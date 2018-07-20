#include "connectedclient.h"

ConnectedClient::ConnectedClient(QTcpSocket* socket, QObject *parent)
    : TCPClientBase(socket, parent)
{

}
