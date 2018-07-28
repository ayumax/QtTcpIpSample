#include "tcpservermodel.h"
#include <QTcpSocket>
#include "tcpclientmodel.h"

TCPServerModel::TCPServerModel(QObject *parent)
    : QObject(parent)
{
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any, 9013);

    connect(server, SIGNAL(newConnection()), this, SLOT(OnConnect()));
}

void TCPServerModel::OnConnect()
{
    auto newClient = new TCPClientModel(this);
    newClient->setClient(server->nextPendingConnection());

    Clients.push_back(newClient);

    connect(newClient, SIGNAL(disConnected(TCPClientModel*)), this, SLOT(OnDisconnectClient(TCPClientModel*)));
    connect(newClient, SIGNAL(dataReceived(QString)), this, SLOT(OnReceived(QString)));
}

void TCPServerModel::OnDisconnectClient(TCPClientModel* client)
{
    disconnect(client, SIGNAL(disconnected(TCPClientModel*)), this, SLOT(OnDisconnectClient(TCPClientModel*)));
    disconnect(client, SIGNAL(dataReceived(QString)), this, SLOT(OnReceived(QString)));

    auto _client = (TCPClientModel*)client;
    Clients.removeAll(_client);
}

void TCPServerModel::OnReceived(QString message)
{
    emit changeServerReceivedString(message);
}
