#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formwindow.h"

#include <QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint  ); // 去掉标题栏,去掉任务栏显示
    //增加加号按钮

    QIcon* Icon=new  QIcon();
    Icon->addFile("");

    FormWindow* plusTab=new  FormWindow(this);

    //todo 将最大 最小化，关闭三个按钮加入右侧,需要加入多个按钮，目前只有退出，没有放大与缩小
    QPushButton* tabButton = new QPushButton();
    tabButton->setFlat(true);
    tabButton->setIcon(QIcon(":/Icons/System/close-fill.svg"));
    tabButton->setIconSize(QSize(48,48));
//    QPushButton* tabButton2 = new QPushButton();
//    tabButton2->setFlat(true);
//    tabButton2->setIcon(QIcon(":/Icons/Health/dossier-fill.svg"));

//    QPushButton* tabButton3 = new QPushButton();
//    tabButton3->setFlat(true);
//    tabButton3->setIcon(QIcon(":/Icons/Health/dossier-fill.svg"));

     tabButton->connect(tabButton,&QPushButton::clicked, this,&MainWindow::OnBtnClicked);
     ui->formTabWidget->setCornerWidget(tabButton);

     //添加首页


}
// 绑定的响应函数
void MainWindow::OnBtnClicked()
{
    QApplication* app;
    app->quit();
}



MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_formTabWidget_tabCloseRequested(int index)
{
    if(index<0)
    {
        return;
    }
    QWidget* tab=ui->formTabWidget->widget(index);
    tab->close();
}


void MainWindow::on_pushButton_clicked()
{
    //导出Json 页面
    FormWindow* formTable=new  FormWindow(this);
    formTable->setAttribute(Qt::WA_DeleteOnClose);
    int cur=ui->formTabWidget->addTab(formTable,QString::asprintf("标签页 %d",ui->formTabWidget->count()));
     ui->formTabWidget->setCurrentIndex(cur);
}

