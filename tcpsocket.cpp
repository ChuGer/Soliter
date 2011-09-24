#include "tcpsocket.h"
#include <QHostAddress>


TcpSocket::TcpSocket(MainWidget *field) : field(field)
{
    nextBlockSize = 0;
}

void TcpSocket::readClient()
{
    qDebug() << "readClientInServer";
    QDataStream in(this);
    in.setVersion(QDataStream::Qt_4_6);
    if (nextBlockSize == 0)
    {
        if (bytesAvailable() < sizeof(quint64))
            return;
        in >> nextBlockSize;
    }
    if ((quint64)bytesAvailable() < nextBlockSize)
        return;
    QString requestType;
    in >> requestType;

    if(requestType == "GET")
        sendInfo();
    else if (requestType == "CLICK" || requestType == "RIGHT" || requestType == "DOUBLE")
    {
        int i,j;
        in >> i >> j;

        qDebug() << requestType << QString::number(i) << QString::number(j);
        emit updateSocks(requestType,i,j);

        emitter = peerAddress().toString();
    }
    nextBlockSize = 0;
}

void TcpSocket::sendInfo()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    out << quint64(0);
    out << QString("GET");
    out << field->mat << field->mines << field->presses << field->pressBut;

    out.device()->seek(0);
    out << quint64(block.size() - sizeof(quint64));
    write(block);
}

void TcpSocket::updateOne(QString type, int i,int j)
{
    qDebug() << "updateOne" << type << i << j;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    out << quint64(0);
    out << QString(type);
    out << i << j;

    out.device()->seek(0);
    out << quint64(block.size() - sizeof(quint64));
    write(block);
}
