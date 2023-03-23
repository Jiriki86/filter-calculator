#include <QApplication>
#include <QQmlApplicationEngine>

#include "FilterCalculator.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  QQmlApplicationEngine engine;

  qmlRegisterType<FilterCalculator>("MyWidgets", 1, 0, "FilterCalculator");

  const QUrl url("qrc:/view/main.qml");
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
