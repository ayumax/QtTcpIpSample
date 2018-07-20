#ifndef TCPCLIENTBASE_H
#define TCPCLIENTBASE_H

#include <QObject>
class QTcpSocket;

class TCPClientBase : public QObject
{
    Q_OBJECT
public:
    explicit TCPClientBase(QTcpSocket* socket, QObject *parent = nullptr);

signals:
    void disConnected(TCPClientBase* client);

public slots:
    virtual void OnConnected();
    virtual void OnDisconnected();
    virtual void OnReceived();
    virtual void OnError();

protected:
    QTcpSocket* tcpClient;
};

#endif // TCPCLIENTBASE_H
