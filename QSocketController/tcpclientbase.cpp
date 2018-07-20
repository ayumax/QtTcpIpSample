#include "tcpclientbase.h"
#include <QTcpSocket>
#include <QHostAddress>

TCPClientBase::TCPClientBase(QTcpSocket* socket, QObject *parent) : QObject(parent)
{
    tcpClient = socket;

    connect(tcpClient, SIGNAL(connected()), this, SLOT(OnConnected()));
    connect(tcpClient, SIGNAL(disconnected()), this, SLOT(OnDisconnected()));
    connect(tcpClient, SIGNAL(readyRead()), this, SLOT(OnReceived()));
    connect(tcpClient, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(OnError()));

}

void TCPClientBase::OnConnected()
{
    qDebug("onConnect client");
}

void TCPClientBase::OnDisconnected()
{
    emit disConnected(this);
}

void TCPClientBase::OnReceived()
{

}

void TCPClientBase::OnError()
{

}
