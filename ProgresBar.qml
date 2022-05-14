import QtQuick 2.0
import QtWebChannel 1.0
import QtWebEngine 1.1


Item {
   property string myurl
   visible: false
   enabled: false
   id : progress_bar
   width: 200
   height: 70

   WebEngineView {
       id:wb
       anchors.fill: parent
       url: myurl
       webChannel: channel
      }


}
