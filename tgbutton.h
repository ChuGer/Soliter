#ifndef TGBUTTON_H
#define TGBUTTON_H

#include <QPushButton>

class TGbutton : public QPushButton
{
    Q_OBJECT
public:
    enum State{First,Click,Disable,Flag};
    State curState;

    TGbutton();
    void setAB(int a,int b);
    void GetAB(int &a,int &b);
signals:
    void rightClicked();
    void doubleClicked();

protected:
    void mousePressEvent ( QMouseEvent * e );
    void mouseDoubleClickEvent ( QMouseEvent * e );
private:
    int a,b;
};

#endif // TGBUTTON_H
