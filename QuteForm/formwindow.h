#ifndef FORMWINDOW_H
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
    explicit FormWindow(QWidget *parent = nullptr,QString dbFilePath=nullptr);

    ~FormWindow();
public :
    void    DbInit();
    void    CreateTable();
    void    QueryTable();
    void   ShowTabel();
    void   DbInit(QString filePath);
private slots:
    void on_actExportJson_triggered();

private:
    Ui::FormWindow *ui;
    QSqlDatabase db;
    QSqlQueryModel*  dbModel=new  QSqlQueryModel();
    QSqlTableModel* tbleModel=new  QSqlTableModel();
    QSqlRelationalTableModel* tableRelationalModel=new  QSqlRelationalTableModel();

};

#endif // FORMWINDOW_H
