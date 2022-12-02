#ifndef CREATEFORM_H
#define CREATEFORM_H

#include "createformcell.h"
#include "qboxlayout.h"
#include <QWidget>
#include <TableColume.h>
#include <qdialog.h>

namespace Ui
{
class CreateForm;
}

class CreateForm : public QDialog
{
    Q_OBJECT

public:
    explicit CreateForm(QWidget *parent = nullptr);
    ~CreateForm();
    bool isOK;
    QString tableName;
    QList<CreateFormCell> cells;
    QList<TableColume> *tableColumes;
    void CreateCell();
    QVBoxLayout *vbox;
    Ui::CreateForm *ui;
private slots:

    void on_verticalScrollBar_valueChanged(int value);

    void on_pushButton_clicked();

    void on_verticalScrollBar_sliderMoved(int position);

    void on_pushButton_2_clicked();
};



#endif // CREATEFORM_H
