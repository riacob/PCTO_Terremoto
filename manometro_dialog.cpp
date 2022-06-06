#include "manometro_dialog.h"
#include "ui_manometro_dialog.h"


ManometroDialog::ManometroDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}


ManometroDialog::~ManometroDialog()
{
    delete ui;
}


void ManometroDialog::on_pB_Ok_clicked()
{
    //*INVIO CONFERMA PER LA PARTENZA DELLA SIMULAZIONE*
}


void ManometroDialog::on_pB_Pollice_clicked()
{
    //*INVIO RESET VALORE ENERGIA*
    //azzero il valore del dial tramite animazione
    ui->dial->setValueAnim(0);

}


void ManometroDialog::on_pB_Arrivederci_clicked()
{
    //chiude il dialog
    close();
}


//inutile per il programma finale, uso a scopo do test
void ManometroDialog::on_spinBox_valueChanged(int arg1)
{
    ui->dial->setValueAnim( arg1);
}

