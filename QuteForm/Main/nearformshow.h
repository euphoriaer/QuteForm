#ifndef NEARFORMSHOW_H
#define NEARFORMSHOW_H

#include <QWidget>

namespace Ui {
class nearFormShow;
}

class nearFormShow : public QWidget
{
    Q_OBJECT

public:
    explicit nearFormShow(QWidget *parent = nullptr);
    ~nearFormShow();

private:
    Ui::nearFormShow *ui;
};

#endif // NEARFORMSHOW_H
