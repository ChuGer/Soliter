#include "mainwidget.h"
#include <QTime>
#include <QtGui>
#include <qpalette.h>

MainWidget::MainWidget(int row,int col,int mines) : row(row), col(col), mines(mines)
{
    all = row*col-mines;
    cur=0;
    fields = new TGbutton * [row];
    rows=new QHBoxLayout[row];
    rows->setSpacing(0);
    cols=new QVBoxLayout;
    cols->setSpacing(0);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for (int i=0; i < row; i++)
    {   
        fields[i]=new TGbutton[col];
        for(int j=0;j<col;j++)
        {
            fields[i][j].setAB(i,j);
            fields[i][j].setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
            rows[i].addWidget(& (fields[i][j]));
            connect(&fields[i][j],SIGNAL(clicked()),this,SLOT(check()));
            connect(&fields[i][j],SIGNAL(rightClicked()),this,SLOT(rightClicked()));
            connect(&fields[i][j],SIGNAL(doubleClicked()),this,SLOT(doubleClicked()));
        }
    }
    for (int i=0;i<row;i++)
        cols->addLayout(& (rows[i]));
    //    mat=new int *[row];
    for (int i=0;i<row;i++)
    {
        QList<int> row;
        //        mat[i]=new int[col];
        for (int j=0;j<col;j++)
            row << 0;
        mat << row;
    }
    setLayout(cols);
    for (int i=0;i<mines;)
    {
        int e=qrand()%(row-1);
        int q=qrand()%(col-1);
        if(mat[e][q]!=-1)
        {
            mat[e][q]=-1;
            i++;
        }
    }
    for(int i=0;i<row;i++)
        for (int j=0;j<col;j++)
        {
        if(mat[i][j]==-1)
        {
            if((i-1)>=0)
            {
                if(mat[i-1][j]!=-1)
                    mat[i-1][j]++;
                
                if((j+1)<col)
                    if(mat[i-1][j+1]!=-1)
                        mat[i-1][j+1]++;
                
                if((j-1)>=0)
                    if(mat[i-1][j-1]!=-1)
                        mat[i-1][j-1]++;
            }
            
            if((i+1)<row)
            {
                if(mat[i+1][j]!=-1)
                    mat[i+1][j]++;
                
                if(j+1<col)
                    if(mat[i+1][j+1]!=-1)
                        mat[i+1][j+1]++;
                
                if(j-1>=0)
                    if(mat[i+1][j-1]!=-1)
                        mat[i+1][j-1]++;
            }
            if((j+1)<col)
                if(mat[i][j+1]!=-1)
                    mat[i][j+1]++;
            
            if((j-1)>=0)
                if(mat[i][j-1]!=-1)
                    mat[i][j-1]++;
        }
    }
    isNewGame = false;
    QTimer::singleShot(1,this,SLOT(res()));
    isNotSend = false;
    isEmitter = false;

}

MainWidget::MainWidget(QList<QList<int> > mat, int mines) : mat(mat),mines(mines)
{
    row = mat.size();
    col = mat[0].size();
    all = row*col-mines;
    cur = 0;
    fields = new TGbutton * [row];
    rows = new QHBoxLayout[row];
    rows->setSpacing(0);
    cols = new QVBoxLayout;
    cols->setSpacing(0);

    for (int i = 0; i < row; i++)
    {
        fields[i] = new TGbutton[col];
        for(int j = 0 ; j < col ; j++)
        {
            fields[i][j].setAB(i,j);
            fields[i][j].setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
            rows[i].addWidget(& (fields[i][j]));
            connect(&fields[i][j],SIGNAL(clicked()),this,SLOT(check()));
            connect(&fields[i][j],SIGNAL(rightClicked()),this,SLOT(rightClicked()));
            connect(&fields[i][j],SIGNAL(doubleClicked()),this,SLOT(doubleClicked()));
        }
    }
    for (int i=0;i<row;i++)
        cols->addLayout(& (rows[i]));
    setLayout(cols);

    isNewGame = false;
    QTimer::singleShot(1,this,SLOT(res()));
    isNotSend = false;
    isEmitter = false;

}

