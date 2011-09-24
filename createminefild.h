#ifndef CREATEMINEFILD_H
#define CREATEMINEFILD_H

#include <QDialog>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

class CreateMineFild : public QDialog
{
    Q_OBJECT

public:
    CreateMineFild();
private slots:
    void ok_presed();
    void cancel_presed();
signals:
    void acepted (int,int,int);
private:
    QSpinBox sa,sb,sc;
    QLabel la,lb,lc;
    QPushButton ok,cancel;
    QHBoxLayout hi,lo;
    QVBoxLayout layout;
};

#endif // CREATEMINEFILD_H
