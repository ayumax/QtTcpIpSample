import QtQuick 2.4
import MyModule 1.0

Item {

    property alias clientMouseArea: clientMouseArea

    width: 320
    height: 480

    MouseArea {
        id: clientMouseArea
        anchors.fill: parent
        hoverEnabled: true
    }

    Text {
        id: text1
        color: "#262626"
        text: qsTr("Client")
        font.pixelSize: 24
    }
}
