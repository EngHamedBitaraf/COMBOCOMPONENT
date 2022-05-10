import QtQuick 2.0
import QtWebChannel 1.0
import QtWebEngine 1.1
Item {
   id : img_slider
   width: 300
   height: 200
   WebEngineView {
   anchors.fill: parent
   url: "qrc:/Image_Slider/dist/index.html"
   webChannel: channel
             }


}
