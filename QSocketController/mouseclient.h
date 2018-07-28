#ifndef MOUSECLIENT_H
#define MOUSECLIENT_H

#include <QObject>

class TCPClientModel;

class MouseClient : public QObject
{
    Q_OBJECT
public:
    explicit MouseClient(QObject *parent = nullptr);

    void Init();

    Q_INVOKABLE void sendClientToServer(QString message);

    Q_INVOKABLE void setMousePosition(double mouesX, double mouseY);
    Q_INVOKABLE void changePressed(bool pressed);

private:
    void sendClientToServer();


private:
    TCPClientModel* Client;

    double m_mouesX;
    double m_mouseY;
    bool m_pressed;
};

#endif // MOUSECLIENT_H
