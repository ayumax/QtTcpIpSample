#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <QObject>
#include "tcpclientbase.h"


class ClientManager : public TCPClientBase
{
    Q_OBJECT
public:
    explicit ClientManager(QObject *parent = nullptr);


    void ConnectToServer();

signals:

public slots:


};

#endif // CLIENTMANAGER_H
