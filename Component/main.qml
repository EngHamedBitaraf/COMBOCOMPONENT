import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4


Item {
    id: main
    visible: true
    anchors.fill: parent
    //background image
    Image {
        id: back
        source: "qrc:/gradient-colors-background-vector-22266648.jpg"
        anchors.fill: parent
    }

//    function size_button(Width,Height){
//       btn_1.width = Width
//       btn_1.height = Height

//    }

//   function size_combo(Width,Height){
//       combo_box.width = Width
//       combo_box.height = Height
//   }

    property int btn_1_width: button_ui.get_btn_1_wth()
    property int btn_1_height: button_ui.get_btn_1_hght()
    Button_1{
        id:btn_1
        width: btn_1_width
        height: btn_1_height
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10

    }


    Combo_Box{
        id:combo_box
        anchors.left: btn_1.right
        anchors.leftMargin: 50
        anchors.top: parent.top
        anchors.topMargin: 15

    }

    Tree_view{
            width: 200
            height: 280
            anchors.left: combo_box.right
            anchors.leftMargin: 250
            anchors.top: parent.top
            anchors.topMargin: 60
}

}
