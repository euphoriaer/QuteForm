#ifndef CREATEFORMCELL_H
#define CREATEFORMCELL_H

#include "qcombobox.h"
#include <QWidget>
#include <qlineedit.h>

class CreateFormCell
{

public:
    CreateFormCell(QList<QString> columeTypes,int cellHeight=25,QWidget *parent = nullptr);

    QString Name;
    QString Type;
    QLineEdit *columeName;
    QComboBox *columeType;
    QWidget *cell_widget;
 private:




};

#endif // CREATEFORMCELL_H
