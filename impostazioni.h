#ifndef IMPOSTAZIONI_H
#define IMPOSTAZIONI_H

#include <QDialog>
#include <QObject>
#include <QWidget>
#include "serialtransreceiver.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Impostazioni;
}

class Impostazioni : public QDialog
{
    Q_OBJECT

public:
    explicit Impostazioni(SerialTransreceiver* serialTransreceiver, QWidget *parent = nullptr);
    ~Impostazioni();


    // definizione dei metodi
private slots:
    void on_verticalSlider_sliderMoved(int position);


    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_horizontalSlider1_sliderMoved(int position);

    void on_horizontalSlider_2_sliderMoved(int position);

    void on_horizontalSlider_3_sliderMoved(int position);


    //Rendiamo tutti i groupBox non cliccabili per non interferire con la
    // simulazione durante essa

private:
    Ui::Impostazioni *ui;
    void enableUi(bool enabled);
    void resetUi();
    SerialTransreceiver* serial;

    // premendo il pulsante CANCEL la finestra si chiude
private slots:
    void start();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // IMPOSTAZIONI_H
