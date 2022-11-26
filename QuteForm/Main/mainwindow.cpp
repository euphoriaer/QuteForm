#include "mainwindow.h"
#include "allformfileshow.h"
#include "ui_allformfileshow.h"
#include "ui_mainwindow.h"
#include "formwindow.h"
#include "tip.h"


#include <QFileDialog>
#include <QList>
#include <QMenu>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPushButton>
#include <QSqlQuery>
#include <qpluginloader.h>

#include <ui/createform.h>



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

    //首页
    ui->funcList->insertItem(0,tr("全部"));
    ui->funcList->insertItem(1,tr("最近"));
    ui->funcList->insertItem(2,tr("星标"));

    forms=new allFormFileShow(this);
    nearForms=new nearFormShow(this);
    starForms=new starFormShow(this);
    for(int i = ui->stackedWidget->count(); i >= 0; i--)
    {
        QWidget* widget = ui->stackedWidget->widget(i);
        ui->stackedWidget->removeWidget(widget);
        widget->deleteLater();
    }

    ui->stackedWidget->addWidget(forms);
    ui->stackedWidget->addWidget(nearForms);
    ui->stackedWidget->addWidget(starForms);
    //ui->funcList->insertItem(2,ui->testAction);

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

QStringList MainWindow::DbInit(QString filePath)
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(filePath);

    if(db.open()==false)
    {
        qDebug()<<"创建/打开数据库成功失败";
        return QStringList();
    }
    qDebug()<<QStringLiteral("创建/打开数据库成功");
    dbPtr=&db;
    auto tables=db.tables();
    return  tables;
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
        //查询数据表所有表格，并显示在list区域
        auto tableList=DbInit(filePath);
        QList<QString> list=QList<QString>();
        QList<QAction*> tableListAction=QList<QAction*>();
        for (int var = 0; var < tableList.count(); ++var)
        {
            auto curTableName=tableList[var];
            QAction *cellAction=new QAction(curTableName,this);
            tableListAction.append(cellAction);
            forms->ui->formList->addItem(curTableName);
        }
    }

}


void MainWindow::on_CreateDataButton_clicked()
{
    //创建数据表
    QString title="创建数据库";
    QString curPath;
    QString fliter="*.db";
    QString filePath = QFileDialog::getSaveFileName(this,title,curPath,fliter);
    if(filePath.isEmpty())
    {
        return;
    }
    else
    {
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


void MainWindow::on_deleteFormAction_triggered()
{

}

void MainWindow::on_copyAction_triggered()
{

}


void MainWindow::on_formAdd_triggered()
{


    if(dbPtr==nullptr)
    {
        auto result=QMessageBox::warning(this,"错误","没有打开数据库");
    }else
    {

        //打开表格创建界面 ，表名，列名，类型 int string float enum TableID 。。。
        QSqlQuery query;
        CreateForm *createForm=new CreateForm(this);
        createForm->show();
        createForm->exec();
        if(!createForm->isOK)
        {
            //点击取消
            return;
        }

        QString queryStr="";
        QString tableName=createForm->tableName;
        queryStr+="create table "+tableName+" (";

        int i=0;
        foreach (auto cell, createForm->tableColumes->keys())
        {
            auto key=cell;
            auto Type=createForm->tableColumes->value(cell);

            if(i==0)//默认第一列为主键
            {
                queryStr+=key+" "+Type+" primary key,";

            }else if(i==createForm->tableColumes->keys().count()-1)
            {
                queryStr+=key+" "+Type;
            }
            else
            {
                queryStr+=key+" "+Type+",";
            }
            i++;
        }

        queryStr+=")";

        bool success=  query.exec(queryStr);

        if(!success)
        {
            qDebug("创建表失败");
        }

        QSqlTableModel *model=new QSqlTableModel(this,db);
        model->setTable(tableName);

        //创建form
        FormWindow* formTable=new  FormWindow(this,model);
        formTable->setAttribute(Qt::WA_DeleteOnClose);
        int cur=ui->formTabWidget->addTab(formTable,QString::asprintf("标签页 %d",ui->formTabWidget->count()));
        ui->formTabWidget->setCurrentIndex(cur);
    }

}


void MainWindow::on_funcList_customContextMenuRequested(const QPoint &pos)
{

}

void MainWindow::on_formList_customContextMenuRequested(const QPoint &pos)
{

}


void MainWindow::on_stackedWidget_customContextMenuRequested(const QPoint &pos)
{
    QMenu *menu = new QMenu();

    QAction *testAction = new QAction("右键测试", this);
    menu->addAction(testAction);
    menu->addAction(ui->openFormAction);
    menu->addAction(ui->formAdd);
    menu->addAction(ui->copyAction);
    menu->addAction(ui->deleteFormAction);
    menu->exec(QCursor::pos());
}


void MainWindow::on_funcList_currentRowChanged(int currentRow)
{
    ui->stackedWidget->setCurrentIndex(currentRow);
}


void MainWindow::on_openFormAction_triggered()
{
    if(forms->ui->formList->currentItem()==nullptr)
    {
        return;
    }
    QString tableName=forms->ui->formList->currentItem()->text();
    QSqlTableModel *model=new QSqlTableModel(this,db);
    model->setTable(tableName);

    //创建form打开
    FormWindow* formTable=new  FormWindow(this,model);
    formTable->setAttribute(Qt::WA_DeleteOnClose);
    int cur=ui->formTabWidget->addTab(formTable,tableName);
    ui->formTabWidget->setCurrentIndex(cur);
}

