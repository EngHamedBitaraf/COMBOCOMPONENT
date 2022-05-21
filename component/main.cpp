#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <button_ui.h>

#include <button_Events.h>
#include <QQmlContext>

#include <TreeViewModel.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    //qml button class
    button button_class;

    button_UI ui_class;


    QQmlApplicationEngine engine;

    //tree view model class
    TreeViewModel mymodel;
    engine.rootContext()->setContextProperty("mymodel", &mymodel);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QQmlContext * rootContext = engine.rootContext();
    rootContext->setContextProperty("button_wid", &button_class);




    return app.exec();
}
