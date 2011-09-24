/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created: Mon 7. Jun 22:47:26 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QLineEdit *hostLineEdit;
    QLineEdit *portLineEdit;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QString::fromUtf8("Client"));
        Client->resize(209, 127);
        hostLineEdit = new QLineEdit(Client);
        hostLineEdit->setObjectName(QString::fromUtf8("hostLineEdit"));
        hostLineEdit->setGeometry(QRect(80, 20, 113, 20));
        portLineEdit = new QLineEdit(Client);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));
        portLineEdit->setGeometry(QRect(80, 50, 113, 20));
        pushButton = new QPushButton(Client);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 90, 75, 23));
        label = new QLabel(Client);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 46, 13));
        label_2 = new QLabel(Client);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 50, 46, 13));

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QDialog *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "\320\232\320\273\320\270\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Client", "\320\241\320\276\320\265\320\264\320\270\320\275\320\270\321\202\321\214\321\201\321\217", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Client", "\320\220\320\264\321\200\320\265\321\201\321\201", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Client", "\320\237\320\276\321\200\321\202", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
