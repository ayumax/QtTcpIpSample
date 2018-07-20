#include "clientmanager.h"
#include <QTcpSocket>
#include <QHostAddress>

ClientManager::ClientManager(QObject *parent)
    : TCPClientBase(new QTcpSocket(this), parent)
{

}

void ClientManager::ConnectToServer()
{
    tcpClient->connectToHost(QHostAddress::LocalHost, 9013);
}
