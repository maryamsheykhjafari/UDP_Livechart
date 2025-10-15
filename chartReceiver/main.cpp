#include <QApplication>
#include <QQuickView>
#include <QQmlContext>
#include <QQuickWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QDebug>
#include<QQmlEngine>
#include"udphandler.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);


    QQuickWindow::setGraphicsApi(QSGRendererInterface::Software);

    QQuickView viewer;
    udphandler *udpreceiver = new udphandler;

    viewer.setTitle(QStringLiteral("QtCharts task"));

    viewer.rootContext()->setContextProperty("udpreceiver", udpreceiver);


    viewer.setSource(QUrl("qrc:/chart/Main.qml"));
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    viewer.setColor(QColor("#ffffff"));



    viewer.show();


    return app.exec();
}
