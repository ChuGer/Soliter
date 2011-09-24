#ifndef TCPSOCKET_H
#define TCPSOCKET_H
#include <QMutex>
#include <QTcpSocket>
#include "mainwidget.h"

class TcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    TcpSocket(MainWidget *field);

private slots:
    void readClient();
    void updateOne(QString, int,int);

signals:
    void updateSocks(QString,int,int);

private:
    void sendInfo();
    quint64 nextBlockSize;
    QMutex mutex;
    MainWidget *field;
    QString emitter;
};

#endif // TCPSOCKET_H
