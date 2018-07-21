#include "tcpclientbase.h"
#include <QTcpSocket>
#include <QHostAddress>
#include <QDataStream>

TCPClientBase::TCPClientBase(QObject *parent) : QObject(parent)
{
    bodySize = 0;
}

void TCPClientBase::setClient(QTcpSocket* socket)
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
    while (tcpClient->bytesAvailable() > 0)
    {
        tempBuffer.append(tcpClient->readAll());

        while ((bodySize == 0 && tempBuffer.size() >= 4)
               || (bodySize > 0 && tempBuffer.size() >= bodySize))
        {
            if (bodySize == 0 && tempBuffer.size() >= 4)
            {
                QByteArray numArray = tempBuffer.mid(0, 4);
                QDataStream stream(&numArray, QIODevice::ReadOnly);
                stream >> bodySize;
                tempBuffer.remove(0, 4);
            }

            if (bodySize > 0 && tempBuffer.size() >= bodySize)
            {
                QByteArray bodyArray = tempBuffer.mid(0, bodySize);
                tempBuffer.remove(0, bodySize);
                bodySize = 0;

               emit dataReceived(QString::fromUtf8(bodyArray));
            }
        }
    }
}

void TCPClientBase::OnError()
{

}
