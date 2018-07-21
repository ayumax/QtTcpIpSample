#include "servermanager.h"
#include <QTcpSocket>
#include "connectedclient.h"

ServerManager::ServerManager(QObject *parent)
    : QObject(parent)
{
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any, 9013);

    connect(server, SIGNAL(newConnection()), this, SLOT(OnConnect()));
}

void ServerManager::OnConnect()
{
    auto newClient = new ConnectedClient(this);
    newClient->setClient(server->nextPendingConnection());

    Clients.push_back(newClient);

    connect(newClient, SIGNAL(disConnected(TCPClientBase*)), this, SLOT(OnDisconnectClient(TCPClientBase*)));
    connect(newClient, SIGNAL(dataReceived(QString)), this, SLOT(OnReceived(QString)));
}

void ServerManager::OnDisconnectClient(TCPClientBase* client)
{
    disconnect(client, SIGNAL(disconnected(TCPClientBase*)), this, SLOT(OnDisconnectClient(TCPClientBase*)));
    disconnect(client, SIGNAL(dataReceived(QString)), this, SLOT(OnReceived(QString)));

    auto _client = (ConnectedClient*)client;
    Clients.removeAll(_client);
}

void ServerManager::OnReceived(QString message)
{
    emit changeServerReceivedString(message);
}
