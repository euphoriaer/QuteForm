#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
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

private:
    Ui::MainWindow *ui;
    void    DataInit();
};
#endif // MAINWINDOW_H
