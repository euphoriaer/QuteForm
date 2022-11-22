#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <PluginsInterface.h>
#include <QLabel>
#include <QMainWindow>
#include <QSqlDatabase>
#include <allFormFileShow.h>
#include <nearFormShow.h>
#include <starFormShow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void OnBtnClicked(void);
    ~MainWindow();

    bool LoadPlugInsManager();
    PluginsInterface* pluginsMgr;
    QStringList DbInit(QString filePath);
    QSqlDatabase db;
    QSqlDatabase* dbPtr=nullptr;
    allFormFileShow *forms;
    nearFormShow *nearForms;
    starFormShow *starForms;
private slots:
    void on_formTabWidget_tabCloseRequested(int index);

    void on_pushButton_clicked();

    void on_OpenDataDBButton_clicked();

    void on_CreateDataButton_clicked();

    //鼠标按下
    void mousePressEvent(QMouseEvent* event);
    //鼠标移动
    void mouseMoveEvent(QMouseEvent* event);
    //鼠标释放
    void mouseReleaseEvent(QMouseEvent* event);

    void on_PluginsManager_clicked();

    void on_funcList_customContextMenuRequested(const QPoint &pos);

    void on_deleteFormAction_triggered();

    void on_copyAction_triggered();

    void on_formAdd_triggered();

    void on_formList_customContextMenuRequested(const QPoint &pos);

    void on_stackedWidget_customContextMenuRequested(const QPoint &pos);

    void on_funcList_currentRowChanged(int currentRow);

    void on_openFormAction_triggered();

private:
    Ui::MainWindow *ui;
    void    DataInit();
};
#endif // MAINWINDOW_H
