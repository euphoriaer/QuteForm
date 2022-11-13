#include "plugincore.h"
#include "plugmanager.h"



QString PluginCore::ShowMgrPanel(const QString &message)
{
    PlugManager* plugManager=new PlugManager();
    plugManager->show();
    return  "我是Core";
}
