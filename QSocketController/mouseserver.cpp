#include "mouseserver.h"
#include "tcpservermodel.h"
#include <QJsonObject>
#include <QJsonDocument>

MouseServer::MouseServer(QObject *parent) : QObject(parent)
{
    m_MouseX = 0;
    m_MouseY = 0;
    m_Pressed = false;
}

void MouseServer::Init()
{
    Server = new TCPServerModel(this);
    connect(Server, SIGNAL(changeServerReceivedString(QString)), this, SLOT(OnReceivedServerString(QString)));
}

void MouseServer::OnReceivedServerString(QString message)
{
    m_ServerReceivedString = message;

    QJsonDocument jsonDoc = QJsonDocument::fromJson(message.toUtf8());
    QJsonObject jsonObj = jsonDoc.object();

    m_MouseX = jsonObj.value("mouesX").toDouble();
    m_MouseY = jsonObj.value("mouseY").toDouble();
    m_Pressed = jsonObj.value("pressed").toBool();

    emit changeServerReceived();
}


