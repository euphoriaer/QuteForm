#ifndef HINTDIALOG_H
#define HINTDIALOG_H

#include <QDialog>
#include <QSqlRecord>
#include <QSqlTableModel>

namespace Ui {
class HintDialog;
}

class HintDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HintDialog(QWidget *parent = nullptr,QSqlTableModel*  sqlModel=nullptr,QString tableName=nullptr,int col=0);
    ~HintDialog();

private slots:
    void on_textEdit_textChanged();

private:
    Ui::HintDialog *ui;
    QSqlTableModel*  textSqlModel=nullptr;
    QSqlRecord curRecord;
    QString tipsColName;
};

#endif // HINTDIALOG_H
