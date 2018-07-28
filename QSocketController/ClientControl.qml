import QtQuick 2.4
import MyModule 1.0

ClientControlForm{

    function positionChange()
    {
        if (clientMouseArea.pressed)
        {
            client.setMousePosition(clientMouseArea.mouseX, clientMouseArea.mouseY)
        }
    }


    clientMouseArea.onPressed:
    {
        client.changePressed(clientMouseArea.pressed)
        positionChange()
    }

    clientMouseArea.onReleased: client.changePressed(false);

    clientMouseArea.onPositionChanged: positionChange()


}

