#ifndef TCPClientModel_H
#define TCPClientModel_H

#include <QObject>
#include <QHostAddress>

class QTcpSocket;

class TCPClientModel : public QObject
{
    Q_OBJECT
public:
    explicit TCPClientModel(QObject *parent = nullptr);

    void setClient();
    void setClient(QTcpSocket* socket);
    void ConnectToServer(QHostAddress address, quint16 port);
    void SendClientToServer(QString message);

signals:
    void disConnected(TCPClientModel* client);
    void dataReceived(QString message);

public slots:
    virtual void OnConnected();
    virtual void OnDisconnected();
    virtual void OnReceived();
    virtual void OnError();

protected:
    QTcpSocket* tcpClient;

    QByteArray tempBuffer;
    qint32 bodySize;
};

#endif // TCPClientModel_H
