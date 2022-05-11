import QtQuick 2.0
import QtWebChannel 1.0
import QtWebEngine 1.1
Item {
    anchors.fill: parent
   id : searc_box
   QtObject{
       id: someObject
           // ID, under which this object will be known at WebEngineView side
           WebChannel.id: "backend"


           function searchbox(newText) {
               name.text = newText;
           }



   }



  WebChannel {
   id: channel
   registeredObjects: [someObject]
}
   WebEngineView {

   anchors.fill: parent
   url: "qrc:/search_box/dist/index.html"
   webChannel: channel
   }
   Text {
       anchors.centerIn: parent
       id: name

   }
}
