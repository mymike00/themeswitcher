#include <QtQml>
#include <QtQml/QQmlContext>

#include "plugin.h"
#include "switch.h"

void SwitchPlugin::registerTypes(const char *uri) {
    //@uri Switch
    qmlRegisterSingletonType<Switch>(uri, 1, 0, "Switch", [](QQmlEngine*, QJSEngine*) -> QObject* { return new Switch; });
}
