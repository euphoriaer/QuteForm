#include "formwindow.h"
#include "ui_formwindow.h"

#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QList>

FormWindow::FormWindow(QWidget *parent,QString filePath) :
      QMainWindow(parent),
      ui(new Ui::FormWindow)
{
    ui->setupUi(this);
    qDebug()<<"DbFilePath  :"<<filePath;
    DbInit(filePath);

    //todo 选择打开哪个表

    ShowTabel();
}

FormWindow::~FormWindow()
{
    delete ui;
}

QStringList FormWindow::DbInit(QString filePath)
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(filePath);

    if(db.open()==true)
    {
        qDebug()<<QStringLiteral("创建数据库成功");
        return  db.tables();
    }else
    {
        qDebug()<<"创建/打开数据库成功失败";
    }
}

void FormWindow::ShowTabel()
{

    //dbModel
    //   QString str=QString("SELECT * FROM buff;");
    //    dbModel->setQuery(str);
    //    ui->tableView->setModel(dbModel);

    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("buff");
    model->select();

    QTableView *view =ui->tableView;
    view->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    view->show();
}


void FormWindow::on_actExportJson_triggered()
{
    //DbmodelExport();
    TableModelExport();


}

void FormWindow::TableModelExport()
{

}

void FormWindow::DbmodelExport()
{
    //按下导出，导出表  //error 导出可被插件重写
    QString title="导出Json表";
    QString curPath;
    QString fliter="*.json";
    QString filePath = QFileDialog::getSaveFileName(this,title,curPath,fliter);
    if(filePath.isEmpty())
    {
        return;
    }


    QList<QString> titles;
    QJsonObject jObject;
    for (int col = 0; col <dbModel->columnCount(); ++col)
    {
        auto title=dbModel->headerData(col,Qt::Orientation::Horizontal).toString();
        titles.append(title);
    }

    for (int row = 0; row < dbModel->rowCount();row ++)
    {
        //todo 需要考虑是否导出数组类型
        QJsonObject curColDic;
        auto rowKey=dbModel->data(dbModel->index(row,0));//每一行一条数据， k,v

        for (int col = 1; col <dbModel->columnCount();col ++)
        {
            auto  key=titles[col];
            auto  value=dbModel->data(dbModel->index(row,col));
            curColDic.insert(key,value.toString());//每次插入向前
        }
        jObject.insert(rowKey.toString(),curColDic);
    }

    QJsonDocument json=QJsonDocument();
    json.setObject(jObject);
    qDebug()<<"Json : "<< json.toJson();
    //存储
    QFile file(filePath);
    file.open(QIODeviceBase::ReadWrite);
    QTextStream write(&file);
    write<< json.toJson();//写入
    file.close();

}


void FormWindow::on_actionAddRow_triggered()
{
    //直接增加一行空数据，View 填写即可
}


void FormWindow::on_actionCol_triggered()
{
    //增加列，弹出对话框，列名


}

