#include "mouseclient.h"
#include "tcpclientmodel.h"
#include <QJsonObject>
#include <QJsonDocument>

MouseClient::MouseClient(QObject *parent) : QObject(parent)
{
    m_mouesX = 0;
    m_mouseY = 0;
    m_pressed = false;
}

void MouseClient::Init()
{
    Client = new TCPClientModel(this);
    Client->setClient();
    Client->ConnectToServer(QHostAddress::LocalHost, 9013);
}


void MouseClient::sendClientToServer(QString message)
{
    Client->SendMessage(message);
}


void MouseClient::setMousePosition(double mouesX, double mouseY)
{
    m_mouesX = mouesX;
    m_mouseY = mouseY;

    sendClientToServer();
}

void MouseClient::changePressed(bool pressed)
{
    m_pressed = pressed;

    sendClientToServer();
}

void MouseClient::sendClientToServer()
{
    QJsonObject mouesJson
    {
        {"mouesX", m_mouesX},
        {"mouseY", m_mouseY},
        {"pressed", m_pressed}
    };

    QJsonDocument doc(mouesJson);
    QString strJson(doc.toJson(QJsonDocument::Compact));

    Client->SendMessage(strJson);
}


