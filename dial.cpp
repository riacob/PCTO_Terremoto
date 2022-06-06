#include "dial.h"
#include <QTimer>
#include <QPainter>

Dial::Dial(QWidget *parent) :
    QDial(parent)
{
    //imposto l'immagine che farà da sfondo
    backgroundImg = new QPixmap(":/manometro_sfondo.svg");

    //imposto l'immagine che farà da ago
    needleImg = new QPixmap(":/ago.svg");

    //imposto l'immagine che farà da ombra per l'ago
    needleShadowImg = new QPixmap(":/ombra_ago.svg");

    valueToReach = value();

    //faccio la prima richiesta dati in modo da iniziare il ciclo automatico di richieste
   // valueRequest();
}

Dial::~Dial()
{
    //ripulisco l'heap dalle immagini
    delete backgroundImg;
    delete needleImg;
    delete needleShadowImg;
}

void Dial::paintEvent(QPaintEvent*){

    QPainter painter(this);


    //definisco i punti di inizio da cui inizieranno le immagini
    QPoint start(0, 0);
    QPoint centre(width() /2, height() / 2);


    //SFONDO
    //disegno l'immagine di sfondo ridimensionata in modo tale da far si che l'altezza corrisponda a quello del dial
    painter.drawPixmap(start, backgroundImg->scaledToHeight(height()));


    //AGO
    //ruoto e ridimensiono l'immagine dell'ago
    QTransform transform;
    transform.rotate(value() - 135);
    //se dimensioneFinale = dimensioneIniziale * fattoreDiScala
    //allora fattoreDiScala = dimenzioneFinale / dimensioneIniziale
    double scaleRatio = (height() / 1.5) / needleImg->height();
    transform.scale(scaleRatio, scaleRatio);

    //applico le trasformazioni
    QPixmap *transNeedleImg = new QPixmap(needleImg->transformed(transform));
    QPixmap *transNeedleShadowImg = new QPixmap(needleShadowImg->transformed(transform));

    //definisco i punti di inizio per il Painter
    QPoint needleStart(centre.x() - transNeedleImg->width() / 2, centre.y() - transNeedleImg->height() / 2);

    //Ombra ago
    //inserisco prima l'ombra perchè ciò che verrà messo dopo andrà a coprire quello messo in precedenza
    //parametri dell'ombra
    int sfy = 4; //sfasamento negativo verticale
    QPoint shadowStartingPoint(needleStart.x(), needleStart.y() + sfy);
    painter.drawPixmap(shadowStartingPoint, *transNeedleShadowImg);

    //infine inserisco il corpo dell'ago
    painter.drawPixmap(needleStart, *transNeedleImg);

}


void Dial::setValueAnim(int value){
    valueToReach = value;
    animateNeedle();
}


//la seguente funzione può essere definita ricorsiva:
//presenta una condizione di terminaione e due condizioni in cui si autorichiama
//il richiamo avviene con un certo ritardo per consetire la visualizzazione a schermo
//del cambiamento effettuato (visualizzare l'animazione)
//Non ha parametri perché il value() e il valueToReach sono attributi della classe
//Si è preferito settare il value() ad ogni passata in quanto il suo aggiornamento automaticamente
//richiama la funzione incaricata a "dipingere" il dial (paintEvent())
void Dial::animateNeedle(){

    //se ho raggiunto il valore desiderato termino la funzione di animazione
    if(valueToReach == value())
        return;

    if(valueToReach > value()){
        //vario il valore di uno in modo da coprire tutti i valori
        //uso questa funzione per richiamare automaticamete paintEven()
        setValue(value() + 1);
        //attendo 5ms prima di "dipingere" l'ago con il valore successivo
        QTimer::singleShot(5, this, &Dial::animateNeedle);
    }

    else if(valueToReach < value()){
          setValue(value() - 1);
         QTimer::singleShot(5, this, &Dial::animateNeedle);
    }

}


/*void Dial::valueRequest(){
    int newValue;
    // *RICHIEDE IL VALORE ALLA SCHEDA*

    setAnimValue(newValue);

    //la funzione si richiamerà automaticamente dopo un certo tempo tale
    //da garantire un aggiornamente costante sul valore di energia del condensatore
    QTimer::singleShot(500, this, &Dial::valueRequest);

}

*/
