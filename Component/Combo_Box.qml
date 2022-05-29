import QtQuick 2.12
import QtGraphicalEffects 1.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import contrl_struct 1.0



Item {
    DropShadow {
        id:shadow
        anchors.fill: styleSelector
        horizontalOffset: 1
        verticalOffset: 1
        radius: 8
        spread: 0.1
        samples: 18
        color: "lightblue"
        source: styleSelector
    }
    property bool stateVisible: false
    ComboBox{
        background: Rectangle {
            radius: 10
            id:x
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
            console.log(currentIndex)

            comboEvent.onActivated(currentText)
        }
        onHighlightedIndexChanged: {

                if (textAt(highlightedIndex) === displayText){
                    stateVisible = true

                }
                else{
                   stateVisible = false

                }
                comboEvent.onHighlightedIndexChanged()
        }
        onCurrentIndexChanged: {
                comboEvent.onCurrentIndexChanged()
        }
        onCurrentTextChanged: {
                comboEvent.onCurrentTextChanged()
        }


        model: ["Section1", "Section2", "Section3", "Section4", "Section5", "Section6", "Section7", "Section8"]
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
                //width: styleSelector.width -16
                color: "transparent"
//                radius: 20

            }
            highlighted: styleSelector.highlightedIndex === index
        }


        popup: Popup{

            enter: Transition {
                NumberAnimation { property: "height"; from: 0.0; to: styleSelector.height * 6; easing.type: Easing.InOutCirc; duration: 1000 }
            }
            exit: Transition {
                NumberAnimation { property: "height"; from: styleSelector.height * 6; to: 0.0; easing.type: Easing.OutInCirc; duration: 800 }
            }

            id:popup
            y: styleSelector.height
            width: styleSelector.width
            height: styleSelector.height * 6
            padding: 1


            Component {
                id: highlight            
                Rectangle{
                    radius: 10
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

                anchors.top: parent.top
                anchors.topMargin: 7.4
                ScrollBar.vertical:ScrollBar {}
            }
            background: Rectangle {
                anchors.top: parent.top
                anchors.topMargin: 7
                id : reccombo
                radius: 10
                gradient: Gradient {
                    GradientStop { position: 0.35; color: "#4c6cb0" }
                    GradientStop { position: 1.0; color: "#00d4ff" }
                }
//                border.width: 4
//                border.color:"white"

            }


        }


    }

}


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
