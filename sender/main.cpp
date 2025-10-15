#include <QCoreApplication>
#include"udphandler.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    udphandler *sender = new udphandler;
    sender->start();

    return a.exec();
}
