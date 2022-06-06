#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "animatedsplashscreen.h"
#include <aiuto.h>               //classe Aiuto (bottone aiuto)
#include <grafico.h>             //classe Grafico (bottone grafico)
#include <impostazioni.h>        //classe Impostazioni (bottone ruotaDentata)
#include <dial.h>                //classe Dial (bottone manometro)
#include <video.h>               //classe Video (bottoni civetta, occhio, scudettoMalignani)
#include "scudettomalignani.h"
#include "manometro_dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new SerialTransreceiver();
}

MainWindow::~MainWindow()
{
    delete serial;
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    AnimatedSplashScreen* splash;
    splash = new AnimatedSplashScreen();
    splash->show();
}

void MainWindow::on_coccinella_clicked()
{

}

void MainWindow::on_grafico_clicked()
{
    Grafico *grafico;                      //dichiarazione del puntatore a un oggetto di classe Grafico
    grafico=new Grafico();                 //istanza della classe Grafico per creare l'oggetto grafico
}

void MainWindow::on_aiuto_clicked()
{
    Aiuto *aiuto;                          //dichiarazione del puntatore a un oggetto di classe Aiuto
    aiuto=new Aiuto();                     //istanza della classe Grafico per creare l'oggetto grafico
    aiuto->show();
}

void MainWindow::on_occhio_clicked()
{
    Video *video;                         //dichiarazione del puntatore a un oggetto di classe Video
    video=new Video();                    //istanza della classe Video per creare l'oggetto video
}

void MainWindow::on_scudettoMalignani_clicked()
{
    ScudettoMalignani *video;                         //dichiarazione del puntatore a un oggetto di classe Video
    video=new ScudettoMalignani();                    //istanza della classe Video per creare l'oggetto video
    video->show();

}

void MainWindow::on_manometro_clicked()
{
                    //istanza della classe Dial per creare l'oggetto dial
    ManometroDialog *manometro;
    manometro= new ManometroDialog();
    manometro-> show();
}

void MainWindow::on_civetta_clicked()
{
    Video *video;                         //dichiarazione del puntatore a un oggetto di classe Video
    video=new Video();                    //istanza della classe Video per creare l'oggetto video
}

void MainWindow::on_iconaCampo_clicked()
{

}

void MainWindow::on_ruotaDentata_clicked()
{
    Impostazioni *impostazioni;             //dichiarazione del puntatore a un oggetto di classe Impostazioni
    impostazioni=new Impostazioni();        //istanza della classe Impostaizoni per creare l'oggetto impostazioni
    impostazioni->show();

}

void MainWindow::on_mano_clicked()
{
    close();                   //chiudo la mainWindow
}
