#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "mainmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<MainModel>("MyModule", 1,0, "MainModel");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/MainWindow.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    MainModel data;
    data.Init();
    engine.rootContext()->setContextProperty("model", &data);

    return app.exec();
}
