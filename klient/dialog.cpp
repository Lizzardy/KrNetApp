#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->lineEdit->setText("127.0.0.1");
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::adresa()
{
    return ui->lineEdit->text();
}
int Dialog::port()
{
    return ui->spinBox->value();
}

void Dialog::accept()
{

    QRegExp xp;
    xp.setPattern("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    if(!ui->lineEdit->text().contains(xp))
        qWarning()<< "spatne zadana ip adresa";
    else{
        QDialog::accept();
    }
}
