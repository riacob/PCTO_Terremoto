#include "impostazioni.h"
#include "ui_impostazioni.h"
#include <QString>
#include <QSlider>
#include <QTimer>
#include <QDialog>
#include "com.h"

Impostazioni::Impostazioni(QWidget *parent) :     //
    QDialog(parent),
    ui(new Ui::Impostazioni)
{
    ui->setupUi(this);
}

Impostazioni::~Impostazioni()
{
    delete ui;
}

void Impostazioni::on_verticalSlider_sliderMoved(int position)       // range di valori del magnitudo e lo divido per 10 per aver
{
    double Magnitudo=position/10.0;                                         // i valori dopo la virgola nella lable

    ui->label_2->setText(QString::number(Magnitudo));

}




void Impostazioni::on_spinBox_valueChanged(int arg1)     //setto massimo valore della progress bar uguale a quello dello spin box
 {
    ui->progressBar->setMaximum(arg1);

}



void Impostazioni::on_pushButton_clicked()       //
{
    start();
  }

void Impostazioni::on_horizontalSlider1_sliderMoved(int Trascorrente)        //Mostro nella lable il valore dello slider trascorrente
{
    ui->label_trascorrente->setText(QString::number(Trascorrente));

}



void Impostazioni::on_horizontalSlider_2_sliderMoved(int diretta)            //Mostro nella lable il valore dello slider diretta
{
    ui->label_diretta->setText(QString::number(diretta));

}

void Impostazioni::on_horizontalSlider_3_sliderMoved(int inversa)            //Mostro nella lable il valore dello slider inversa
{
    ui->label_inversa->setText(QString::number(inversa));

}



void Impostazioni::enableUi(bool enabled)                                  //pongo una costante per l'attivazioe o
{                                                                                 //disattivazione dei groupBox
 ui->groupBox->setEnabled(enabled);
 ui->groupBox_2->setEnabled(enabled);
 ui->groupBox_4->setEnabled(enabled);
 ui->groupBox_8->setEnabled(enabled);

 ui->pushButton->setEnabled(enabled);                                               //pongo una costante per l'attivazioe o
                                                                                    //disattivazione del pulsante conferma
}

void Impostazioni::start()
{
    // Non posso modificare i parametri quando inizia la simulazione
    enableUi(false);

    // Controllo se il valore di qSlider è già al massimo o se è nullo
    // In caso affermativo, ignoro tutto il codice della funzione
    if ((ui->progressBar->value() + 1 > ui->progressBar->maximum()) || (ui->spinBox->value() <= 0)) {
        enableUi(true);
        return;
    }

    // Altrimenti, aumento il valore di qSlider
    ui->progressBar->setValue(ui->progressBar->value()+1);

    // E aspetto 1 secondo prima di reiniziare il ciclo
    QTimer::singleShot(1000, this, SLOT(start()));
}



void Impostazioni::on_pushButton_2_clicked()
{
    COM* com;
    com= new COM();
    com->show();
}

void Impostazioni::on_pushButton_3_clicked()
{
 close();
}
