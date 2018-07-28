#ifndef TCPServerModel_H
#define TCPServerModel_H

#include <QTcpServer>
#include <QObject>

class ConnectedClient;
class TCPClientModel;

class TCPServerModel: public QObject
{
    Q_OBJECT
public:
    explicit TCPServerModel(QObject *parent = nullptr);


signals:
    void changeServerReceivedString(QString message);

protected slots:
    void OnConnect();

    void OnDisconnectClient(TCPClientModel* client);
    void OnReceived(QString message);

private:
    QTcpServer* server;
    QList<TCPClientModel*> Clients;
};

#endif // TCPServerModel_H
