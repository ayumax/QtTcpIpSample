#ifndef MAINMODEL_H
#define MAINMODEL_H

#include <QObject>

class ServerManager;
class ClientManager;

class MainModel : public QObject
{
    Q_OBJECT
public:
    explicit MainModel(QObject *parent = nullptr);

    void Init();

signals:

public slots:

private:
    ServerManager* Server;
    ClientManager* Client;
};

#endif // MAINMODEL_H
