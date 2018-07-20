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
    auto newClient = new ConnectedClient(server->nextPendingConnection(), this);
    Clients.push_back(newClient);

    connect(newClient, SIGNAL(disconnected(ConnectedClient*)), this, SLOT(OnDisconnectClient(ConnectedClient*)));
}

void ServerManager::OnDisconnectClient(ConnectedClient* client)
{
    disconnect(client, SIGNAL(disconnected(ConnectedClient*)), this, SLOT(OnDisconnectClient(ConnectedClient*)));
    Clients.removeAll(client);
}

