import QtQuick 2.12
import QtGraphicalEffects 1.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4



Item {

    Rectangle{
        anchors.fill: parent
        id:btn
        border.color: "#1aba1a"
        border.width: 2

        MouseArea{


        anchors.fill: parent
        hoverEnabled: true


        onEntered:{
            ani_col_gre.start()
            btn_txt.color="#fff"




        }
        onExited: {
            ani_col_whi.start()
            btn_txt.color="#1aba1a"


        }


        onClicked: {


           if(btn_img.source=="qrc:/kindpng.png"){
               btn_txt.text="Less Detail"
               ani_mov_p.start()
               ani_rot.start()

               btn_img.source="qrc:/minus"
        }
           else if(btn_img.source=="qrc:/minus"){
                 btn_txt.text="More Detail"
                 btn_img.source="qrc:/kindpng.png"
                 ani_rot.start()
                 ani_mov_n.start()
        }

        }
        }
        NumberAnimation {
            id:ani_rot
            target: btn_img
            property: "rotation"
            from :0
            to:180
            duration: 300

        }

        ColorAnimation {
            id:ani_col_gre
            easing.type:Easing.InOutCirc
            target: btn
            property: "color"
            to:"#1aba1a"
            duration: 400

        }

        ColorAnimation {
            id:ani_col_whi
            easing.type:Easing.OutInCirc
            target: btn
            property: "color"
            to:"#fff"
            duration: 400

        }

     ParallelAnimation {
        id:ani_mov_p
        NumberAnimation {

            target: btn_main
            property: "anchors.leftMargin"
            from :10
            to:15
            duration: 150
}

        NumberAnimation {
            target: btn_main
            property: "anchors.topMargin"
            from :10
            to:15
            duration: 150
}


       }


     ParallelAnimation {
        id:ani_mov_n
        NumberAnimation {

            target: btn_main
            property: "anchors.leftMargin"
            from :15
            to:10
            duration: 150
}

        NumberAnimation {
            target: btn_main
            property: "anchors.topMargin"
            from :15
            to:10
            duration: 150
}


       }

            Image {
                anchors.left: parent.left

                id: btn_img
                width: 20
                height: 20
                anchors.top: parent.top
                anchors.topMargin: 15
                anchors.leftMargin: 30
                source: "qrc:/kindpng.png"


                 }

            Text {
                id: btn_txt
                color: "#1aba1a"
                text: qsTr("More Detail")
                font.pointSize: 14
                anchors.leftMargin: 75
                anchors.bottomMargin: 10
                anchors.topMargin: 12
                anchors.fill: parent
            }






    }
    DropShadow {
            anchors.fill: btn
            horizontalOffset: 5
            verticalOffset: 5
            radius: 8.0
            spread: 0.1
            samples: 17
            color: "#1aba1a"
            source: btn
        }


}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:2;anchors_height:20;anchors_width:20}
}
##^##*/
