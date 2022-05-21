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
            onActivated: {

                console.log("dsjksdkj")
                if (txt.text === currentText){
                    txt.text = "menu"
                }else
                     txt.text = styleSelector.currentText
            }

            id: styleSelector
            anchors.fill: parent
            editText:  "menu :"
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
                    width: styleSelector.width
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
                border.width: 10
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
                         border.width: 2
                         border.color: "red"
                          gradient: Gradient {
                                    GradientStop { position: 0.0; color: "#00d4ff" }
                                    GradientStop { position: 0.33; color: "#5079b3" }
                                    GradientStop { position: 1.0; color: "#8b43a3" }
                                } radius: 5
                          Image {
                              id: image

                              height: 16
                              width: 16
                              source: "qrc:/icons8-multiply-30.png"
                              anchors.right: parent.right
                              anchors.rightMargin: 10
                              anchors.verticalCenter: parent.verticalCenter
                              MouseArea{
                                  anchors.fill: parent
                                  onClicked: {
                                      console.log("d")
                                      btn.visible =true;
                                  }
                              }
                          }


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
                       id : reccombo
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

    Rectangle{
        visible: true
        id:btn
        anchors.centerIn: parent
        width: 200
        height: 50
        gradient: Gradient {
               GradientStop { position: 0.35; color: "#4c6cb0" }
               GradientStop { position: 1.0; color: "#00d4ff" }
              }
        Text {
            anchors.centerIn: parent
            id:txt
            text: qsTr("Menu")
        }


    }
}
