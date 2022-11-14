#include "tip.h"
#include "ui_tip.h"

Tip::Tip(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Tip)
{
    ui->setupUi(this);
}



void Tip::ShowMessage(QString message)
{
    Tip* tip=new Tip();
    tip->show();
    tip->ui->Message->append(message);

}
