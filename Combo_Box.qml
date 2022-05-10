import QtQuick 2.0
import QtWebChannel 1.0
import QtWebEngine 1.8
Item {
   id : combo_box
   width: 230
   height: 270

   WebEngineView {
   anchors.fill: parent
   url: "qrc:/Combo_Box/dist/index.html"
   webChannel: channel
   }
}
