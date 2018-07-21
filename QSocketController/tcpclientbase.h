#ifndef TCPCLIENTBASE_H
#define TCPCLIENTBASE_H

#include <QObject>
class QTcpSocket;

class TCPClientBase : public QObject
{
    Q_OBJECT
public:
    explicit TCPClientBase(QObject *parent = nullptr);

    void setClient(QTcpSocket* socket);

signals:
    void disConnected(TCPClientBase* client);
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

#endif // TCPCLIENTBASE_H
