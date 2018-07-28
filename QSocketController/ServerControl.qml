import QtQuick 2.4
import MyModule 1.0

ServerControlForm {

    rect.x: server.MouseX
    rect.y: server.MouseY
    rect.color: server.Pressed ? "blue" : "red"
}
