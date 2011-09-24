#include "mainwindow.h"
#include <QDesktopWidget>
#include <QDebug>
#include <QTimer>
#include <QSound>


MainWindow::MainWindow()
{
    CreateMenus();
    pb = new QProgressBar;
    pb->setMaximum(100);
    mines = new QPushButton;
    mines->setIcon(QIcon(":/bomb.png"));
    lcd = new QLCDNumber(3);
    field = NULL;
    statusBar()->addWidget(pb);
    statusBar()->addWidget(mines);
    statusBar()->addWidget(lcd);

    connect(pb,SIGNAL(valueChanged(int)),statusBar(),SLOT(update()));
    dialogNewField = new CreateNewField;
    connect(dialogNewField,SIGNAL(acepted(int,int,int)),this,SLOT(createNewField(int,int,int)));
    connect(dialogNewField,SIGNAL(exits()),this,SLOT(close()));
    setWindowTitle("Сапер 2010");

    createNewField(9,9,10);
    timer = new QTimer;

    isClient = isServer = false;
}

void MainWindow::CreateMenus()
{
    QAction *newGameAction=new QAction("Новая игра",this);
    connect(newGameAction,SIGNAL(triggered()),this,SLOT(createGame()));
    newGameAction->setShortcut(tr("Ctrl+N"));
    QAction *startServerAction=new QAction("Запустить сервер",this);
    connect(startServerAction,SIGNAL(triggered()),this,SLOT(startServer()));
    startServerAction->setShortcut(tr("Ctrl+S"));
    QAction *connectServerAction=new QAction("Соединиться с сервером",this);
    connect(connectServerAction,SIGNAL(triggered()),this,SLOT(connectServer()));
    connectServerAction->setShortcut(tr("Ctrl+C"));
    QAction *exitAction=new QAction("Выход",this);
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));
    exitAction->setShortcut(tr("Ctrl+X"));

    QMenu *menu = menuBar()->addMenu("Игра");
    menu->addAction(newGameAction);
    menu->addAction(startServerAction);
    menu->addAction(connectServerAction);
    menu->addSeparator();
    menu->addAction(exitAction);
}

void MainWindow::createGame()
{
    timerStop = true;
    dialogNewField->setText("Начните новую игру!");
    center(dialogNewField);
    dialogNewField->exec();
}

void MainWindow::GameOver()
{
    QSound::play("wav/explo.wav");
    timerStop = true;
    dialogNewField->setText("Вы проиграли!");
    center(dialogNewField);
    dialogNewField->exec();
}

void MainWindow::Win()
{
    QSound::play("wav/appl.wav");
    timerStop = true;
    dialogNewField->setText("Вы выиграли");
    center(dialogNewField);
    dialogNewField->exec();
}

void MainWindow::createNewField(int a,int b,int c)
{
    qDebug() << "createNewField";
    if(field)
        delete field;
    field = new MainWidget(a,b,c);
    row = a;
    col = b;
    updateMines(c);
    createNewField();
}

void MainWindow::createNewField(QList<QList<int> > mat,int mines,QStringList presses,QList<QPair<int, int> > pressBut)
{
    if(field)
        delete field;
    field = new MainWidget(mat, mines);
    field->presses = presses;
    field->pressBut = pressBut;
    row = mat.size();
    col = mat[0].size();
    updateMines(mines);
    createNewField();
    updateField();
}

void MainWindow::createNewField()
{
    QTimer::singleShot(5,this,SLOT(res()));
    setCentralWidget(field);
    connect(field,SIGNAL(boom()),this,SLOT(GameOver()));
    connect(field,SIGNAL(progress(int)),pb,SLOT(setValue(int)));
    connect(field,SIGNAL(updateMines(int)),this,SLOT(updateMines(int)));
    connect(field,SIGNAL(finish()),this,SLOT(Win()));
    connect(field,SIGNAL(newGame()),this,SLOT(newGame()));
    connect(field,SIGNAL(sendClient(QString,int,int)),this,SLOT(sendClient(QString,int,int)));

    pb->setValue(0);
    this->updateGeometry();
    QTimer::singleShot(2,this,SLOT(center()));

    timerStop = false;
    time = 0;
    lcd->display(time);
}
void MainWindow::updateField()
{
    if (field->presses.isEmpty())
        return;
    for(int n = 0 ; n < field->presses.size() ; n++)
        this->doClick(field->presses[n],field->pressBut[n].first,field->pressBut[n].second);
}

void MainWindow::updateMines(int mine)
{
    mines->setText(QString::number(mine));
}

void MainWindow::res()
{
    resize(23*col,23*row);
    this->setFixedSize(size());
}

void MainWindow::center()
{
    qDebug() << "center";
    QRect frect = frameGeometry();
    frect.moveCenter(QDesktopWidget().availableGeometry().center());
    move(frect.topLeft());
}

void MainWindow::center(QDialog* dlg)
{
    QRect frect = dlg->frameGeometry();
    frect.moveCenter(QDesktopWidget().availableGeometry().center());
    dlg->move(frect.topLeft());
}

void MainWindow::newGame()
{
//    qDebug() << "newGame";
    if (!timerStop)
    {
        lcd->display(time++);
        timer->setSingleShot(false);
        timer->singleShot(1000,this,SLOT(newGame()));
    }
}

void MainWindow::startServer()
{
    qDebug() << "SERVER";
    isServer = true;
    server = new ServerDialog(field);
    server->show();
    this->connectServer();
}

void MainWindow::connectServer()
{
    isClient = true;
    client = new Client;
    connect(client,SIGNAL(createNewField(QList<QList<int> >,int,QStringList,QList<QPair<int, int> >)),
            this,SLOT(createNewField(QList<QList<int> >,int,QStringList,QList<QPair<int, int> >)));
    connect(client,SIGNAL(doClick(QString , int , int )),this,SLOT(doClick(QString , int , int )));

    client->show();
}

void MainWindow::sendClient(QString type, int i, int j)
{
//    qDebug () <<  "MainWindow::sendClient";
    if(isClient)
    {
        client->sendClient(type, i, j);
    }
}

void MainWindow::doClick(QString type, int i, int j)
{
//    qDebug () <<  "MainWindow::doClick";
    field->doClick(type,i,j);
}


