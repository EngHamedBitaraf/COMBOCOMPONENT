import QtQuick 2.0
import QtWebEngine 1.8
Item {
   width: 200
   height: 100
      WebEngineView {
      anchors.fill: parent
      url: "qrc:/Btn_More_Detail/dist/index.html"
      webChannel: channel
            }
}
