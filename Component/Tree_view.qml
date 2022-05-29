import QtQuick 2.12
import QtGraphicalEffects 1.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Private 1.0
import QtQml 2.12
import QtQuick.Dialogs 1.2
import QtQml.Models 2.2

Item {
    id:tree_view
    TreeView{
        id:tree
        headerVisible: false
        frameVisible: false
        section.property: ""
        antialiasing: true
        highlightOnFocus: true

//            headerDelegate: {

//
//                            }

            rowDelegate:Rectangle{
                height:40
                gradient: Gradient {
                    GradientStop { position: 0.2; color: "#003A6B" }
                    GradientStop { position: 0.6; color: "#1B5886" }
                    GradientStop { position: 1.0; color: "#5293BB" }
                }
            }
            style: TreeViewStyle{
                branchDelegate:Rectangle {
                    width: 25; height: 25
                    anchors.left: parent.left
                    anchors.leftMargin: 15
                    color: "transparent"


                    Image {
                        id: icon
                        source: "qrc:/tree_view_icons/icons8-folder-64(1).png"
                        anchors.fill: parent
                    }

                    }
               highlightedTextColor: "black"
               backgroundColor:"white"
               textColor:"white"

            }

            model: mymodel
            anchors.fill: parent
            itemDelegate: Item {

                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    color: "white"
                    elide: styleData.elideMode
                    text: styleData.value
                    anchors.left: parent.left
                    anchors.leftMargin: 20

                }
}

            Transition {
                id: treeTransitionAnimation
                NumberAnimation { properties: "y"; duration: 700; easing.type: Easing.InOutCirc }
            }

            Transition {
                id: treeTransitionAnimation_neg
                NumberAnimation { properties: "y"; to:0; duration: 900; easing.type: Easing.OutInCirc }
            }

            TableViewColumn{
                resizable: false
                role: "display"
                title: "elements"
                width: 100


            }
            Component.onCompleted: {
                if(this.__listView) {
                    this.__listView.add  = treeTransitionAnimation
                    this.__listView.remove  = treeTransitionAnimation_neg
                }
                else {
                    console.log("Something bad happened")
                }
            }


            onClicked: {
                //console.log("curExpandedRowIndex is: ",__currentRow)
                console.log("curIndexParentRow is: ",currentIndex.parent.row, "CurIndexChildrow: ",currentIndex.row,"CurRowindex: ",__currentRow)
                treeEvent.onClicked()
            }

            onCurrentIndexChanged: {
                treeEvent.onCurrentIndexChanged()
            }
            onRootIndexChanged: {
                treeEvent.onRootIndexChanged()
            }


        }

}


