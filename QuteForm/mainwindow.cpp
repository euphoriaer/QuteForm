#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formwindow.h"
#include <QFileDialog>

#include <QPushButton>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //this->setWindowFlags(Qt::FramelessWindowHint  ); // 去掉标题栏,去掉任务栏显示
    //增加加号按钮

    QIcon* Icon=new  QIcon();
    Icon->addFile("");

    FormWindow* plusTab=new  FormWindow(this);

    //todo 将最大 最小化，关闭三个按钮加入右侧,需要加入多个按钮，目前只有退出，没有放大与缩小
    QPushButton* tabButton = new QPushButton();
    tabButton->setFlat(true);
    tabButton->setIcon(QIcon(":/Icons/System/close-fill.svg"));
    tabButton->setIconSize(QSize(48,48));

     tabButton->connect(tabButton,&QPushButton::clicked, this,&MainWindow::OnBtnClicked);
     ui->formTabWidget->setCornerWidget(tabButton);

     //添加首页


     //初始化DB


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

}


void MainWindow::on_OpenDataDBButton_clicked()
{
    //选择db 文件

    //打开、数据库
    QString title="打开数据表";
    QString curPath;
    QString fliter="*.db";
    QString filePath = QFileDialog::getOpenFileName(this,title,curPath,fliter);
    if(filePath.isEmpty())
    {
        return;
    }else
    {

        //读取数据表


        //创建form
        FormWindow* formTable=new  FormWindow(this,filePath);
        formTable->setAttribute(Qt::WA_DeleteOnClose);
        int cur=ui->formTabWidget->addTab(formTable,QString::asprintf("标签页 %d",ui->formTabWidget->count()));
        ui->formTabWidget->setCurrentIndex(cur);

    }

}


void MainWindow::on_CreateDataButton_clicked()
{
    //创建数据表
    QString title="创建数据表";
    QString curPath;
    QString fliter="*.db";
    QString filePath = QFileDialog::getSaveFileName(this,title,curPath,fliter);
    if(filePath.isEmpty())
    {
        return;
    }
    else
    {
         //Qstring 重载+ 不是更好

         QSqlDatabase  dataBase=QSqlDatabase::addDatabase("QSQLITE");
         dataBase.setDatabaseName(filePath);
         if(dataBase.open()==true)
         {
             qDebug()<<filePath.prepend("Create Db Sucess!");
         }else
         {
             qDebug()<<filePath.prepend("Create Db Fail");
         }

    }
}
//初始化数据库
void MainWindow::DataInit()
{

}

