#ifndef GRAFICO_H
#define GRAFICO_H

#include "serialtransreceiver.h"

class Grafico
{
public:
    Grafico(SerialTransreceiver* serialTransreceiver);
private:
    SerialTransreceiver* serial;
};

#endif // GRAFICO_H
