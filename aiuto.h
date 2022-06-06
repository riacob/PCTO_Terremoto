#ifndef AIUTO_H
#define AIUTO_H

#include <QDialog>
#include <QObject>
#include <QAbstractButton>

namespace Ui {
class Aiuto;
}

class Aiuto : public QDialog
{
    Q_OBJECT

public:
    explicit Aiuto(QWidget *parent = nullptr);
    ~Aiuto();

private slots:
    void on_Close_clicked();

private:
    Ui::Aiuto *ui;
};

#endif // TASTO_AIUTO_H
