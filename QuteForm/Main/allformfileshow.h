#ifndef ALLFORMFILESHOW_H
#define ALLFORMFILESHOW_H

#include <QWidget>

namespace Ui {
class allFormFileShow;
}

class allFormFileShow : public QWidget
{
    Q_OBJECT

public:
    explicit allFormFileShow(QWidget *parent = nullptr);
    ~allFormFileShow();
    Ui::allFormFileShow *ui;
private:

};

#endif // ALLFORMFILESHOW_H
