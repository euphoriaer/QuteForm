#include "formwindow.h"
#include "ui_formwindow.h"

#include <QFileDialog>
#include <QFontComboBox>
#include <QHeaderView>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QList>
#include <QTableView>
#include <hintdialog.h>


FormWindow::FormWindow(QWidget *parent,QString filePath) :
      QMainWindow(parent),
      ui(new Ui::FormWindow)
{
    ui->setupUi(this);
    qDebug()<<"DbFilePath  :"<<filePath;
    DbInit(filePath);

    //todo 选择打开哪个表
    curTableName="buff";
    ShowTabel(curTableName);

    //设置表头事件，点击双击表头弹出提示
    auto tableHand= ui->tableView->horizontalHeader();
    tableHand->connect(tableHand,&QHeaderView::sectionDoubleClicked ,this,&FormWindow::DoubleClikTitle);

}



void FormWindow::DoubleClikTitle(int index)
{
    qDebug()<<"Enter titel:   "<< index;
    //弹出提示  提示存在数据库里   需自定义弹出控件，且Setmodel
    HintDialog* dialog=new HintDialog(this ,tableModel,curTableName,index);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    auto flags=dialog->windowFlags();
    dialog->setWindowFlags(flags|Qt::WindowStaysOnTopHint);
    dialog->show();
}

QStringList FormWindow::DbInit(QString filePath)
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(filePath);

    if(db.open()==true)
    {
        qDebug()<<QStringLiteral("创建/打开数据库成功");
        return  db.tables();
    }else
    {
        qDebug()<<"创建/打开数据库成功失败";
    }
}

void FormWindow::ShowTabel(QString tableName)
{

    //dbModel
    //   QString str=QString("SELECT * FROM buff;");
    //    dbModel->setQuery(str);
    //    ui->tableView->setModel(dbModel);

    tableModel = new  QSqlTableModel;
    tableModel->setTable(tableName);
    tableModel->select();

    QTableView *view =ui->tableView;
    view->setModel(tableModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    view->show();

}


void FormWindow::on_actExportJson_triggered()
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


void FormWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    qDebug()<<"Enter Press  :"<<index.data().toString();
}
FormWindow::~FormWindow()
{
    delete ui;
}


void FormWindow::on_RefreshAction_triggered()
{
    //刷新表格数据  多人协作模块需要，当使用远程数据库时

   //刷新数据表格  Git多人协作时需要，刷新本地Db文件，拉取重读
    tableModel->select();


}

