#include "server.h"
#include <QDebug>
#include <QNetworkInterface>
Server::Server(QObject *parent)
{
    if(!listen())
        qWarning()<< "Nezdarilo se pripojit k serveru";
    else
    {
        connect(this, &Server::newConnection, this, &Server::newClient);
        QList<QHostAddress> adresses=QNetworkInterface::allAddresses();
        for(int i=0; i<adresses.length();++i)
        {
            if(adresses.at(i).protocol()==QAbstractSocket::IPv4Protocol)
            {
            qDebug() << adresses.at(i).toString() << ";" << serverPort();
            }
        }
    }
}

void Server::newClient()
{
    QTcpSocket *novyklient = nextPendingConnection();
    connect(novyklient, &QTcpSocket::disconnected, this, &Server::delClient);
    connect(novyklient, SIGNAL(readyRead()), this, SLOT(readData()));
    clients.append(novyklient);
}

void Server::delClient()
{
    QTcpSocket *sender=static_cast<QTcpSocket *>(QObject::sender());
    clients.removeOne(sender);
    qDebug() << "klient odpojen";
}
