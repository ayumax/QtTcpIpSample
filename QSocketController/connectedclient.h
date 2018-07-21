#ifndef CONNECTEDCLIENT_H
#define CONNECTEDCLIENT_H

#include <QObject>
#include "tcpclientbase.h"

class ConnectedClient : public TCPClientBase
{
    Q_OBJECT
public:
    explicit ConnectedClient(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CONNECTEDCLIENT_H
