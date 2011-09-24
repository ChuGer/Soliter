#ifndef MainWidget_H
#define MainWidget_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMutex>

#include "tgbutton.h"

class MainWidget : public QWidget
{
    Q_OBJECT

private:
    int row,col,all,cur;
    TGbutton **fields;
    QHBoxLayout *rows;
    QVBoxLayout *cols;
    void clickRound(int, int);
    bool type;
    bool isNewGame;
    bool isNotSend;
    bool isEmitter;
QMutex mutex;
public:
    MainWidget(int row=16,int col=16,int mines=40);
    MainWidget(QList<QList<int> > mat,int mines);
    ~MainWidget();
    QList<QList<int> > mat;
    int mines;
    QStringList presses;
    QList<QPair<int,int> > pressBut;

public slots:
    void check();
    void rightClicked();
    void rightClicked(int i, int j);
    void doubleClicked();
    void doubleClicked(int i,int j);
    void theEnd();
    void doClick(QString, int,int);
    void res();

signals:
    void boom();
    void progress(int);
    void finish();
    void updateMines(int);
    void newGame();
    void sendClient(QString, int, int);


};

#endif // MainWidget_H
