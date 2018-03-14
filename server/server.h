#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(QObject *parent = nullptr);

signals:

private slots:
    void newClient();
    void delClient();
protected:
    QList<QTcpSocket *> clients;
};

#endif // SERVER_H
