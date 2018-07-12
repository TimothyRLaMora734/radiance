import QtQuick 2.7
import QtQuick.Layouts 1.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0

Slider {
    minimumValue: 0;
    maximumValue: 1;

    style: SliderStyle {
        handle: Rectangle {
            height: 20
            width: 20
            radius: width/2
            gradient: Gradient {
                GradientStop { position: 0; color: "#777" }
                GradientStop { position: 0.5; color: "#444" }
            }
        }

        groove: Rectangle {
            implicitHeight: 10
            radius: height/2
            border.width: 1
            border.color: "#111"
            gradient: Gradient {
                GradientStop { position: 0.5; color: "#000" }
                GradientStop { position: 1; color: "#333" }
            }
            Rectangle {
                x: 2.5
                y: 2.5
                height: parent.height - 5
                width: styleData.handlePosition
                radius: height/2
                gradient: Gradient {
                    GradientStop { position: 0; color: "#66f" }
                    GradientStop { position: 0.5; color: "#00f" }
                }
            }
        }
    }
}
