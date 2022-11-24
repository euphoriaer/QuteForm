#include "createformcell.h"
#include "qboxlayout.h"

#include <qtextedit.h>

CreateFormCell::CreateFormCell(QList<QString> columeTypes,int cellHeight,QWidget *parent)
    : QWidget{parent}
{
    QWidget *listGroup=new QWidget(parent);

    QHBoxLayout *cellBox=new QHBoxLayout();

    columeName=new QLineEdit();
    columeType=new QComboBox();
    columeName->setFixedHeight(cellHeight);
    columeType->setFixedHeight(cellHeight);

    cellBox->addWidget(columeName);
    cellBox->addWidget(columeType);

    for (int var = 0; var < columeTypes.count(); ++var)
    {
        columeType->addItem(columeTypes[var]);

    }
    cell_widget=listGroup;
    listGroup->setLayout(cellBox);
}
