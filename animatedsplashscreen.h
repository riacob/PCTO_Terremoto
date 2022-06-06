#ifndef ANIMATEDSPLASHSCREEN_H
#define ANIMATEDSPLASHSCREEN_H

#include <QWidget>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
#include "mainwindow.h"

namespace Ui {
class AnimatedSplashScreen;
}

class AnimatedSplashScreen : public QWidget
{
    Q_OBJECT

public:
    explicit AnimatedSplashScreen(MainWindow* mw = nullptr, QWidget *parent = nullptr);
    ~AnimatedSplashScreen();
    void setScreenSize(int width, int height);

private:
    Ui::AnimatedSplashScreen *ui;
    QMediaPlayer* mediaPlayer;
    QVideoWidget* videoWidget;
    MainWindow* mainWindow;

    //Parametri dimensione display di default, se non modificati dall'utente sono utilizzatio i seguenti
    int SCREEN_WIDTH = 1920;
    int SCREEN_HEIGHT = 1080;

private slots:
    void closeWindow();
};

#endif // ANIMATEDSPLASHSCREEN_H
