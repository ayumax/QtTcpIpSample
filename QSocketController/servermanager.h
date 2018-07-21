#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <QTcpServer>
#include <QObject>

class ConnectedClient;
class TCPClientBase;

class ServerManager: public QObject
{
    Q_OBJECT
public:
    explicit ServerManager(QObject *parent = nullptr);


signals:
    void changeServerReceivedString(QString message);

protected slots:
    void OnConnect();

    void OnDisconnectClient(TCPClientBase* client);
    void OnReceived(QString message);

private:
    QTcpServer* server;
    QList<ConnectedClient*> Clients;
};

#endif // SERVERMANAGER_H
