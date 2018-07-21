import QtQuick 2.4

Item {
    id: item1
    visible: true
    width: 640
    height: 480

    Row {
        id: row
        anchors.fill: parent

        ClientControl {
            width: 320
            height: 480
        }

        Rectangle {
            id: rectangle
            width: 5
            color: "#e12c2c"
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
        }

        ServerControl {
            width: 320
            height: 480
        }

    }
}
