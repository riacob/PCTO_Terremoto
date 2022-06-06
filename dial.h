#ifndef DIAL_H
#define DIAL_H

#include <QDial>
#include <QObject>
#include <QWidget>

class Dial : public QDial
{
    Q_OBJECT

public:
    Dial(QWidget *parent = nullptr);
    ~Dial();

    //metodo con la stessa funzione della setValue(), ma il valore verrà raggiunto con un certo
    //ritardo in modo da consentire un'animazione dell'ago
    void setValueAnim(int value);

private:

    //immagine sfondo dell'energometro
    QPixmap* backgroundImg;

    //immagine dell'ago
    QPixmap* needleImg;

    //immagine dell'ombra dell'ago
    QPixmap* needleShadowImg;

    //"dipinge" l'immagine finale del dial a schermo
    //combinando sfondo, ago e ombra
    void paintEvent(QPaintEvent*);

    //anima l'ago
    void animateNeedle();

    //contiene il valore che value() raggiungerà al termine della setValueAnim()
    //per dare un riferimento a animateNeedle():
    //il value() deve aumentare o diminuire?
    int valueToReach;

    //richiede alla scheda il valore di energia attuale
    //e lo imosta come valore tramite setValueAnim()
    //void valueRequest();

};

#endif // DIAL_H
