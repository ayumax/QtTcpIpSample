#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "mouseclient.h"
#include "mouseserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<MouseClient>("MyModule", 1,0, "MouseClient");
    qmlRegisterType<MouseServer>("MyModule", 1,0, "MouseServer");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/MainWindow.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    MouseServer server;
    server.Init();
    engine.rootContext()->setContextProperty("server", &server);

    MouseClient client;
    client.Init();
    engine.rootContext()->setContextProperty("client", &client);

    return app.exec();
}
