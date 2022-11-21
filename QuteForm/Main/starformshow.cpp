#include "starformshow.h"
#include "ui_starformshow.h"

starFormShow::starFormShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::starFormShow)
{
    ui->setupUi(this);
}

starFormShow::~starFormShow()
{
    delete ui;
}
