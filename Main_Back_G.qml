import QtQuick 2.12
import QtQuick.Window 2.12
import QtWebView 1.1

Item {

    id: back_g
    visible: true
    width: 1280
    height: 300
    WebView {
            id: webview
            url: "qrc:/Search_Box_3/dist/index.html"
            anchors.fill: parent


}
}
