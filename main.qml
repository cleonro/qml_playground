import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15

import com.tst.model 1.0

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Material.theme: Material.Dark
    Material.accent: Material.Blue

    TstModel {
        id: tstModel
        id_label: qsTr("" + 15)
    }

    TstQml {
        id: testQml
        model: tstModel
        anchors.fill: parent
    }

    Component.onCompleted: {
        console.log("-------------------\nmain.qml Component.oncompleted...")
        console.log("TstModel id_label: ", tstModel.id_label)
        console.log("TstModel number: ", tstModel.number)
        console.log("TstModel selections: ", tstModel.selections)
        console.log("-------------------")
    }

}
