import QtQuick 2.0
import QtQuick.Controls 2.12

Item {
    Rectangle{
        anchors.centerIn: parent

        width: 200
        height: 50
        //radius: 15
        //anchors.verticalCenter: parent.verticalCenter
        color: "transparent"
        border.width: 1.2
        border.color: "black"

        ComboBox{
            //width: 200
            //height: 50
            id: styleSelector
            anchors.fill: parent
            onCurrentIndexChanged: {
                console.log(currentText)
            }
            model: ["Section1", "Section2", "Section3", "Section4"]
            delegate: ItemDelegate {
                width: styleSelector.width
                contentItem: Text {
                    text: modelData
                    color: "#FFFFFF"

                    elide: Text.ElideRight
                    verticalAlignment: Text.AlignVCenter
                }
                background: Rectangle {
                    id:item
                    width: 100
                    color: "transparent"
                    radius: 20


                }
                highlighted: styleSelector.highlightedIndex === index
            }
            background: Rectangle {
                anchors.fill: parent
                gradient: Gradient {
                       GradientStop { position: 0.35; color: "#4c6cb0" }
                       GradientStop { position: 1.0; color: "#00d4ff" }
                      }
                border.color: "white"
                border.width: 4
                //radius: 30
            }

            popup: Popup{


                enter: Transition {
                    NumberAnimation { property: "height"; from: 0.0; to: styleSelector.height * 6; easing.type: Easing.InOutCirc; duration: 1000 }
                }

                id:popup
                y: styleSelector.height - 1
                width: styleSelector.width
                height: styleSelector.height * 6
                padding: 1


                Component {
                     id: highlight
                     Rectangle {
                         width: 180; height: 40
                          gradient: Gradient {
                                    GradientStop { position: 0.0; color: "#00d4ff" }
                                    GradientStop { position: 0.33; color: "#5079b3" }
                                    GradientStop { position: 1.0; color: "#8b43a3" }
                                } radius: 5
//                         y: list.currentItem.y
//                         Behavior on y {
//                             SpringAnimation {
//                                 spring: 3
//                                 damping: 0.2
//                             }
//                         }
                     }
                 }


                contentItem: ListView {
                    id: listview
                    implicitHeight: popup.height
                    clip: true
                    highlight: highlight
                    model:styleSelector.delegateModel
                    currentIndex: styleSelector.highlightedIndex
                    interactive: true
                    highlightMoveDuration: 0
                    boundsBehavior: ListView.StopAtBounds


                    ScrollBar.vertical:ScrollBar {}
                }
                background: Rectangle {
                    //anchors.top: styleSelector.top
                    anchors.topMargin: 10
                    //radius: 20
                    gradient: Gradient {
                           GradientStop { position: 0.35; color: "#4c6cb0" }
                           GradientStop { position: 1.0; color: "#00d4ff" }
                          }
                    border.width: 4
                    border.color:"white"
                }


            }


        }
    }


}
