import QtQuick 2.0
import QtQuick.Controls 2.12



Item {



    property bool stateVisible: false


    ComboBox{
        background: Rectangle {
           gradient: Gradient {
                      GradientStop { position: 0.35; color: "#4c6cb0" }
                      GradientStop { position: 1.0; color: "#00d4ff" }
                  }
        }
        id: styleSelector
        displayText: "Please Choose:"
        width: 200
        height: 50
        onActivated: {
            if (displayText === currentText){

                displayText = "Please Choose:"
            }else
                displayText = styleSelector.currentText
        }
        onHighlightedIndexChanged: {




                if (textAt(highlightedIndex) === displayText){
                    stateVisible = true





                }
                else{
                   stateVisible = false

                }




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
                id:i
                width: styleSelector.width -16
                color: "transparent"
                radius: 20

            }
            highlighted: styleSelector.highlightedIndex === index
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
                Rectangle{

                    Image {
                        id: image
                        opacity: 0
                        enabled: false
                        height: 16
                        width: 16
                        source: "qrc:/multiply"
                        anchors.centerIn: highlight
                        anchors.right: parent.right
                        anchors.rightMargin: 12
                        anchors.verticalCenter: parent.verticalCenter

}
                    gradient: Gradient {
                        GradientStop { position: 0.0; color: "#00d4ff" }
                        GradientStop { position: 0.33; color: "#5079b3" }
                        GradientStop { position: 1.0; color: "#8b43a3" }

                    }

                    states: [
                            State { when: stateVisible;
                                PropertyChanges { target: image; opacity: 1.0 }

                            },
                            State { when: !stateVisible;
                                PropertyChanges { target: image; opacity: 0.0 }

                            }
                        ]
                        transitions: Transition {
                            NumberAnimation { property: "opacity"; duration: 300}
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


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
