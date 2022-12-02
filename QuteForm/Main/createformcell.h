#ifndef CREATEFORMCELL_H
#define CREATEFORMCELL_H

#include "qcombobox.h"
#include "qcheckbox.h"
#include <QWidget>
#include <qlineedit.h>

class CreateFormCell
{

public:
    CreateFormCell(QList<QString> columeTypes,int cellHeight=25,QWidget *parent = nullptr);

    QString Name;
    QString Type;
    bool   IsKey;
    QLineEdit *columeName;
    QComboBox *columeType;
    QCheckBox *columeKey;
    QWidget *cell_widget;
 private:




};

#endif // CREATEFORMCELL_H
