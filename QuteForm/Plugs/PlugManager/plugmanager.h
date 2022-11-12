#ifndef PLUGMANAGER_H
#define PLUGMANAGER_H

#include <QMainWindow>
#include "PluginsInterface.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PlugManager; }
QT_END_NAMESPACE

class PlugManager : public QMainWindow
{
    Q_OBJECT

public:
    PlugManager(QWidget *parent = nullptr);
    ~PlugManager();

private:
    Ui::PlugManager *ui;
};
#endif // PLUGMANAGER_H
