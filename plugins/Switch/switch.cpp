#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <stdio.h>
#include <iostream>

#include "switch.h"
using namespace std;
Switch::Switch() {

}

QString Switch::readLine(const QString &filename, int lineNumber)
{
   QFile file(filename);
   if (!file.open(QIODevice::ReadOnly))
   return "";

   QTextStream in(&file);
   QString line;
   for (size_t i = 0; i < lineNumber; i++) {
      line = in.readLine();
   }
   file.close();
   return line;
}

QString Switch::fullTheme(void)
{
   return Switch::readLine("/home/phablet/.config/ubuntu-ui-toolkit/theme.ini", 2).mid(6);
}

QString Switch::nextTheme(void)
{
   QString actualTheme = fullTheme().mid(25);
   return ((actualTheme == "SuruDark") ? "Ambiance" : "SuruDark");

}

QString Switch::switchTheme(const QString &actualTheme, const QString &newTheme) {
   QLatin1String newThemeLatin(actualTheme.toUtf8());

   QFile file("/home/phablet/.config/ubuntu-ui-toolkit/theme.ini");
   // file.open(stderr, QIODevice::ReadWrite);
   file.open(QIODevice::ReadWrite|QIODevice::Text);
   QTextStream stream(&file);
   // QString text = stream.readAll();
   QString text = file.readAll();
   // return text;
   text.replace(actualTheme, newTheme);
   file.seek(0);
   file.write(text.toUtf8());
   file.close();
   return text;
}
