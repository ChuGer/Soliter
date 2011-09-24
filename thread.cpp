#include "thread.h"

Thread::Thread(int socketDescriptor,MainWidget *field): socketDescriptor(socketDescriptor),field(field)
{
}

void Thread::run()
{
    qDebug() << "run";
    tcpSocket = new TcpSocket(field);

    if (!tcpSocket->setSocketDescriptor(socketDescriptor))
    {
        qDebug("tcpSocket->error()");
        return;
    }
    connect(tcpSocket, SIGNAL(readyRead()), tcpSocket, SLOT(readClient()));
    connect(tcpSocket, SIGNAL(disconnected()), tcpSocket, SLOT(deleteLater()));
    connect(tcpSocket, SIGNAL(updateSocks(QString,int,int)), this, SLOT(updateSocks(QString,int,int)));
    connect(this, SIGNAL(updateOne(QString,int,int)), tcpSocket, SLOT(updateOne(QString,int,int)));

    exec();
    delete tcpSocket;
}

void Thread::updateSocks(QString type , int i,int j)
{
    emit updateThreads(type,i,j);
}

void Thread::up(QString type , int i,int j)
{
    emit updateOne(type,i,j);
}
