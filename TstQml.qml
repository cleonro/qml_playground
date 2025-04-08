import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import com.tst.model 1.0

Item {

    id: pane

    property TstModel model

    property string id_label: model.id_label

    ColumnLayout {
        Label {
            text: "Test QML"
        }

        TextField {
            id: textField
            placeholderText: "Enter some text"
            text: model.number
            onTextChanged: {
                var validHex = /^[0-9]*$/;
                if (!validHex.test(text) || text.length > 4096) {
                    text = text.slice(0, 4096).replace(/[^0-9]/g, "");
                }
                model.number = text;
            }
        }

        ComboBox {
            id: comboBox
            Layout.fillWidth: true
            model: pane.model.selections
            currentIndex: pane.model.selectedIndex
            onCurrentIndexChanged: {
                pane.model.selectedIndex = currentIndex
            }
        }

        GridLayout {
            columns: 3

            Repeater {
                model: pane.model.choiceList

                Label {
                    Layout.row:index
                    Layout.column: 0

                    text: modelData.label
                }
            }

            Repeater {
                model: pane.model.choiceList

                RowLayout {
                    Layout.row: index
                    Layout.column: 1
                    Layout.columnSpan: 2

                    RadioButton {
                        id: bt1

                        text: modelData.option1
                        checked: modelData.checked
                        onCheckedChanged: {
                            modelData.checked = checked
                        }
                    }

                    Item {
                        Layout.preferredWidth: 100 - bt1.width
                    }

                    RadioButton {
                        text: modelData.option2
                    }
                }
            }
        }

        Button {
            text: "Submit"
            onClicked: {
                console.log("TstQml id_label: ", id_label)
            }
        }
    }
}

