#ifndef MOUSESERVER_H
#define MOUSESERVER_H

#include <QObject>

class TCPServerModel;

class MouseServer : public QObject
{
    Q_OBJECT
public:
    explicit MouseServer(QObject *parent = nullptr);

    void Init();

    Q_PROPERTY(QString serverReceivedString MEMBER m_ServerReceivedString NOTIFY changeServerReceived)
    Q_PROPERTY(qreal MouseX MEMBER m_MouseX NOTIFY changeServerReceived)
    Q_PROPERTY(qreal MouseY MEMBER m_MouseY NOTIFY changeServerReceived)
    Q_PROPERTY(bool Pressed MEMBER m_Pressed NOTIFY changeServerReceived)


signals:
    void changeServerReceived();

public slots:
    void OnReceivedServerString(QString message);

private:
    TCPServerModel* Server;

    QString m_ServerReceivedString;
    qreal m_MouseX;
    qreal m_MouseY;
    bool m_Pressed;

};

#endif // MOUSESERVER_H
