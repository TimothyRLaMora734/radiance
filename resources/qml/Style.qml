pragma Singleton
import QtQuick 2.7

QtObject {
    // These colors are for the main UI background
    readonly property color mainBackgroundColor: "#333"
    readonly property color mainTextColor: "#aaa"
    readonly property color mainTextHighlightColor: "#eee"

    // These colors are for the tiles
    readonly property color tileBackgroundColor: "#111"
    readonly property color tileBackgroundHighlightColor: "#113"
    readonly property color tileTextColor: "#ddd"
    readonly property color tileLineColor: "#666"
    readonly property color tileLineHighlightColor: "#aa3"

    // Colors for UI elements
    readonly property color sliderKnobColor: "#333"
    readonly property color sliderTrackColor: "#111"
    readonly property color sliderFillColor: "#00f"
}  
