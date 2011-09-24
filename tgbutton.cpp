#include "tgbutton.h"
#include <QMouseEvent>
#include <QDebug>

TGbutton::TGbutton()
{
    curState = First;
    this->setFixedHeight(23);
    this->setFixedWidth(23);
}

void TGbutton::GetAB(int & c,int & d)
{
    c = a;
    d = b;
}

void TGbutton::setAB(int c,int d)
{
    a = c;
    b = d;
}

void TGbutton::mousePressEvent ( QMouseEvent * e )
{
    qDebug() << "mousePressEvent";

    if(e->button() == Qt::LeftButton)
        emit clicked();
    else if(e->button() == Qt::RightButton)
        emit rightClicked();

}

void TGbutton::mouseDoubleClickEvent ( QMouseEvent * e )
{
    qDebug() << "mouseDoubleClickEvent";
    emit doubleClicked();
}


