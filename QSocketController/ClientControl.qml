import QtQuick 2.4
import MyModule 1.0

ClientControlForm{

    function positionChange()
    {
        if (clientMouseArea.pressed)
        {
            model.setMousePosition(clientMouseArea.mouseX, clientMouseArea.mouseY)
        }
    }


    clientMouseArea.onPressed:
    {
        model.changePressd(clientMouseArea.pressed)
        positionChange()
    }

    clientMouseArea.onReleased: model.changePressd(false);

    clientMouseArea.onPositionChanged: positionChange()


}

