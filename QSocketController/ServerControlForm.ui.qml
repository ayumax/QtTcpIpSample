import QtQuick 2.4
import QtQuick.Controls 2.0

Item {
    id: item1
    property alias rect: rect

    width: 320
    height: 480

    Rectangle {
        id: rect
        width: 20
        height: 20
        radius: 5
    }

    Column {
        id: column
        width: 200
        height: 49
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0

        Row {
            id: row
            width: 200
            height: 15

            Text {
                id: text1
                width: 100
                text: qsTr("Position X:")
                font.pixelSize: 12
            }

            Text {
                id: text2
                width: 50
                text: server.MouseX
                horizontalAlignment: Text.AlignRight
                font.pixelSize: 12
            }
        }

        Row {
            id: row1
            width: 200
            height: 15
            Text {
                id: text3
                width: 100
                text: qsTr("Position Y:")
                font.pixelSize: 12
            }

            Text {
                id: text4
                width: 50
                text: server.MouseY
                horizontalAlignment: Text.AlignRight
                font.pixelSize: 12
            }
        }

        Row {
            id: row2
            width: 200
            height: 15
            Text {
                id: text5
                width: 100
                text: qsTr("Pressed :")
                font.pixelSize: 12
            }

            Text {
                id: text6
                width: 50
                text: server.Pressed
                horizontalAlignment: Text.AlignRight
                font.pixelSize: 12
            }
        }
    }

    Text {
        id: text7
        color: "#262626"
        text: qsTr("Server")
        font.pixelSize: 24
    }
}
