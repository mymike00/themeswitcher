import QtQuick 2.4
import QtQuick.Layouts 1.1
import Ubuntu.Components 1.3
import Ubuntu.Components.Themes 1.3
import Switch 1.0

MainView {
   id: root
   objectName: 'mainView'
   applicationName: 'themeswitcher.mymike'
   automaticOrientation: true

   width: units.gu(45)
   height: units.gu(75)

   Page {
      id: page
      anchors.fill: parent
      property string path: "/home/phablet/.config/ubuntu-ui-toolkit/theme.ini"
      property string apptheme: theme.name
      property string fullTheme: Switch.fullTheme()
      property string shortTheme: fullTheme.slice(25)
      property string nextTheme: (shortTheme=="SuruDark"?"Ambiance":"SuruDark")

      header: PageHeader {
         id: header
         title: i18n.tr('theme-switcher')
      }

      Column {
         anchors {
            top: header.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
         }
         ListItem {
            ListItemLayout {
               title.text: "app theme:"
               subtitle.text: page.apptheme
            }
         }
         ListItem {
            ListItemLayout {
               title.text: "system theme:"
               subtitle.text: page.fullTheme
            }
         }
         ListItem {
            ListItemLayout {
               title.text: "Switch theme"
               subtitle.text: "Switch to "+page.nextTheme//+" "+Switch.nextTheme()
            }
            onClicked: {
               console.log(Switch.switchTheme(page.shortTheme, Switch.nextTheme()))
               page.fullTheme = Switch.fullTheme()
            }
         }
      }
      Component.onCompleted: console.log("tema adesso qml: "+page.shortTheme+"\ntema nuovo qml: "+page.nextTheme+"\ncpp new theme: "+Switch.nextTheme())
   }
}
// Ubuntu.Components.Themes.SuruDark
