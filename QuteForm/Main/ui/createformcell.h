#ifndef CREATEFORMCELL_H
#define CREATEFORMCELL_H

#include "qcombobox.h"
#include <QWidget>
#include <qlineedit.h>

class CreateFormCell : public QWidget
{
    Q_OBJECT
public:
    explicit CreateFormCell(QList<QString> columeTypes,int cellHeight=25,QWidget *parent = nullptr);
    CreateFormCell(QObject *temp);
    CreateFormCell();
    QLineEdit *columeName;
    QComboBox *columeType;
    QWidget *cell_widget;
signals:

};

#endif // CREATEFORMCELL_H
