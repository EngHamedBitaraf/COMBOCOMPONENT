import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4

Window {
    id: window
    visible: true
    width: 1280
    height: 720




    Button_1{
        id:btn_main
        width: 200
        height: 50
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10

    }

    Combo_Box_2{
        id:combo_box_2
        anchors.left: btn_main.right
        anchors.leftMargin: 150
        anchors.top: parent.top
        anchors.topMargin: 40

    }

}
