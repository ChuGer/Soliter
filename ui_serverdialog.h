/********************************************************************************
** Form generated from reading UI file 'serverdialog.ui'
**
** Created: Tue 8. Jun 12:17:53 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERDIALOG_H
#define UI_SERVERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_ServerDialog
{
public:
    QLineEdit *adress;
    QLineEdit *port;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *ServerDialog)
    {
        if (ServerDialog->objectName().isEmpty())
            ServerDialog->setObjectName(QString::fromUtf8("ServerDialog"));
        ServerDialog->resize(216, 116);
        adress = new QLineEdit(ServerDialog);
        adress->setObjectName(QString::fromUtf8("adress"));
        adress->setGeometry(QRect(80, 30, 113, 20));
        port = new QLineEdit(ServerDialog);
        port->setObjectName(QString::fromUtf8("port"));
        port->setGeometry(QRect(80, 70, 113, 20));
        label = new QLabel(ServerDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 46, 13));
        label_2 = new QLabel(ServerDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 70, 46, 13));

        retranslateUi(ServerDialog);

        QMetaObject::connectSlotsByName(ServerDialog);
    } // setupUi

    void retranslateUi(QDialog *ServerDialog)
    {
        ServerDialog->setWindowTitle(QApplication::translate("ServerDialog", "\320\241\320\265\321\200\320\262\320\265\321\200", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ServerDialog", "\320\220\320\264\321\200\320\265\321\201\321\201", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ServerDialog", "\320\237\320\276\321\200\321\202", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ServerDialog: public Ui_ServerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERDIALOG_H
