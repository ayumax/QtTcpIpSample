#include "mainmodel.h"
#include "servermanager.h"
#include "clientmanager.h"

MainModel::MainModel(QObject *parent) : QObject(parent)
{

}

void MainModel::Init()
{
    Server = new ServerManager(this);

    Client = new ClientManager(this);
    Client->ConnectToServer();
}
