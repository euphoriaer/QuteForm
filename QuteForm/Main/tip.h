#ifndef TIP_H
#define TIP_H

#include <QDialog>

namespace Ui {
class Tip;
}

class Tip : public QDialog
{
    Q_OBJECT

public:

    static void ShowMessage(QString message);

private:
    Ui::Tip *ui;

public:
    explicit Tip(QWidget *parent = nullptr);

};

#endif // TIP_H
