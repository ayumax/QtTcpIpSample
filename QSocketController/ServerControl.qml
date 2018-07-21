import QtQuick 2.4
import MyModule 1.0

ServerControlForm {

    rect.x: model.RMouseX
    rect.y: model.RMouseY
    textArea.text: model.serverReceivedString
    rect.color: model.RPressed ? "blue" : "red"
}
