#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <QTcpServer>
#include <QObject>
class ConnectedClient;

class ServerManager: public QObject
{
    Q_OBJECT
public:
    explicit ServerManager(QObject *parent = nullptr);

protected slots:
    void OnConnect();

    void OnDisconnectClient(ConnectedClient* client);

private:
    QTcpServer* server;
    QList<ConnectedClient*> Clients;
};

#endif // SERVERMANAGER_H
