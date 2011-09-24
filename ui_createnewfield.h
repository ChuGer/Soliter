/********************************************************************************
** Form generated from reading UI file 'createnewfield.ui'
**
** Created: Mon 7. Jun 22:47:25 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENEWFIELD_H
#define UI_CREATENEWFIELD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_CreateNewField
{
public:
    QSpinBox *rows;
    QSpinBox *columns;
    QSpinBox *mines;
    QPushButton *okButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *exitButton;
    QLabel *info;
    QComboBox *comboBox;

    void setupUi(QDialog *CreateNewField)
    {
        if (CreateNewField->objectName().isEmpty())
            CreateNewField->setObjectName(QString::fromUtf8("CreateNewField"));
        CreateNewField->resize(218, 192);
        rows = new QSpinBox(CreateNewField);
        rows->setObjectName(QString::fromUtf8("rows"));
        rows->setGeometry(QRect(40, 100, 41, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Narrow"));
        font.setPointSize(10);
        font.setItalic(true);
        rows->setFont(font);
        rows->setFrame(true);
        rows->setMinimum(9);
        rows->setMaximum(24);
        rows->setSingleStep(10);
        rows->setValue(16);
        columns = new QSpinBox(CreateNewField);
        columns->setObjectName(QString::fromUtf8("columns"));
        columns->setGeometry(QRect(130, 100, 42, 22));
        columns->setFont(font);
        columns->setFrame(true);
        columns->setMinimum(9);
        columns->setMaximum(30);
        columns->setSingleStep(10);
        columns->setValue(16);
        mines = new QSpinBox(CreateNewField);
        mines->setObjectName(QString::fromUtf8("mines"));
        mines->setGeometry(QRect(130, 120, 42, 22));
        mines->setFont(font);
        mines->setFrame(true);
        mines->setMinimum(10);
        mines->setMaximum(100);
        mines->setSingleStep(10);
        mines->setValue(40);
        okButton = new QPushButton(CreateNewField);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setEnabled(true);
        okButton->setGeometry(QRect(24, 150, 111, 23));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Narrow"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        okButton->setFont(font1);
        label = new QLabel(CreateNewField);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 80, 71, 21));
        label->setFont(font);
        label_2 = new QLabel(CreateNewField);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 100, 16, 21));
        label_2->setFont(font);
        label_3 = new QLabel(CreateNewField);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 120, 111, 21));
        label_3->setFont(font);
        exitButton = new QPushButton(CreateNewField);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(134, 150, 61, 23));
        exitButton->setFont(font1);
        info = new QLabel(CreateNewField);
        info->setObjectName(QString::fromUtf8("info"));
        info->setGeometry(QRect(14, 10, 191, 21));
        info->setFont(font1);
        info->setAlignment(Qt::AlignCenter);
        comboBox = new QComboBox(CreateNewField);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(34, 50, 161, 21));

        retranslateUi(CreateNewField);

        comboBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(CreateNewField);
    } // setupUi

    void retranslateUi(QDialog *CreateNewField)
    {
        CreateNewField->setWindowTitle(QApplication::translate("CreateNewField", "\320\235\320\276\320\262\320\260\321\217 \320\270\320\263\321\200\320\260?", 0, QApplication::UnicodeUTF8));
        rows->setSpecialValueText(QString());
        rows->setPrefix(QString());
        columns->setSpecialValueText(QString());
        columns->setPrefix(QString());
        mines->setSpecialValueText(QString());
        mines->setPrefix(QString());
        okButton->setText(QApplication::translate("CreateNewField", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\275\320\276\320\262\321\203\321\216 \320\270\320\263\321\200\321\203", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CreateNewField", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\277\320\276\320\273\321\217", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CreateNewField", "\320\275\320\260", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CreateNewField", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\274\320\270\320\275", 0, QApplication::UnicodeUTF8));
        exitButton->setText(QApplication::translate("CreateNewField", "\320\222\321\213\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
        info->setText(QApplication::translate("CreateNewField", "TextLabel", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("CreateNewField", "\320\235\320\276\320\262\320\270\321\207\320\276\320\272", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreateNewField", "\320\241\321\200\320\265\320\264\320\275\320\270\320\271", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreateNewField", "\320\222\321\213\321\201\320\276\320\272\320\270\320\271", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class CreateNewField: public Ui_CreateNewField {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENEWFIELD_H
