#include "mainmodel.h"
#include "servermanager.h"
#include "clientmanager.h"
#include <QJsonObject>
#include <QJsonDocument>

MainModel::MainModel(QObject *parent) : QObject(parent)
{
    m_mouesX = 0;
    m_mouseY = 0;
    m_pressed = false;
}

void MainModel::Init()
{
    Server = new ServerManager(this);
    connect(Server, SIGNAL(changeServerReceivedString(QString)), this, SLOT(OnReceivedServerString(QString)));

    Client = new ClientManager(this);
    Client->ConnectToServer();
}


void MainModel::sendClientToServer(QString message)
{
    Client->SendClientToServer(message);
}

void MainModel::OnReceivedServerString(QString message)
{
    m_ServerReceivedString = message;


    QJsonDocument jsonDoc = QJsonDocument::fromJson(message.toUtf8());
    QJsonObject jsonObj = jsonDoc.object();

    m_RMouseX = jsonObj.value("mouesX").toDouble();
    m_RMouseY = jsonObj.value("mouseY").toDouble();
    m_RPressed = jsonObj.value("pressed").toBool();

    emit changeServerReceived();
}

void MainModel::setMousePosition(double mouesX, double mouseY)
{
    m_mouesX = mouesX;
    m_mouseY = mouseY;


    sendClientToServer();
}

void MainModel::changePressd(bool pressed)
{
    m_pressed = pressed;

    sendClientToServer();
}

void MainModel::sendClientToServer()
{
    QJsonObject mouesJson
    {
        {"mouesX", m_mouesX},
        {"mouseY", m_mouseY},
        {"pressed", m_pressed}
    };

    QJsonDocument doc(mouesJson);
    QString strJson(doc.toJson(QJsonDocument::Compact));

    Client->SendClientToServer(strJson);
}


