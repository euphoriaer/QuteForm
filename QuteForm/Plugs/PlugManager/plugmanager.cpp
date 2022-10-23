#include "plugmanager.h"
#include "ui_plugmanager.h"

PlugManager::PlugManager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PlugManager)
{
    ui->setupUi(this);
}

PlugManager::~PlugManager()
{
    delete ui;
}