void MainWidget::check()
{

    //    qDebug() << "check";
    isEmitter = false;
    TGbutton *button = (TGbutton*)sender();
    if (button->curState != TGbutton::First)
        return;

    if (isNewGame == false)
    {
        isNewGame = true;
        emit newGame();
    }
    cur++;
    if(cur == all)
    {        
        type = true;
        for (int i=0; i < row; i++)
        {
            for(int j=0;j<col;j++)
            {
                if (fields[i][j].curState == TGbutton::First)
                {
                    if (mat[i][j]==-1)
                        fields[i][j].setIcon(QIcon(":/bomb.png"));
                    else
                        fields[i][j].click();
                }
                else if (fields[i][j].curState == TGbutton::Flag && mat[i][j] != -1)
                {
                    type = false;
                    QPalette pal = fields[i][j].palette();
                    pal.setColor(QPalette::Button,QColor(249,123,126,128));
                    fields[i][j].setPalette(pal);
                }
            }
        }

        emit progress(100);

        QTimer::singleShot(1,this,SLOT(theEnd()));
        return;
    }
    int a,b;
    button->GetAB(a,b);
    qDebug() << "click" << a << b;

    if (isNotSend == false)
    {
        isEmitter = true;
        emit sendClient("CLICK", a, b);
    }


    presses << "CLICK";
    QPair <int,int> pair;
    pair.first = a;
    pair.second = b;
    pressBut << pair;

    QColor color;
    if(mat[a][b] == -1)
    {
        type = false;

        for (int i=0; i < row; i++)
        {
            for(int j=0;j<col;j++)
            {

                if(mat[i][j] == -1 && fields[i][j].curState == TGbutton::First)
                    fields[i][j].setIcon(QIcon(":/bomb.png"));
                else if ((mat[i][j] == -1 && fields[i][j].curState != TGbutton::Flag) ||
                         (mat[i][j] != -1 && fields[i][j].curState == TGbutton::Flag))
                {
                    QPalette pal = fields[i][j].palette();
                    pal.setColor(QPalette::Button,QColor(249,123,126,128));
                    fields[i][j].setPalette(pal);
                }
            }
        }

        QTimer::singleShot(100,this,SLOT(theEnd()));
        return;
    }
    else if(mat[a][b] == 1)
        color.setRgb(50,205,80,255);
    else if(mat[a][b] == 2)
        color.setRgb(220,160,40,255);
    else if(mat[a][b] == 0)
        color.setRgb(0,0,0,255);
    else
        color.setRgb(255,0,0,255);

    button->curState = TGbutton::Click;

    QFont font("Sans",10,10,false);
    button->setFont(font);
    button->setMaximumWidth(button->width());
    QPalette p=button->palette();
    p.setColor(QPalette::ButtonText,color);
    p.setColor(QPalette::Button,QColor(182,214,220,128));
    button->setPalette(p);       
    if (mat[a][b] != 0)
        button->setText(QString::number(mat[a][b]));
    else
        clickRound(a,b);    

    isNotSend = false;
    emit progress((int)(((float)cur/(float)all)*100));
}

void MainWidget::theEnd()
{
    if (type)
        emit finish();
    else
        emit boom();
}


void MainWidget::rightClicked()
{
    qDebug() << "rightClicked";

    TGbutton *button = (TGbutton*)sender();

    int a,b;
    button->GetAB(a,b);
    emit sendClient("RIGHT", a, b);

    presses << "RIGHT";
    QPair <int,int> pair;
    pair.first = a;
    pair.second = b;
    pressBut << pair;

    if(button->curState == TGbutton::First)
    {
        button->setIcon(QIcon(":/flag.png"));
        button->curState = TGbutton::Flag;
        emit updateMines(--mines);
    }
    else if(button->curState == TGbutton::Flag)
    {
        button->setIcon(QIcon());
        button->curState = TGbutton::First;
        emit updateMines(++mines);
    }
}


