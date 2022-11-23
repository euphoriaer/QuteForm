#include "createform.h"
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
        QWidget *listCellGroup=new QWidget();
        QHBoxLayout *hbox=new QHBoxLayout();
        listCellGroup->setLayout(hbox);

        QLineEdit *TextEdit=new QLineEdit();
        TextEdit->setFixedHeight(25);

        QComboBox *comBox=new QComboBox();
        comBox->setFixedHeight(25);
        comBox->addItem("int");
        comBox->addItem("string");
        comBox->addItem("table id");
        comBox->addItem("float");

        hbox->addWidget(TextEdit);
        hbox->addWidget(comBox);

        vbox->addWidget(listCellGroup);
        vbox->setSpacing(0);
    }
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
        ui->verticalScrollBar->setMaximum(value+25);
    }
}

