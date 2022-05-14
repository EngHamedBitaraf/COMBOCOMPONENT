import QtQuick 2.0
import QtQuick.Window 2.12
import QtQuick.Controls 1.4
import QtWebChannel 1.0
import QtWebEngine 1.1
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
Item {

    visible: true
    width: 1280
    height: 720

    QtObject{
        id: someObject
            // ID, under which this object will be known at WebEngineView side
            WebChannel.id: "backend"


            property int send_Time


            function changeText(newText) {
                txt.text = newText;
            }
            function change_Text_combo(new_combo_Text) {
               combo_txt.text = new_combo_Text;


           }

            function change_Text_tab(new_tab_Text) {
                            tab_bar_txt.text = new_tab_Text;


                        }

           function change_Text_tree_v(new_tree_Text) {
                tree_v_txt.text = new_tree_Text;


           }

           function change_color_switch(color){
               if (combo_rec.color=="#de6262"){
                   combo_rec.color="white"
                 }
               else{
               combo_rec.color=color
                }
           }


    }



   WebChannel {
    id: channel
    registeredObjects: [someObject]
}
 GridLayout{
    anchors.fill: parent
    rows: 4
    columns: 4
    columnSpacing: 1
    rowSpacing: 1

    Button_detail{

       Layout.row: 0
       Layout.column: 0


    }
   Rectangle{
       Layout.row: 1
       Layout.column: 0
       Layout.preferredHeight: 30
       Layout.preferredWidth: 130
       Layout.leftMargin: 30
       Layout.bottomMargin: 225



        width: 130
        height: 30
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
        Layout.row: 1
        Layout.column: 2

        Layout.preferredWidth: 200
        Layout.preferredHeight: 30
        Layout.leftMargin: 150
        Layout.topMargin: -240
        id : txtfld

        horizontalAlignment: TextInput.AlignHCenter
        validator: IntValidator {bottom: 1000; top: 200000;}
        width: 200
        height: 30
        placeholderText: "زمان اجرا را وارد کنید: m/s"
        property int time:text*1

    }


    Button{
    id:set_time_btn
    property bool clickeddd: false
    Layout.row: 1
    Layout.column: 2
    Layout.preferredWidth: 70
    Layout.preferredHeight: 25
    Layout.leftMargin: 210
    Layout.topMargin: -140
    //color: "light blue"
    //border.width: 2
    //border.color: "black"
    text: "Set"
    onClicked: {

        function abbas (){
          if  (txtfld.time>=1000 && txtfld.time<=20000){
                someObject.send_Time=txtfld.time
                pg.visible =true
                pg.enabled =true
                pg.myurl = "qrc:/Progress_Bar/dist/index.html"
          }

        }
        abbas()





    }


}

    ProgresBar{
        id:pg
        Layout.leftMargin: 150
        Layout.topMargin: -400
        Layout.row: 1
        Layout.column: 2

    }

    Combo_Box{
        Layout.leftMargin: -150
        Layout.topMargin: -185
        Layout.row: 1
        Layout.column: 2
    }
    Rectangle{
        id:combo_rec
        Layout.row: 2
        Layout.column: 2
        Layout.leftMargin: -130
        Layout.topMargin: -280
         width: 150
         height: 30
         border.width: 1
         border.color: "black"
         radius: 10
     Text {
         id: combo_txt
         anchors.centerIn: parent
         text: "none"
     }
 }



    Tab_Bar{
        Layout.rightMargin: -300
        Layout.topMargin: -360
        id: tab_Bar
        Layout.row: 1
        Layout.column: 3
    }

        Rectangle{
            Layout.leftMargin: 70
            Layout.topMargin: -450
            Layout.row: 2
            Layout.column: 3
             width: 150
             height: 30

             border.width: 1
             border.color: "blue"
             radius: 10
         Text {
             id: tab_bar_txt
             anchors.centerIn: parent
             text: "Browse"
         }
     }

    Tree_View {
        Layout.rightMargin: -200
        Layout.topMargin: -200
        Layout.row:3
        Layout.column:3
    }

    Rectangle{
        Layout.leftMargin: 75
        Layout.bottomMargin: -140
        Layout.row: 3
        Layout.column: 3
         width: 150
         height: 30

         border.width: 1
         border.color: "blue"
         radius: 10
     Text {
         id: tree_v_txt
         anchors.centerIn: parent
         text: "Please_Choose"
     }
 }
    PersianCalendar{Layout.row: 3
        Layout.column: 2}




    Image_slider{
        Layout.row: 3
        Layout.column: 0

    }



 }


}



