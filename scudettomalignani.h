#ifndef SCUDETTOMALIGNANI_H
#define SCUDETTOMALIGNANI_H

#include <QDialog>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QAudioOutput>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QKeyEvent>

namespace Ui {
class ScudettoMalignani;
}

class ScudettoMalignani : public QDialog
{
    Q_OBJECT

public:
    explicit ScudettoMalignani(QWidget *parent = nullptr);
    ~ScudettoMalignani();

private:
    Ui::ScudettoMalignani *ui;

    QMediaPlayer* player;
    QVideoWidget* videowidget;
    QAudioOutput* audio;

    void ringraziamenti();
    void keyPressEvent(QKeyEvent* event);
};

#endif // SCUDETTOMALIGNANI_H
