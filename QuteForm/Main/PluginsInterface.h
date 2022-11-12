#ifndef PLUGINSINTERFACE_H
#define PLUGINSINTERFACE_H


#include <QObject>
#include <QString>

//! [0]
class PluginsInterface
{
public:
    virtual ~PluginsInterface() = default;
    virtual QString ShowMgrPanel(const QString &message) = 0;
};


QT_BEGIN_NAMESPACE

#define PluginsInterface_iid "QuteForm.Plugins"

Q_DECLARE_INTERFACE(PluginsInterface, PluginsInterface_iid)
QT_END_NAMESPACE


#endif // PLUGINSINTERFACE_H
