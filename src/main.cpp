#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFont>
#include <QTranslator>
#include "appmanager.h"
#include "ft2232hwrapper.h"
#include "ascan.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    // app font
    QFont font("simfang.ttf", 12);
    app.setFont(font);

    // register c++ type to qml
    qmlRegisterType<AppManager>("AppManager", 1, 0, "AppManager");
    qmlRegisterType<Ft2232HWrapper>("Ft2232HWrapper", 1, 0, "Ft2232HWrapper");
    qmlRegisterType<Ascan>("Ascan", 1, 0, "Ascan");

    // app translator
    QTranslator *trans_cn = new QTranslator;
    trans_cn->load(":/res/translations/la_cn.qm");
    qApp->installTranslator(trans_cn);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
