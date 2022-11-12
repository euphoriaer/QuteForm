#ifndef PLUGINCORE_H
#define PLUGINCORE_H

#include <QObject>
#include <QtPlugin>
#include "PluginsInterface.h"

//! [0]
class PluginCore : public QObject, PluginsInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "QuteForm.Plugins")
    Q_INTERFACES(PluginsInterface)

public:
    QString ShowMgrPanel(const QString &message) override;
};
//! [0]

#endif
