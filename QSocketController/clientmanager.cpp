#include "clientmanager.h"
#include <QTcpSocket>
#include <QHostAddress>
#include <QDataStream>

ClientManager::ClientManager(QObject *parent)
    : TCPClientBase(parent)
{
    setClient(new QTcpSocket(this));
}

void ClientManager::ConnectToServer()
{
    tcpClient->connectToHost(QHostAddress::LocalHost, 9013);
}


void ClientManager::SendClientToServer(QString message)
{

    QByteArray messageBytes = message.toUtf8();

    int messageSize = messageBytes.length();
    QByteArray sizeBytes;
    QDataStream stream(&sizeBytes, QIODevice::WriteOnly);
    stream << messageSize;

    tcpClient->write(sizeBytes, sizeBytes.length());
    tcpClient->write(messageBytes, messageBytes.length());
    tcpClient->flush();
}
