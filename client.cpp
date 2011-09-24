#include "client.h"
#include "ui_client.h"
#include <QDebug>
#include <QMessageBox>

Client::Client() : ui(new Ui::Client)
{
    ui->setupUi(this);

    ui->hostLineEdit->setText("10.3.172.89");
    ui->portLineEdit->setValidator(new QIntValidator(1, 65535, this));
    ui->portLineEdit->setText("5555");

    connect(&tcpSocket, SIGNAL(connected()), this, SLOT(connected()));
    connect(&tcpSocket, SIGNAL(readyRead()), this, SLOT(updateInfo()));
    connect(&tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
    this->setFixedSize(size());
    nextBlockSize = 0;
}

Client::~Client()
{
    delete ui;
}

void Client::connected()
{
    qDebug() << "connected";
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);

    out<< quint64(0) << QString("GET");
    out.device()->seek(0);
    out << quint64(block.size() - sizeof(quint64));

    qDebug() << "send to server";
    tcpSocket.write(block);
}

void Client::sendClient(QString type, int i, int j)
{
    qDebug() << "sendFromClientToServer" << type << QString::number(i) << QString::number(j);
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);

    out<< quint64(0) << type << i << j;
    out.device()->seek(0);
    out << quint64(block.size() - sizeof(quint64));

//    qDebug() << "send to server";
    tcpSocket.write(block);
}

void Client::updateInfo()
{
    qDebug() << "updateInfo(readInClient) ";
    const int Timeout = 5 * 1000;

    while (tcpSocket.bytesAvailable() < sizeof(quint64)) {
        if (!tcpSocket.waitForReadyRead(Timeout)) {
            return;
        }
    }

    QDataStream in(&tcpSocket);
    in.setVersion(QDataStream::Qt_4_6);
    in >> nextBlockSize;
//    qDebug() << "nextBlockSize " << nextBlockSize;

    while ((quint64)tcpSocket.bytesAvailable() < nextBlockSize) {
        if (!tcpSocket.waitForReadyRead(Timeout)) {
            return;
        }
    }
    QString type;
    in >> type;
//    qDebug() << type;
    if (type == "GET")
    {
        QList<QList<int> > mat;
        int mines;
        QStringList presses;
        QList<QPair<int, int> > pressBut;
        in >> mat >> mines >> presses >> pressBut;
        qDebug() << mines;
        for (int i = 0 ; i < mat.size() ; i++)
            qDebug() << mat[i];

        emit createNewField(mat,mines,presses,pressBut);
    }
    else if (type == "CLICK" || type == "RIGHT" || type == "DOUBLE")
    {
        int i,j;
        in >> i >> j;
        qDebug() << type << QString::number(i) << QString::number(j);
        emit doClick(type,i,j);
    }
    nextBlockSize = 0;

}

void Client::displayError(QAbstractSocket::SocketError socketError)
{
    qDebug() << "displayError ";
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, "Ошибка подключения",
                                 "Сервер не найден. Проверьте правильность адреса и порта.");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, "Ошибка подключения",
                                 "Соединение было разорвано. Убедитесь, что сервер запущен, и были указаны верные настройки.");
        break;
    default:
        QMessageBox::information(this,  "Ошибка подключения",
                                 QString("Произошла ошибка: %1.")
                                 .arg(tcpSocket.errorString()));
    }
}

void Client::on_pushButton_clicked()
{
    if (ui->portLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Введите порт сервера");
        return;
    }
    tcpSocket.connectToHost(ui->hostLineEdit->text(), ui->portLineEdit->text().toInt());
}
