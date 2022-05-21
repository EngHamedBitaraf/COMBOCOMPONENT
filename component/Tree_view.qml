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


    Rectangle {
        radius: 10
        anchors.fill: parent
        id: root
        height: tree.height
        width: tree.width
        Transition {
            NumberAnimation {target:root ; property: "height"; from: 0; to: tree.height; easing.type: Easing.InOutCirc; duration: 1000; running: true}
        }


        TreeView{
            id:tree


            headerDelegate: {

                        enabled:false
                    }

            rowDelegate:Rectangle{

                height:40



                gradient: Gradient {
                    GradientStop { position: 0.35; color: "#4c6cb0" }
                    GradientStop { position: 1.0; color: "#00d4ff" }

                }
            }
            style: TreeViewStyle{
//                branchDelegate:Rectangle {
//                    width: 20; height: 20
//                        color: "transparent"
//                    }
               highlightedTextColor: "black"
               backgroundColor:"white"
               textColor:"white"

            }

            model: mymodel
            anchors.fill: parent
//            itemDelegate: Item {




//                Text {
//                    anchors.verticalCenter: parent.verticalCenter
//                    color: "white"
//                    elide: styleData.elideMode
//                    text: styleData.value
//                }
//            }




            Transition {
                id: treeTransitionAnimation
                NumberAnimation { properties: "y"; duration: 700; easing.type: Easing.InOutQuint }
            }

            TableViewColumn{


                resizable: false

                //            delegate: {


                //            }

                role: "display"
                title: "elements"
                width: 100



            }
            Component.onCompleted: {
                if(this.__listView) {
                    this.__listView.add  = treeTransitionAnimation
                    this.__listView.remove  = treeTransitionAnimation
                    //doesn't actually work on remove. The child items in the tree just disappear...
                }
                else {
                    console.log("Something bad happened. Darn.")
                }
            }
        }

    }

}
