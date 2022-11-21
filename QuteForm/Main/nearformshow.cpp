#include "nearformshow.h"
#include "ui_nearformshow.h"

nearFormShow::nearFormShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::nearFormShow)
{
    ui->setupUi(this);
}

nearFormShow::~nearFormShow()
{
    delete ui;
}
