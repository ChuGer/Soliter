#ifndef CREATENEWFIELD_H
#define CREATENEWFIELD_H

#include <QDialog>

namespace Ui {
    class CreateNewField;
}

class CreateNewField : public QDialog {
    Q_OBJECT
public:
    CreateNewField();
    ~CreateNewField();
    void setText(QString info);
    bool isAccept;

private:
    Ui::CreateNewField *ui;
    void closeEvent ( QCloseEvent * e );
signals:
    void acepted(int,int,int);
    void exits();
private slots:
    void on_comboBox_currentIndexChanged(int index);
    void on_exitButton_clicked();
    void on_okButton_clicked();
};

#endif // CREATENEWFIELD_H
