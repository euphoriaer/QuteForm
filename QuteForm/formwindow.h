#ifndef FORMWINDOW_H
#define FORMWINDOW_H

#include <QMainWindow>

namespace Ui {
class FormWindow;
}

class FormWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormWindow(QWidget *parent = nullptr);
    ~FormWindow();

private:
    Ui::FormWindow *ui;
};

#endif // FORMWINDOW_H
