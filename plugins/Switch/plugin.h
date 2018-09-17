#ifndef SWITCHPLUGIN_H
#define SWITCHPLUGIN_H

#include <QQmlExtensionPlugin>

class SwitchPlugin : public QQmlExtensionPlugin {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif
