#include "Chain.h"
#include <memory>
#include <array>
#include <algorithm>
#include "xoroshiro128plus.hpp"
#include <QDebug>
#include <QThread>
#include "OpenGLWorkerContext.h"

using namespace Xoroshiro;

Chain::Chain(QSize size)
    : m_noiseTexture(QOpenGLTexture::Target2D)
    , m_blankTexture(QOpenGLTexture::Target2D)
    , m_vao(new QOpenGLVertexArrayObject())
    , m_size(size)
{
}

Chain::Chain(const Chain *other, QSize size)
    : Chain(size)
{
    moveToThread(other->thread());
}

Chain::operator QString() const {
    return QString("Chain(%1x%2, %3)").arg(m_size.width()).arg(m_size.height()).arg(thread()->objectName());
}

void Chain::moveToWorkerContext(OpenGLWorkerContext *context) {
    moveToThread(context->context()->thread());
}

QSize Chain::size() const {
    return m_size;
}

GLuint Chain::noiseTexture() {
    if (!m_noiseTexture.isCreated()) {
        m_noiseTexture.setSize(m_size.width(), m_size.height());
        m_noiseTexture.setFormat(QOpenGLTexture::RGBA32F);
        m_noiseTexture.allocateStorage(QOpenGLTexture::RGBA, QOpenGLTexture::Float32);
        m_noiseTexture.setMinMagFilters(QOpenGLTexture::Linear, QOpenGLTexture::Linear);
        m_noiseTexture.setWrapMode(QOpenGLTexture::Repeat);

        auto compCount = m_size.width() * m_size.height() * 4;
        auto data = std::make_unique<float[]>(compCount);

        auto xsr = xoroshiro128plus_engine(reinterpret_cast<uint64_t>(this));

        auto xsrd = [&xsr, div = (1./(UINT64_C(1)<<53))](){
            return (xsr() >> 11) * div;
        };
        std::generate(&data[0],&data[compCount],xsrd);
        m_noiseTexture.setData(QOpenGLTexture::RGBA, QOpenGLTexture::Float32, (const void*)&data[0]);
        glFlush();
    }

    return m_noiseTexture.textureId();
}

GLuint Chain::blankTexture() {
    if (!m_blankTexture.isCreated()) {
        m_blankTexture.setSize(1, 1);
        m_blankTexture.setFormat(QOpenGLTexture::RGBA8_UNorm);
        m_blankTexture.allocateStorage(QOpenGLTexture::RGBA, QOpenGLTexture::UInt8);
        m_blankTexture.setMinMagFilters(QOpenGLTexture::Nearest, QOpenGLTexture::Nearest);
        m_blankTexture.setWrapMode(QOpenGLTexture::Repeat);

        auto data = std::array<uint8_t,4>();
        m_blankTexture.setData(QOpenGLTexture::RGBA, QOpenGLTexture::UInt8, (const void*)&data[0]);
    }

    return m_blankTexture.textureId();
}

QOpenGLVertexArrayObject *Chain::vao() {
    if (!m_vao.isCreated()) {
        m_vao.create();
    }
    return &m_vao;
}
