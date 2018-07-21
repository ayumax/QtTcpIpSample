import QtQuick 2.4
import QtQuick.Controls 2.0

Item {
    id: item1
    property alias textArea: textArea
    property alias rect: rect

    width: 320
    height: 480
    //    header: Label {
    //        text: qsTr("Server")
    //        font.pixelSize: Qt.application.font.pixelSize * 2
    //        padding: 10
    //    }
    TextArea {
        id: textArea
        y: 15
        height: 50
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
    }

    Rectangle {
        id: rect
        width: 20
        height: 20
        radius: 5
    }
}
