#include "udphandler.h"
#include<QRandomGenerator>
#include<QTimer>
udphandler::udphandler(QObject *parent)
    :QObject(parent)
{
    socket = new QUdpSocket(this);
    socket->connectToHost(QHostAddress::LocalHost , port);



}

void udphandler::sendData(const QString &message)
{
    QByteArray data = message.toUtf8();
    socket->writeDatagram(data,QHostAddress::LocalHost , port );

}

void udphandler::start()
{
    QTimer *timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, [this]() {
        int random = QRandomGenerator::global()->bounded(500);
        sendData(QString::number(random));
    });

    timer->start(100);

}

