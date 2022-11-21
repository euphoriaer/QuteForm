#include "allformfileshow.h"
#include "ui_allformfileshow.h"

allFormFileShow::allFormFileShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::allFormFileShow)
{
    ui->setupUi(this);
}

allFormFileShow::~allFormFileShow()
{
    delete ui;
}
