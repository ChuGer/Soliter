#include "createnewfield.h"
#include "ui_createnewfield.h"

CreateNewField::CreateNewField() : ui(new Ui::CreateNewField)
{
    ui->setupUi(this);
    isAccept = false;
    this->setFixedSize(size());

}

CreateNewField::~CreateNewField()
{
    delete ui;
}

void CreateNewField::on_okButton_clicked()
{
    emit acepted(ui->rows->value(),ui->columns->value(),ui->mines->value());
    isAccept = true;
    this->close();
}

void CreateNewField::setText(QString info)
{
    ui->info->setText(info);
}
void CreateNewField::on_exitButton_clicked()
{
    this->close();
}

void CreateNewField::on_comboBox_currentIndexChanged(int index)
{
    if (index == 0)
    {
        ui->rows->setValue(9);
        ui->columns->setValue(9);
        ui->mines->setValue(10);
    }
    else if (index == 1)
    {
        ui->rows->setValue(16);
        ui->columns->setValue(16);
        ui->mines->setValue(40);
    }
    else if (index == 2)
    {
        ui->rows->setValue(16);
        ui->columns->setValue(30);
        ui->mines->setValue(99);
    }
}

void CreateNewField::closeEvent ( QCloseEvent * e )
{
    if (!isAccept)
        emit exits();
    isAccept = false;
}

