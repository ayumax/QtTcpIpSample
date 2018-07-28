#include "tcpclientmodel.h"
#include <QTcpSocket>
#include <QDataStream>

TCPClientModel::TCPClientModel(QObject *parent) : QObject(parent)
{
    bodySize = 0;
}

void TCPClientModel::setClient()
{
    setClient(new QTcpSocket(this));
}

void TCPClientModel::setClient(QTcpSocket* socket)
{
    tcpClient = socket;

    connect(tcpClient, SIGNAL(connected()), this, SLOT(OnConnected()));
    connect(tcpClient, SIGNAL(disconnected()), this, SLOT(OnDisconnected()));
    connect(tcpClient, SIGNAL(readyRead()), this, SLOT(OnReceived()));
    connect(tcpClient, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(OnError()));
}


void TCPClientModel::ConnectToServer(QHostAddress address, quint16 port)
{
    tcpClient->connectToHost(address, port);
}


void TCPClientModel::SendClientToServer(QString message)
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


void TCPClientModel::OnConnected()
{
    qDebug("onConnect client");
}

void TCPClientModel::OnDisconnected()
{
    emit disConnected(this);
}

void TCPClientModel::OnReceived()
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

void TCPClientModel::OnError()
{

}
