#include "com.h"
#include "ui_com.h"
#include "QSerialPortInfo"

COM::COM(SerialTransreceiver* serialTransreceiver, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::COM)
{
    ui->setupUi(this);
    serial = serialTransreceiver;
}

COM::~COM()
{
    delete ui;
}

void COM::on_pushButtonRefreshPorts_clicked()
{
    // Add all available ports and their description to the list
    QSerialPortInfo serialInfo(*serial->getSerialPort());
    QString portInfo;
    for (int i = 0; i < serialInfo.availablePorts().length(); i++) {
        portInfo = serialInfo.availablePorts().at(i).portName();
        portInfo.append(" - ");
        portInfo.append(serialInfo.availablePorts().at(i).description());
        ui->listWidgetPort->addItem(portInfo);
    }
}


void COM::on_buttonBox_accepted()
{
    // If no port is selected we return
    if (ui->listWidgetPort->selectedItems().empty()) {
        return;
    }
    // Get the selected string containing the port name and the port description from the list
    QString portText = ui->listWidgetPort->selectedItems().at(0)->text();
    int chopIdx = 0;
    // Chop the string leaving only the serial port name
    while (portText.at(chopIdx) != '-') {
        chopIdx++;
    }
    portText.truncate(chopIdx);
    portText = portText.trimmed();
    serial->setPortName(portText);
}

