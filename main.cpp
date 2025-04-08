#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

#include "tstmodel.h"
#include "choiceitem.h"

void registerTypes()
{
    qmlRegisterType<TstModel>("com.tst.model", 1, 0, "TstModel");
    qmlRegisterType<ChoiceItem>("com.tst.model", 1, 0, "ChoiceItem");
}

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    registerTypes();

    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
