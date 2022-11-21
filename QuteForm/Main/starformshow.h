#ifndef STARFORMSHOW_H
#define STARFORMSHOW_H

#include <QWidget>

namespace Ui {
class starFormShow;
}

class starFormShow : public QWidget
{
    Q_OBJECT

public:
    explicit starFormShow(QWidget *parent = nullptr);
    ~starFormShow();

private:
    Ui::starFormShow *ui;
};

#endif // STARFORMSHOW_H
