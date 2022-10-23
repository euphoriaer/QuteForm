#include "hintdialog.h"
#include "ui_hintdialog.h"
#include "QSqlRecord"
#include <QModelIndex>

HintDialog::HintDialog(QWidget *parent,QSqlTableModel* sqlModel,QString tableName,int col) :
      QDialog(parent),
      ui(new Ui::HintDialog)
{
    ui->setupUi(this);
    textSqlModel=new  QSqlTableModel;
    QString tableTipName=tableName+"_Tips";
    textSqlModel->setTable(tableTipName);
    //todo  读取数据库所有表，如果不存在表，创建表头提示表
    {
         textSqlModel->select();
    }

    tipsColName= textSqlModel->headerData(col,Qt::Orientation::Horizontal).toString();

    //auto test= textSqlModel->record();
    curRecord=textSqlModel->record(0);
   auto tipsContent =curRecord.value(tipsColName).toString();
   ui->textEdit->append(tipsContent);
   ui->tableView->setModel(textSqlModel);
   ui->tableView->show();


}

HintDialog::~HintDialog()
{
    delete ui;
}

void HintDialog::on_textEdit_textChanged()
{
    //内容改变，同步到数据库
    qDebug()<<ui->textEdit->toPlainText();
    curRecord.setValue(tipsColName,ui->textEdit->toPlainText());
    textSqlModel->setRecord(0,curRecord);
    textSqlModel->submitAll();
}

