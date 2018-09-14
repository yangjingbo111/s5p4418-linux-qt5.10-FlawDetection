import QtQuick 2.0

Item {
    id: btn
    width: parent.width
    height: 80
    property string title: ""
    property string value: ""
    property bool hasFocus: false
    property int index: 0
    signal chosen

    Rectangle{
        width: parent.width
        height: 80
        color: hasFocus? "lightGray" : "RoyalBlue"
        border.width: 2
        border.color: "darkblue"

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 8
            font.pixelSize: 20
            text: btn.title
        }
        Text {
            id: filter_band_val
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 8
            text: btn.value
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
//                chosen()  // comment for now, just use keyboard
            }
        }
    }

}
