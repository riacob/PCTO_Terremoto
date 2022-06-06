#include "scudettomalignani.h"
#include "ui_scudettomalignani.h"

ScudettoMalignani::ScudettoMalignani(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScudettoMalignani)
{
    ui->setupUi(this);

    // La finestra viene settata a fullscreen
    this -> setWindowState(Qt::WindowFullScreen);

    // Inizializzazione del player
    player = new QMediaPlayer(this);

    // Inizializzazione del videowidget
    videowidget = new QVideoWidget(this);

    audio = new QAudioOutput(this);

     // Viene collegato il player al media che deve riprodurre
    player -> setSource(QUrl("qrc:/video_malignani.mp4"));

    // Viene collegato il player al videowidget in modo che possa riprodurre il video
    // Viene collegato il player al videowidget in modo che possa riprodurre il video
    player -> setVideoOutput(videowidget);

    // Viene collegato il player all'audio in modo che possa riprodurre l'audio
    player -> setAudioOutput(audio);

    // Viene settato un volume di default
    audio -> setVolume(50);

    // Viene impostato il video a fullscreen
    videowidget -> setGeometry(this->geometry());

    // Viene fatto partire il video
    player -> play();

    // Per sicurezza si nascondo i GroupBox e le Label
    ui -> groupBox_4EliA -> hide();
    ui -> groupBox_Aeronautica -> hide();
    ui -> groupBox_Assistenti -> hide();
    ui -> groupBox_sigBurelli -> hide();
    ui -> label_riconoscimenti -> hide();

    // Si effettua un connect tra il video il quale mentre viene riprodotto, si entra
    // continuamente nello SLOT ringraziamenti()
    connect(player, &QMediaPlayer::positionChanged, this, &ScudettoMalignani::ringraziamenti);



    // Si impostato i testi delle varie Label

    ui -> studenti_4EliA -> setText("CLASSE 4^ELI-A: allievi che hanno realizzato la parte software e hardware: "
                                    "Azzarone Riccardo - Beltrame Alex - Benedetti Filippo - "
                                    "Bombardella Davide - Bortolussi Riccardo - Bravin Enrico - "
                                    "De Luca Cicale Giuseppe - Don Davide - Gorassini Alessandro"
                                    " - Iacob Riccardo - Mininel Samuele - Negri Gjovani - "
                                    "Pagotto Marco - Puppin Diego - Rovere Cristina - "
                                    "Toso Riccardo - Venir Marco - Zambelli Franz Elia - "
                                    "Zanovello Mattia - Zhu Jin Hao");

    ui -> studenti_Aeronautica -> setText("Classe di Aeronautica: allievi che hanno realizzato "
                                          "il filamto del Malignani: nomi");

    ui -> label_Assistenti -> setText("Assistenti: nomi");

    ui -> label_sigBurelli -> setText("Un speciale riconoscimento va a al sig. Burelli Ranieri"
                                      " il quale ha realizzato tutta la meccanica del simulatore e"
                                      " tutta l'impiantistica della versione precedente");

    ui -> label_riconoscimenti -> setText("RICONOSCIMENTI");



}

ScudettoMalignani::~ScudettoMalignani()
{
    delete ui;
}


void ScudettoMalignani::ringraziamenti()
{
    // Se il video finisce, vengono mostrate le label ed i GroupBox

    if((player -> position()) >= 6000)      // Inserire la durata del video in ms
    {
        // Viene eliminato il video altrimenti non è possibile visualizzare le Label
        delete player;
        delete videowidget;
        delete audio;

        // Si mostrano le Label ed i GroupBox
        ui -> groupBox_Aeronautica -> show();
        ui -> groupBox_sigBurelli -> show();
        ui -> groupBox_4EliA -> show();
        ui -> groupBox_Assistenti -> show();
        ui -> label_riconoscimenti -> show();


        // Si ridimensionano le Label ed i GroupBox

        ui -> label_riconoscimenti -> setGeometry(0,0,(this->width()),30);

        ui -> groupBox_4EliA -> setGeometry(0,0,this->width(),(this->height() / 3));
        ui -> studenti_4EliA -> setGeometry(0,0,this->width(),(this->height() / 3));

        ui -> groupBox_Aeronautica -> setGeometry(0,(this->height() / 3),this->width(),(this->height() / 3));
        ui -> studenti_Aeronautica -> setGeometry(0,0,this->width(),(this->height() / 3));

        ui -> groupBox_Assistenti -> setGeometry(0,2*(this->height() / 3),(this->width() / 2),(this->height() / 3));
        ui -> label_Assistenti -> setGeometry(0,0,(this->width() / 2),(this->height() / 3));

        ui -> groupBox_sigBurelli -> setGeometry((this->width() / 2),2*(this->height() / 3),(this->width() / 2),(this->height() / 3));
        ui -> label_sigBurelli -> setGeometry(0,0,(this->width() / 2),(this->height() / 3));
    }

}


