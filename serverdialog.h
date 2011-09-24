#ifndef SERVERDIALOG_H
#define SERVERDIALOG_H
#include <QDialog>
#include <QTcpServer>
#include "thread.h"
#include "mainwidget.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server(MainWidget *field);

private slots:
    void updateThreads(QString,int,int);
signals:
    void up(QString,int,int);

protected:
    void incomingConnection(int socketDescriptor);
    MainWidget *field;
};

namespace Ui {
    class ServerDialog;
}

class ServerDialog : public QDialog 
{
    Q_OBJECT
public:
    ServerDialog(MainWidget *field);
    ~ServerDialog();

private:
    Server* server;
    Ui::ServerDialog *ui;
    MainWidget *field;
};



#endif // SERVERDIALOG_H
