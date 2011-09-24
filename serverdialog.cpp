#include "serverdialog.h"
#include "ui_serverdialog.h"
#include <QMessageBox>
#include <QtNetwork>

ServerDialog::ServerDialog(MainWidget *field) : ui(new Ui::ServerDialog), field(field)
{
    ui->setupUi(this);

    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    server = new Server(field);
    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address())
        {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }

    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

    if (!server->listen(QHostAddress(ipAddress), 5555))
    {
        QMessageBox::critical(this, this->windowTitle(),
                              QString("Невозможно запустить сервер: %1.").arg(server->errorString()));
        close();
        return;
    }

    ui->adress->setText(ipAddress);
    ui->port->setText(QString::number(server->serverPort()));
    this->setFixedSize(size());

}

ServerDialog::~ServerDialog()
{
    delete ui;
}

Server::Server(MainWidget *field) : field(field)
{
}

void Server::incomingConnection(int socketDescriptor)
{
    Thread *thread = new Thread(socketDescriptor,field);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(thread, SIGNAL(updateThreads(QString, int,int)), this, SLOT(updateThreads(QString, int,int)));
    connect(this, SIGNAL(up(QString, int,int)),thread,SLOT(up(QString, int,int)));
    thread->start();
}

void Server::updateThreads(QString type , int i,int j)
{
    qDebug() << "emit up(car)";
    emit up(type,i,j);
}

