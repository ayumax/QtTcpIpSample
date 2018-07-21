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

    Q_PROPERTY(QString serverReceivedString MEMBER m_ServerReceivedString NOTIFY changeServerReceived)
    Q_PROPERTY(qreal RMouseX MEMBER m_RMouseX NOTIFY changeServerReceived)
    Q_PROPERTY(qreal RMouseY MEMBER m_RMouseY NOTIFY changeServerReceived)
    Q_PROPERTY(bool RPressed MEMBER m_RPressed NOTIFY changeServerReceived)

    Q_INVOKABLE void sendClientToServer(QString message);

    Q_INVOKABLE void setMousePosition(double mouesX, double mouseY);
    Q_INVOKABLE void changePressd(bool pressed);

private:
    void sendClientToServer();

signals:
    void changeServerReceived();

public slots:
    void OnReceivedServerString(QString message);

private:
    ServerManager* Server;
    ClientManager* Client;

    QString m_ServerReceivedString;
    qreal m_RMouseX;
    qreal m_RMouseY;
    bool m_RPressed;

    double m_mouesX;
    double m_mouseY;
    bool m_pressed;
};

#endif // MAINMODEL_H
