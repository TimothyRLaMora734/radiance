#pragma once
#include "Context.h"
#include <QQuickFramebufferObject>
#include <QMutex>

class GraphicalDisplay : public QQuickFramebufferObject
{
    Q_OBJECT
    Q_PROPERTY(Context *context READ context WRITE setContext NOTIFY contextChanged)
    Q_PROPERTY(QString fragmentShader READ fragmentShader WRITE setFragmentShader NOTIFY fragmentShaderChanged)

public:
    QString fragmentShader();
    void setFragmentShader(QString fragmentShader);
    Context *context();
    void setContext(Context *context);
    QMap<const char *, QColor> colors() const;

signals:
    void fragmentShaderChanged(QString value);
    void contextChanged(Context *context);

protected:
    QQuickFramebufferObject::Renderer *createRenderer() const override;
    QString m_fragmentShader;
    QMutex m_fragmentShaderLock;
    Context *m_context;
};
