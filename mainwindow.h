#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <serialtransreceiver.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:


    void on_actionOpen_triggered(); //mostra lo splashscreen

    void on_coccinella_clicked();  //dichiarazione del metodo richiamato quando il bottone "coccinella" viene cliccata

    void on_grafico_clicked();     //dichiarazione del metodo richiamato quando il bottone "grafico" viene cliccata

    void on_aiuto_clicked();       //dichiarazione del metodo richiamato quando il bottone "aiuto" viene cliccata

    void on_occhio_clicked();      //dichiarazione del metodo richiamato quando il bottone "occhio" viene cliccata

    void on_scudettoMalignani_clicked(); //dichiarazione del metodo richiamato quando il bottone "scudetto" viene cliccata

    void on_manometro_clicked();   //dichiarazione del metodo richiamato quando il bottone "manometro" viene cliccata

    void on_civetta_clicked();     //dichiarazione del metodo richiamato quando il bottone "civetta" viene cliccata

    void on_iconaCampo_clicked();  //dichiarazione del metodo richiamato quando il bottone "campo" viene cliccata

    void on_ruotaDentata_clicked();//dichiarazione del metodo richiamato quando il bottone "ruota dentata" viene cliccata

    void on_mano_clicked();        //dichiarazione del metodo richiamato quando il bottone "mano" viene cliccata

private:
    Ui::MainWindow *ui;
    SerialTransreceiver *serial;
};
#endif // MAINWINDOW_H

//per inserire l'immagine nella mainWindow ho aggiunto una label
//delle dimensioni della finestra e l'ho riempita con l'immagine
//poi ho aggiunto i bottoni (QPressButton) e li ho resi trasparenti
//cambiando le styleSheet (background-color:rgba(255,255,255,0) li rende trasparenti)
