#ifndef MANOMETRO_DIALOG_H
#define MANOMETRO_DIALOG_H

#include <QDialog>
#include "serialtransreceiver.h"

namespace Ui {
class Dialog;
}

class ManometroDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManometroDialog(SerialTransreceiver* serialTransreceiver, QWidget *parent = nullptr);
    ~ManometroDialog();

private slots:
    void on_pB_Ok_clicked();

    void on_pB_Pollice_clicked();

    void on_pB_Arrivederci_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Dialog *ui;
    SerialTransreceiver* serial;

};

#endif // MANOMETRO_DIALOG_H
