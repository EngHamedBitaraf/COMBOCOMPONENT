import QtQuick 2.12
import QtGraphicalEffects 1.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.3
import QtQuick.Controls.Private 1.0

Item {
    Rectangle {
        width:400;
        height: 400;

        Rectangle {
                id:comboBox
                property variant items: ["Item 1", "Item 2", "Item 3" , "Item 4", "Item 5", "Item 6", "Item 7"]
                property alias selectedItem: chosenItemText.text;
                property alias selectedIndex: listView.currentIndex;
                signal comboClicked;
                width: 200;
                height: 40;
                z: 100;
                smooth:true;

                Rectangle {
                    id:chosenItem
                    radius:4;
                    width:parent.width;
                    height:comboBox.height;
                    gradient: Gradient {
                           GradientStop { position: 0.0; color: "#00d4ff" }
                           GradientStop { position: 0.33; color: "#5079b3" }
                           GradientStop { position: 1.0; color: "#8b43a3" }
                       }
                    smooth:true;
                    Text {
                        anchors.top: parent.top;
                        anchors.topMargin:7
                        anchors.left: parent.left;
                        anchors.leftMargin:5;
                        id:chosenItemText
                        //text:comboBox.items[0];
                        text:"Please Choose"
                        font.family: "Arial"
                        font.pointSize: 14;
                        smooth:true
                        color: "white"


                    }

                    MouseArea {
                        anchors.fill: parent;
                        onClicked: {
                            comboBox.state = comboBox.state==="dropDown"?"":"dropDown"
                        }
                    }
                }

                Rectangle {
                    id:dropDown
                    width:comboBox.width;
                    height:0;
                    clip:true
                    radius:4
                    anchors.top: chosenItem.bottom;
                    anchors.margins: 2;
                    gradient: Gradient {
                           GradientStop { position: 0.35; color: "#4c6cb0" }
                           GradientStop { position: 1.0; color: "#00d4ff" }
                          }
                    ListView {
                        id:listView
                        height:500;
                        model: comboBox.items
                        currentIndex: 0
                        delegate: Item{
                            width:comboBox.width;
                            height: comboBox.height;

                            Text {
                                text: modelData
                                anchors.topMargin: 7
                                anchors.top: parent.top;
                                anchors.left: parent.left
                                anchors.leftMargin: 5
                                color: "white"



                            }
                            ToolSeparator {
                                orientation: Qt.Horizontal
                                width: parent.width
                                anchors.top: parent.top
                                anchors.topMargin: -7
                            }

                            MouseArea {
                                anchors.fill: parent;
                                onClicked: {
                                    modelData.color="red"

                                    comboBox.state = ""
                                    var prevSelection = chosenItemText.text
                                    chosenItemText.text = modelData
                                    if(chosenItemText.text !== prevSelection){
                                        comboBox.comboClicked();




                                    }
                                    listView.currentIndex = index;
                                }
                            }
                        }
                    }
                }

                Component {
                    id: highlight
                    Rectangle {
                        width:comboBox.width;
                        height:comboBox.height;
                        color: "red";
                        radius: 4
                    }
                }

                states: State {
                    name: "dropDown";
                    PropertyChanges { target: dropDown; height:40*comboBox.items.length }
                }

                transitions: Transition {
                    NumberAnimation { target: dropDown; properties: "height"; easing.type: Easing.InOutCirc; duration: 1000 }
                }
            }
        }



}

