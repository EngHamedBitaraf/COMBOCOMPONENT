import QtQuick 2.0
import QtWebChannel 1.0
import QtWebEngine 1.1
Item {
   id : tab_bar
   width: 245
   height: 80

   WebEngineView {
   anchors.fill: parent
   url: "qrc:/Tab_Bar/dist/index.html"
   webChannel: channel
   }
}
