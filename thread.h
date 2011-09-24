#ifndef THREAD_H
#define THREAD_H
#include <QTcpSocket>
#include <QThread>
#include "tcpsocket.h"
#include "mainwidget.h"

class Thread : public QThread
{
    Q_OBJECT
public:
    Thread(int socketDescriptor,MainWidget *field);
    void run();
    TcpSocket *tcpSocket;

signals:
    void error(QTcpSocket::SocketError socketError);
    void updateThreads(QString, int,int);
    void updateOne(QString, int,int);

private slots:
    void updateSocks(QString, int,int);
    void up(QString, int,int);

private:
    int socketDescriptor;
    MainWidget *field;
};

#endif // THREAD_H
