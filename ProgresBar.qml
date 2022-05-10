import QtQuick 2.0
import QtWebChannel 1.0
import QtWebEngine 1.1

Item {
    function abbas (){
      if  (txtfld.time>=1000 && txtfld.time<=20000){
      return true}
      else{
      return false}
    }
   visible: abbas()
   id : progress_bar
   width: 200
   height: 70

   WebEngineView {
       anchors.fill: parent
       url: "qrc:/Progress_Bar/dist/index.html"
       webChannel: channel
      }


}
