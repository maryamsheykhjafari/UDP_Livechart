#include "udphandler.h"
#include<QDebug>
udphandler::udphandler(QObject *parent)
    :QObject(parent)
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost , port);

    connect(socket ,&QUdpSocket::readyRead , this , &udphandler::readPendingDatagram);



}




void udphandler::readPendingDatagram()
{
    while (socket->hasPendingDatagrams())
    {
        QByteArray datagram;

        datagram.resize(socket->pendingDatagramSize());
        socket->readDatagram(datagram.data() , datagram.size());

        double value=QString::fromUtf8(datagram).toDouble();
        emit dataReceived(value);



    }
}
