#ifndef CREATEFORM_H
#define CREATEFORM_H

#include <QWidget>
#include <qdialog.h>

namespace Ui {
class CreateForm;
}

class CreateForm : public QDialog
{
    Q_OBJECT

public:
    explicit CreateForm(QWidget *parent = nullptr);
    ~CreateForm();

private slots:
    void on_verticalScrollBar_valueChanged(int value);

private:
    Ui::CreateForm *ui;
};

#endif // CREATEFORM_H
