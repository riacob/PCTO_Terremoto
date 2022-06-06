/*Benvenuo al programma che serve al funzionamento del tasto "Aiuto nel
  progetto finale, che sarebbe un programma per la simulazione dei terremoti.
  Con questo tasto si potrà far visualizzare, in una finestra di dialogo,
  tutta la spiegazione sufficente alla comprensione dei vari tasti
  all'interno dell'applicazione con relative immagini.*/

#include "aiuto.h"
#include "ui_aiuto.h"
#include <QImage>
#include <QPixmap>

Aiuto::Aiuto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aiuto)
{
    /*Creazione dell'oggetto di calsse QFont per la modifica del font di un label*/

    QFont f2("Segoe UI",10);

    ui->setupUi(this);

    /*Assegnazione del testo all label inerente alla frase di cortesia*/

    ui->Frase_di_Cortesia->setText("Benvenuto nella sezione aiuto. Qui troverai tutte le informazioni\ndi cui potrai aver bisogno mentre utilizzerai\nquesta applicazione");
    ui->Frase_di_Cortesia->setAlignment(Qt::AlignHCenter);                                              /*Fa in modo che la scritta sia centrata*/

    /*Asseganzione della spiegazione del funzionamento dei vari tasti ai relatvi label con l'aggiunta dell'immagine dei relativi tasti*/

    ui->Descrizione_Scudetto->setText("\nQuesto tasto visualizzerà il\nfilmato del Malignani\noperato da un drone.\nI 2 monitor saranno sincronizzati.");

    /*Cambio di font nella scritta del Label*/
    ui->Descrizione_Scudetto->setFont(f2);

    /*Fa in modo che la scritta si conforme ai contorni presenti nella label*/
    ui->Descrizione_Scudetto->setAlignment(Qt::AlignJustify);

    /*Assegan un immagine alla label e la ridimensiona in base alla grandezza della label stessa*/
    ui->Immagine_Scudetto->setPixmap(QPixmap(":/Scudetto.png").scaled(151,111,Qt::KeepAspectRatio));

    /*I commenti precedenti valgono su tutte le funzioni uguali a quelle precedenti*/

    ui->Descrizione_Grafico->setText("Questo tasto visualizzerà l'andamento\ndelle vibrazioni in diretta\ncome se si trattasse di un sismografo\nreale. E visualizzerà 60 secondi senza dover\nscrollare in orizzontale.");
    ui->Descrizione_Grafico->setAlignment(Qt::AlignJustify);
    ui->Immagine_Grafico->setPixmap(QPixmap(":/Grafico.png").scaled(151,111,Qt::KeepAspectRatio));

    ui->Descrizione_Occhio->setText("Questo tasto visualizzerà il filmato del\nlavoro degli studenti ed eventuali\nbackstage simpatici. La durata\ndel video sarà di circa 3/4 minuti.");
    ui->Descrizione_Occhio->setAlignment(Qt::AlignJustify);
    ui->Immagine_Occhio->setPixmap(QPixmap(":/Occhio.png").scaled(151,111,Qt::KeepAspectRatio));

    ui->Descrizione_Icone_da_Campo->setText("Questo tasto serve alla verifica\ndi una comunicazione WiFi attiva.\nQuando attiva, in una finestra ci sarà\nl'indirizzo dove scaricare l'app che permette\ndi stabilire la connessione con il prorpio\ntelefono e il sistema.");
    ui->Descrizione_Icone_da_Campo->setAlignment(Qt::AlignJustify);
    ui->Immagine_Icona_da_campo->setPixmap(QPixmap(":/Icona da campo.png").scaled(151,111,Qt::KeepAspectRatio));

    ui->Descrizione_Ruota_Dentata->setText("\nQuesto tasto permette di impostare i\nparametri della simulazione del\nterremoto. La selezione di default è quella\nche meglio approssima il terremoto del\n Friuli del '76.");
    ui->Descrizione_Ruota_Dentata->setAlignment(Qt::AlignJustify);
    ui->Immagine_Ruota_dentata->setPixmap(QPixmap(":/Ruota Dentata.png").scaled(151,111,Qt::KeepAspectRatio));

    ui->Descrizione_Manometro->setText("Questo tasto dà l'accesso alla finestra di definizione dell'energia del terremoto. Il sistema è dotato di una leva\nche permette di accumulare energia per poi liberarla durante la simulazione. Man mano che la leva viene azionata la\nlancetta si avvicina verso il rosso. Raggiunto il livello desiderato, apparirà une delle tre emoticon."
                                       "\nIn basso a destra ci sarà il seganle di OK che indica quando il valore è stato raggiunto. In basso a sinistra\nci sarà il tasto che permette di abbandonare la finestra e ritornare al sinottico principale.\nIn alto a destra ci sarà il tasto che permette di annullare il tutto e ripartire da zero.");
    ui->Descrizione_Manometro->setAlignment(Qt::AlignJustify);
    ui->Immagine_Manometro->setPixmap(QPixmap(":/Manometro.png").scaled(151,111,Qt::KeepAspectRatio));

    ui->Descrizione_Civetta->setText("Questo tasto permette di visualizzare\ndei video che permettono alla guida di tenere\nuna minilezione sui terremoti alle scolaresche.");
    ui->Descrizione_Civetta->setAlignment(Qt::AlignJustify);
    ui->Immagine_Civetta->setPixmap(QPixmap(":/Civetta.png").scaled(151,111,Qt::KeepAspectRatio));

    ui->Descrizione_Coccinella->setText("Questo tasto permette di accedere ai dati di\ndebug da diversi punti: o tramite la\nconnessione Bluetooth del PC oppure\nalla connessione WiFi del Master.\nEntrambe le connessioni si connettono all'app\ndei manutentori a loro riservata.");
    ui->Descrizione_Coccinella->setAlignment(Qt::AlignJustify);
    ui->Immagine_Coccinella->setPixmap(QPixmap(":/Coccinella.png").scaled(151,111,Qt::KeepAspectRatio));

    ui->Descrizione_Mano_ceh_saluta->setText("Questo tasto permette di chiudere l'app\nin maniera sicura senza che il sistema\noperativo ne rilevi una chiusura inaspettata.");
    ui->Descrizione_Mano_ceh_saluta->setAlignment(Qt::AlignJustify);
    ui->Immagine_Mano_che_saluta->setPixmap(QPixmap(":/Mano.png").scaled(151,111,Qt::KeepAspectRatio));

}

/*Distruttore*/

Aiuto::~Aiuto()
{
    delete ui;
}

/*Settagggio tasto close*/

void Aiuto::on_Close_clicked()
{
    close();
}
