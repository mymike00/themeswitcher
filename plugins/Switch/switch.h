#ifndef SWITCH_H
#define SWITCH_H

#include <QObject>

class Switch: public QObject {
    Q_OBJECT

public:
    Switch();
    ~Switch() = default;

    Q_INVOKABLE QString readLine(const QString &filename, int lineNumber);
    Q_INVOKABLE QString fullTheme(void);
    Q_INVOKABLE QString nextTheme(void);
    Q_INVOKABLE QString switchTheme(const QString &actualTheme, const QString &newTheme);

};

#endif
