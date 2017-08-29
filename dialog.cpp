#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

double Dialog::getMin()
{
    return ui->minLineEdit->text().toDouble();
}

double Dialog::getMax()
{
    return ui->maxLineEdit->text().toDouble();
}

Dialog::~Dialog()
{
    delete ui;
}
