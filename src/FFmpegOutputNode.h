#pragma once

#include "OutputNode.h"
#include "OutputWindow.h"
#include <QProcess>

class FFmpegOutputNode
    : public OutputNode {
    Q_OBJECT
    Q_PROPERTY(bool recording READ recording WRITE setRecording NOTIFY recordingChanged);
    Q_PROPERTY(QStringList ffmpegArguments READ ffmpegArguments WRITE setFFmpegArguments NOTIFY ffmpegArgumentsChanged);

public:
    FFmpegOutputNode(Context *context, QSize chainSize);
    ~FFmpegOutputNode();

    // These static methods are required for VideoNode creation
    // through the registry

    // A string representation of this VideoNode type
    static QString typeName();

    // Create a VideoNode from a JSON description of one
    // Returns nullptr if the description is invalid
    static VideoNodeSP *deserialize(Context *context, QJsonObject obj);

    // Return true if a VideoNode could be created from
    // the given filename
    // This check should be very quick.
    static bool canCreateFromFile(QString filename);

    // Create a VideoNode from a filename
    // Returns nullptr if a VideoNode cannot be create from the given filename
    static VideoNodeSP *fromFile(Context *context, QString filename);

    // Returns QML filenames that can be loaded
    // to instantiate custom instances of this VideoNode
    static QMap<QString, QString> customInstantiators();

    void recordFrame();

public slots:
    bool recording();
    void setRecording(bool recording);
    QStringList ffmpegArguments();
    void setFFmpegArguments(QStringList ffmpegArguments);

signals:
    void recordingChanged(bool recording);
    void ffmpegArgumentsChanged(QStringList ffmpegArguments);

protected:
    bool m_recording;
    QStringList m_ffmpegArguments;
    QProcess m_ffmpeg;
    QByteArray m_pixelBuffer;
};

typedef QmlSharedPointer<FFmpegOutputNode, OutputNodeSP> FFmpegOutputNodeSP;
Q_DECLARE_METATYPE(FFmpegOutputNodeSP*)
