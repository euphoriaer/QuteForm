#include "formwindow.h"
#include "ui_formwindow.h"

#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

FormWindow::FormWindow(QWidget *parent,QString filePath) :
      QMainWindow(parent),
      ui(new Ui::FormWindow)
{
    ui->setupUi(this);
    qDebug()<<"DbFilePath  :"<<filePath;
    DbInit(filePath);
    ShowTabel();
}

FormWindow::~FormWindow()
{
    delete ui;
}

void FormWindow::DbInit(QString filePath)
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(filePath);

    if(db.open()==true)
    {
        qDebug()<<QStringLiteral("创建数据库成功");

    }else
    {
        qDebug()<<"创建/打开数据库成功失败";
    }


}

void FormWindow::ShowTabel()
{

    QString str=QString("SELECT * FROM buff;");

    dbModel->setQuery(str);
    ui->tableView->setModel(dbModel);

}


void FormWindow::on_actExportJson_triggered()
{
    //按下导出，导出表
    QString title="导出Json表";
    QString curPath;
    QString fliter="*.json";
    QString filePath = QFileDialog::getSaveFileName(this,title,curPath,fliter);
    if(filePath.isEmpty())
    {
        return;
    }

    QJsonArray jsonArray;
    jsonArray.append("Qt");
    jsonArray.append(5.7);
    jsonArray.append(true);


    QJsonObject jsonDic;
    jsonDic.insert("Name", "Qt");
    jsonDic.insert("From", 2002);
    jsonDic.insert("Cross Platform", true);

    // 构建 JSON 文档
//    QJsonDocument document;
//    document.setArray(jsonArray);
//    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
//    QString strJson(byteArray);

    QJsonDocument json1=QJsonDocument();
    json1.setArray(jsonArray);
    json1.setObject(jsonDic);

    auto byteArray= json1.toJson(QJsonDocument::Compact);
    QString strJson(byteArray);
    qDebug()<<"Json : "<<strJson;


    qDebug() << json1.toJson();

    //存储
    QFile file(filePath);
    file.open(QIODeviceBase::ReadWrite);
    QTextStream write(&file);
    write<< json1.toJson();//写入
    file.close();
}

