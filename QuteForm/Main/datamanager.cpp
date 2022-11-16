#include "datamanager.h"
#include "ui_datamanager.h"

DataManager::DataManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataManager)
{
    ui->setupUi(this);
}

DataManager::~DataManager()
{
    delete ui;
}
