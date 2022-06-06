#ifndef COM_H
#define COM_H

#include <QDialog>

namespace Ui {
class COM;
}

class COM : public QDialog
{
    Q_OBJECT

public:
    explicit COM(QWidget *parent = nullptr);
    ~COM();

private:
    Ui::COM *ui;
};

#endif // COM_H
