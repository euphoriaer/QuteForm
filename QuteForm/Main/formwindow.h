﻿#ifndef FORMWINDOW_H
#define FORMWINDOW_H

#include <QMainWindow>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlRelationalTableModel>
#include <QtSql/QSqlTableModel>

namespace Ui {
class FormWindow;
}

class FormWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormWindow(QWidget *parent = nullptr,QSqlTableModel *dbFilePath=nullptr);

    ~FormWindow();
public :
    void    DbInit();
    void    CreateTable();
    void    QueryTable();
    void    DoubleClikTitle(int index);
    void    ShowTabel();
    QStringList DbInit(QString filePath);
    int CreateRow();
private slots:
    void on_actExportJson_triggered();

    void on_actionAddRow_triggered();

    void on_actionCol_triggered();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_RefreshAction_triggered();

    void on_verticalScrollBar_sliderMoved(int position);

    void on_verticalScrollBar_valueChanged(int value);

    void on_submitAction_triggered();

    void on_action_triggered();

private:
    Ui::FormWindow *ui;
    QSqlDatabase db;
    QSqlQueryModel*  dbModel=new  QSqlQueryModel();
    QSqlTableModel* tableModel=new  QSqlTableModel();
    QSqlRelationalTableModel* tableRelationalModel=new  QSqlRelationalTableModel();
    void    DbmodelExport();
    QString curTableName;
    int lastRecord=0;
};

#endif // FORMWINDOW_H
