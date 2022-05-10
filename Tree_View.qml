import QtQuick 2.0
import QtWebChannel 1.0
import QtWebEngine 1.1
Item {
    id : tree_v
    width: 300
    height: 300

    WebEngineView {
    anchors.fill: parent
    url: "qrc:/Tree_View/dist/index.html"
    webChannel: channel
    }

}
