
import QtQuick 2.12
import QtQuick.Window 2.12
import abbas 1.1
import QtWebChannel 1.0
import QtWebEngine 1.8

Window{

    visible: true
    width: 800
    height: 600
    title: qsTr("qml_window")



    Text {
        id: text


        anchors.bottom: x.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 30

        text: "This text is created with QML, the item below is a QWidget that loaded in qml window:"
    }


    QtObject{
        id: someObject
        WebChannel.id: "backend"



        function visibilityx(show){
            console.log(show)
            if (show===true){

                x.visible=true
                x.enabled=true

            }
            else {
                x.visible=false
                x.enabled=false


            }


      }
}

    WebChannel {
       id: channel
       registeredObjects: [someObject]
}



    Item {
       id:wg_btn
       width: 210
       height: 60

       anchors.centerIn: parent

       WebEngineView {
       anchors.fill: parent
       url: "qrc:/Btn_More_Detail/dist/index.html"
       webChannel: channel
                }
    }




    Item {
        id:x
        width: 180
        height: 25

        enabled: false
        visible: false
        anchors.bottom: wg_btn.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 30




        WidgetItem {
            id:w_i
            anchors.fill: parent
            anchors.horizontalCenter: parent.horizontalCenter

        }
    }

    Shortcut {
        sequence: "Ctrl+q"
        onActivated: Qt.quit()
    }
}
