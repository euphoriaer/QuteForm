#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formwindow.h"
#include "tip.h"


#include <QFileDialog>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPushButton>
#include <qpluginloader.h>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint  ); // 去掉标题栏,去掉任务栏显示
    //增加加号按钮

    QIcon* Icon=new  QIcon();
    Icon->addFile("");



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


        //打开数据表管理界面


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


/*
 * 鼠标按下操作
 * 记录当前坐标
 */
static QPoint last(0,0);        //保存坐标
const int TITLE_HEIGHT = 50;    //这里也可以使用宏定义，保存标题高度，也就是鼠标点击区域的高度
void MainWindow::mousePressEvent(QMouseEvent *event)
{

    if(event->y()<TITLE_HEIGHT)
    {
        last = event->globalPos();
    }
}
/*
 * 鼠标移动函数
 * 这里实时修改窗口的坐标
 */
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(event->y()<TITLE_HEIGHT)
    {
        int dx = event->globalX() - last.x();
        int dy = event->globalY() - last.y();
        last = event->globalPos();
        this->move(this->x()+dx,this->y()+dy);
    }
}
/*
 * 鼠标释放函数
 */
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->y()<TITLE_HEIGHT)
    {
        int dx = event->globalX() - last.x();
        int dy = event->globalY() - last.y();
        this->move(this->x()+dx,this->y()+dy);
    }
}

//初始化数据库
void MainWindow::DataInit()
{

}


void MainWindow::on_PluginsManager_clicked()
{
    //插件管理器
    auto isLoad= LoadPlugInsManager();
    if(isLoad)
    {
        qDebug("插件管理器载入成功！");
        auto reStr= pluginsMgr->ShowMgrPanel("插件测试");
        qDebug("插件测试完成",reStr.data());
    }else
    {
       auto result=QMessageBox::warning(this,"警告","插件管理器错误！");
       qDebug("错误的插件管理器！");
    }

}

bool MainWindow::LoadPlugInsManager()
{
    QDir pluginsDir(QCoreApplication::applicationDirPath());


    pluginsDir.cd("plugins");


    const QStringList entries = pluginsDir.entryList(QDir::Files);
    for (const QString &fileName : entries) {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if (plugin) {
            pluginsMgr = qobject_cast<PluginsInterface *>(plugin);
            if (pluginsMgr)
                return true;
            pluginLoader.unload();
        }
    }

    return false;
}

