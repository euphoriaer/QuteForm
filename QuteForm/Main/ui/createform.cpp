#include "createform.h"
#include "createformcell.h"
#include "ui_createform.h"

#include <QButtonGroup>
#include <QComboBox>
#include <QLineEdit>


CreateForm::CreateForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateForm)
{
    ui->setupUi(this);
    ui->textEdit->setAlignment(Qt::AlignCenter);
    QVBoxLayout *vbox = new QVBoxLayout(this);
    QWidget *scroll_inner_curtain=new QWidget();

    for (int var = 0; var < 10; ++var)
    {

        QList<QString> types=QList<QString>();

        types.append(QString("int"));
        types.append(QString("float"));
        types.append(QString("string"));
        types.append(QString("table_id"));

        CreateFormCell *lisrcell=new CreateFormCell(types);
        vbox->addWidget(lisrcell->cell_widget);

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

void CreateForm::on_verticalScrollBar_valueChanged(int value)
{
    if(value==ui->verticalScrollBar->maximum())
    {
        //ui->verticalScrollBar->setMaximum(value+25);
    }
}


void CreateForm::on_pushButton_clicked()
{
    isOK=true;
    //返回
}

