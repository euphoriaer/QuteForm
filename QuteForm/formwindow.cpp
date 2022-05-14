#include "formwindow.h"
#include "ui_formwindow.h"

FormWindow::FormWindow(QWidget *parent) :
      QMainWindow(parent),
      ui(new Ui::FormWindow)
{
    ui->setupUi(this);
}

FormWindow::~FormWindow()
{
    delete ui;
}
