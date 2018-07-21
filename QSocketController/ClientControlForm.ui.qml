import QtQuick 2.4
import MyModule 1.0

Item {

    property alias clientMouseArea: clientMouseArea

    width: 320
    height: 480

    //    header: Label {
    //        text: qsTr("Client")
    //        font.pixelSize: Qt.application.font.pixelSize * 2
    //        padding: 10
    //    }
    Rectangle {
        id: rectangle
        color: "#98e167"
        anchors.fill: parent
    }

    MouseArea {
        id: clientMouseArea
        anchors.fill: parent
        hoverEnabled: true
    }
}
