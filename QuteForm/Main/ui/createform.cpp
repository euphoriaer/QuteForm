#include "createform.h"
#include "ui_createform.h"


CreateForm::CreateForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateForm)
{
    ui->setupUi(this);
    ui->textEdit->setAlignment(Qt::AlignCenter);
}

CreateForm::~CreateForm()
{
    delete ui;
}
