#ifndef COM_H
#define COM_H

#include <QDialog>
#include "serialtransreceiver.h"

namespace Ui {
class COM;
}

class COM : public QDialog
{
    Q_OBJECT

public:
    explicit COM(SerialTransreceiver* serialTransreceiver, QWidget *parent = nullptr);
    ~COM();

private slots:
    void on_pushButtonRefreshPorts_clicked();

    void on_buttonBox_accepted();

private:
    Ui::COM *ui;
    SerialTransreceiver* serial;
};

#endif // COM_H