void MainWidget::rightClicked(int i, int j)
{
    qDebug() << "rightClicked" << i << j;

    TGbutton *button = &fields[i][j];
    if(button->curState == TGbutton::First)
    {
        button->setIcon(QIcon(":/flag.png"));
        button->curState = TGbutton::Flag;
        emit updateMines(--mines);
    }
    else if(button->curState == TGbutton::Flag)
    {
        button->setIcon(QIcon());
        button->curState = TGbutton::First;
        emit updateMines(++mines);
    }
}

void MainWidget::clickRound(int a ,int b)
{
    this->isNotSend = true;

    if (a-1 >= 0)
        fields[a-1][b].click();
    if (a+1 < row)
        fields[a+1][b].click();
    if (b-1 >= 0)
        fields[a][b-1].click();
    if (b+1 < col)
        fields[a][b+1].click();
    if (a-1 >= 0 && b-1 >= 0)
        fields[a-1][b-1].click();
    if (a+1 < row && b+1 < col)
        fields[a+1][b+1].click();
    if (a-1 >= 0 && b+1 < col)
        fields[a-1][b+1].click();
    if (a+1 < row && b-1 >= 0)
        fields[a+1][b-1].click();

    this->isNotSend = false;

}
void MainWidget::doubleClicked()
{    
    qDebug() << "doubleClicked";
    TGbutton *button = (TGbutton*)sender();
    if (button->curState != TGbutton::Click)
        return;
    int a,b;
    button->GetAB(a,b);


    int counter = 0;
    if (a-1 >= 0 && fields[a-1][b].curState == TGbutton::Flag) counter++;
    if (a+1 < row && fields[a+1][b].curState == TGbutton::Flag) counter++;
    if (b-1 >= 0 && fields[a][b-1].curState == TGbutton::Flag) counter++;
    if (b+1 < col && fields[a][b+1].curState == TGbutton::Flag) counter++;
    if (a-1 >= 0 && b-1 >= 0 && fields[a-1][b-1].curState == TGbutton::Flag) counter++;
    if (a+1 < row && b+1 < col && fields[a+1][b+1].curState == TGbutton::Flag) counter++;
    if (a-1 >= 0 && b+1 < col && fields[a-1][b+1].curState == TGbutton::Flag) counter++;
    if (a+1 < row && b-1 >= 0 && fields[a+1][b-1].curState == TGbutton::Flag) counter++;

    if (button->text().toInt() == counter)
    {
        button->curState = TGbutton::Disable;
        emit sendClient("DOUBLE", a, b);        
        presses << "DOUBLE";
        QPair <int,int> pair;
        pair.first = a;
        pair.second = b;
        pressBut << pair;
        clickRound(a,b);
    }
}

void MainWidget::doubleClicked(int i,int j)
{
    qDebug() << "doubleClicked" << i << j;
    TGbutton *button = &fields[i][j];
    button->curState = TGbutton::Disable;
    clickRound(i,j);
}

MainWidget::~MainWidget()
{
    for (int i = 0 ; i < row ; i++)
        delete [] fields[i];
    mat.clear();
    delete[] fields;
    delete[] rows;
    delete cols;
}

void MainWidget::doClick(QString type, int i ,int j)
{
    if (isEmitter)
    {
     this->isEmitter = false;
        return;
    }
    qDebug() << "MainWidget::doClick" << type << i << j;
    if(type == "CLICK")
    {
        isNotSend = true;
        this->fields[i][j].click();
    }
    else if (type == "RIGHT")
        this->rightClicked(i,j);
    else if (type == "DOUBLE")
        this->doubleClicked(i,j);
}

void MainWidget::res()
{
    resize(25*col,25*row);
}


