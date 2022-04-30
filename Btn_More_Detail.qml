import QtQuick 2.0
import QtQuick.Window 2.12
import QtQuick.Controls 1.4
import QtWebChannel 1.0
import QtWebEngine 1.1

Item {
    visible: true
    width: 640
    height: 480
    QtObject{
        id: someObject

            // ID, under which this object will be known at WebEngineView side
            WebChannel.id: "backend"

            function changiz(){
               return txtfld.time
            }


            property int send_Time: changiz()


            function changeText(newText) {
                txt.text = newText;


            }
    }
    Rectangle {
       id : btn_detail
       width: 200
       height: 70
       x:0
       y:30


      WebEngineView {
      anchors.fill: parent
      url: "qrc:/Btn_More_Detail/dist/index.html"
      webChannel: channel
            }



}

   WebChannel {
    id: channel
    registeredObjects: [someObject]
}
   Rectangle{
        width: 100
        height: 30
        x:45
        y:110
        border.width: 1
        border.color: "blue"
        radius: 10
    Text {
        id: txt
        anchors.centerIn: parent
        text: "none"
}
}
    TextField {
       id : txtfld

       horizontalAlignment: TextInput.AlignHCenter
       validator: IntValidator {bottom: 1000; top: 200000;}
       width: 200
       height: 30
       placeholderText: "زمان اجرا را وارد کنید: m/s"
       property int time:text*1



       x: 228
       y: 110

               }
    Rectangle {


       visible: abbas()
       id : progress_bar
       width: 200
       height: 70
       function abbas (){

         if  (txtfld.time>=1000 && txtfld.time<=20000){
         return true}
         else{
         return false}
       }

       x:230
       y:20

       WebEngineView {
       anchors.fill: parent
       url: "qrc:/Progress_Bar/dist/index.html"
       webChannel: channel
                 }


   }

   }



