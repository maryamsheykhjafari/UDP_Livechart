#ifndef UPDHANDLER_H
#define UPDHANDLER_H

#include<QObject>
#include<QUdpSocket>
#include<QtGlobal>

class udphandler :public QObject
{

    Q_OBJECT

public:

    udphandler( QObject *parent = nullptr);

    Q_INVOKABLE void sendData(const QString &message);
    Q_INVOKABLE void start();




private:
    QUdpSocket *socket;
    quint16 port= 1154;

};

#endif // UPDHANDLER_H
