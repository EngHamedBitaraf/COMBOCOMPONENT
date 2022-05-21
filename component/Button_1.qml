import QtQuick 2.12
import QtGraphicalEffects 1.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4



Item {

    property string btn_1_bckg_colr : "white"

    property int btn_1_border_width
    property string btn_1_border_colr

    property string btn_1_txt
    property string btn_1_txt_colr
    property int btn_1_txt_size

    property int btn_1_shadow_radius
    property int btn_1_shadow_sample
    property string btn_1_shadow_color

//    function btn_1_bck_g_colr(Color){
//        btn.color = Color
//    }

//    function btn_1_border(bord_wth,bord_clor){
//        btn.border.width = bord_wth
//        btn.border.color = bord_colr
//    }

//    function btn_1_txt(txt,txt_colr,txt_size){
//        btn_txt.text = txt
//        btn_txt.color = txt_colr
//        btn_txt.font.pixelSize = txt_size
//    }

//    function btn_1_shadow(radius,sample,color){
//        shadow.radius = radius
//        shadow.samples = sample
//        shadow.color = color

//    }

    Rectangle{
        anchors.fill: parent
        id:btn
        border.color: "#1aba1a"
        border.width: 2
        color: btn_1_bckg_colr

        Image {
            id: btn_img
            width: 20
            height: 20
            anchors.right: btn_txt.left
            anchors.rightMargin: 12
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/kindpng.png"


        }

        Text {
            id: btn_txt
            color: "#1aba1a"
            text: qsTr("More Detail")
            font.pixelSize: 20
            anchors.centerIn: parent
        }


    }
    DropShadow {
        id:shadow
        anchors.fill: btn
        horizontalOffset: 5
        verticalOffset: 5
        radius: 8.0
        spread: 0.1
        samples: 17
        color: "#1aba1a"
        source: btn
    }


    MouseArea{
        anchors.fill: parent
        hoverEnabled: true

        onEntered:{
            ani_col_gre.start()
            btn_txt.color="#fff"

            button_wid.onHover_In()

        }
        onExited: {
            ani_col_whi.start()
            btn_txt.color="#1aba1a"

            button_wid.onHover_Out()

        }

        onClicked: {


            if(btn_img.source=="qrc:/kindpng.png"){
                btn_txt.text="Less Detail"
                ani_mov_p.start()
                ani_rot.start()
                btn_img.source="qrc:/minus"

                button_wid.onClick_More()
            }
            else if(btn_img.source=="qrc:/minus"){
                btn_txt.text="More Detail"
                btn_img.source="qrc:/kindpng.png"
                ani_rot.start()
                ani_mov_n.start()

                button_wid.onClick_Less()
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

            target: btn_1
            property: "anchors.leftMargin"
            from :10
            to:15
            duration: 150
        }

        NumberAnimation {
            target: btn_1
            property: "anchors.topMargin"
            from :10
            to:15
            duration: 150
        }


    }


    ParallelAnimation {
        id:ani_mov_n
        NumberAnimation {

            target: btn_1
            property: "anchors.leftMargin"
            from :15
            to:10
            duration: 150
        }

        NumberAnimation {
            target: btn_1
            property: "anchors.topMargin"
            from :15
            to:10
            duration: 150
        }


    }



}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:2;anchors_height:20;anchors_width:20}
}
##^##*/
