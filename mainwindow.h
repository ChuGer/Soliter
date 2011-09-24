#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QProgressBar>
#include <QMenuBar>
#include <QStatusBar>
#include <QLCDNumber>
#include "mainwidget.h"
#include "createnewfield.h"
#include "serverdialog.h"
#include "client.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();

private:
    void CreateMenus();
    void center(QDialog* dlg);
    int row,col,time;
    bool timerStop;
    void updateField();

private slots:
    void createNewField(int,int,int);
    void createNewField(QList<QList<int> > mat, int,QStringList,QList<QPair<int, int> > );
    void createNewField();
    void createGame();
    void GameOver();
    void Win();
    void updateMines(int);
    void center();
    void res();
    void newGame();
    void startServer();
    void connectServer();
    void sendClient(QString, int, int);
    void doClick(QString, int,int);


private:
    QProgressBar *pb;
    MainWidget *field;
    CreateNewField *dialogNewField;
    QLCDNumber *lcd;
    QPushButton *mines;
    QTimer *timer;

    ServerDialog* server;
    Client* client;
    bool isServer;
    bool isClient;
};

#endif // MAINWINDOW_H
