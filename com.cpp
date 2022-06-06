#include "com.h"
#include "ui_com.h"

COM::COM(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::COM)
{
    ui->setupUi(this);
}

COM::~COM()
{
    delete ui;
}
