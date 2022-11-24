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
    bool isOK;
    QString tableName;
    QList<QMap<QString,QString>> tableColumes;
private slots:
    void on_verticalScrollBar_valueChanged(int value);

    void on_pushButton_clicked();

private:
    Ui::CreateForm *ui;
};

#endif // CREATEFORM_H
