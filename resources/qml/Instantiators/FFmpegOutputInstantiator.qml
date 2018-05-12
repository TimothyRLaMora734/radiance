import QtQuick 2.3

QtObject {
    Component.onCompleted: {
        var vn = registry.deserialize(context, {
            type: "FFmpegOutputNode"
        });
        if (vn) {
            graph.insertVideoNode(vn);
        } else {
            console.log("Could not instantiate FFmpegOutputNode");
        }
    }
}
