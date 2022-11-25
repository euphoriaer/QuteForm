#include "createform.h"
#include "createformcell.h"
#include "ui_createform.h"

#include <QButtonGroup>
#include <QComboBox>
#include <QLineEdit>
#include <QMap>


CreateForm::CreateForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateForm)
{
    ui->setupUi(this);
    ui->textEdit->setAlignment(Qt::AlignCenter);
    vbox = new QVBoxLayout(this);
    QWidget *scroll_inner_curtain=new QWidget();

    for (int var = 0; var < 10; ++var)
    {

        CreateCell();

    }

    vbox->setSpacing(0);
    scroll_inner_curtain->setLayout(vbox);
    ui->scrollArea->setWidget(scroll_inner_curtain);
    ui->scrollArea->setVerticalScrollBar(ui->verticalScrollBar);
    //ui->listView->addScrollBarWidget(ui->verticalScrollBar,Qt::AlignTop);
}



CreateForm::~CreateForm()
{
    delete ui;
}

void CreateForm::CreateCell()
{
    QList<QString> types=QList<QString>();

    types.append(QString("int"));
    types.append(QString("float"));
    types.append(QString("string"));
    types.append(QString("table_id"));

    CreateFormCell *lisrcell=new CreateFormCell(types,25,vbox->widget());

    vbox->addWidget(lisrcell->cell_widget);

}

void CreateForm::on_verticalScrollBar_valueChanged(int value)
{
    if(value==ui->verticalScrollBar->maximum())
    {
        CreateCell();
    }
}


void CreateForm::on_pushButton_clicked()
{
    isOK=false;
    //返回
}


void CreateForm::on_verticalScrollBar_sliderMoved(int position)
{


}


void CreateForm::on_pushButton_2_clicked()
{
    isOK=true;

//    tableColumes=new QMap<QString,QString>();
//    auto count=vbox->count();
//    for (int var = 0; var < count; ++var)
//    {
//        auto item = vbox->itemAt(var);
//        if (item && item->widget())
//        {
//            CreateFormCell cell= (CreateFormCell)item->widget();
//            auto cellName=cell.columeName->text();
//            if(cellName.isEmpty()||cellName.isNull())
//            {
//                continue;
//            }
//            auto cellType=cell.columeType->currentText();
//            tableColumes->insert(cellName,cellType);
//        }

//    }
    this->close();
}

