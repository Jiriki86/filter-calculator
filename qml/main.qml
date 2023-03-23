import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import MyWidgets 1.0 

Window {

    property int cnt: 0

    id: root
    visible: true
    title: "Filter-Calculator"
    width: 600
    height: 250
    maximumWidth: width 
    maximumHeight: height 
    minimumWidth: width 
    minimumHeight: height
    
    Row {
        id: filterParameterRow
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 10 
        anchors.leftMargin: 10
        spacing: 10

        Label {
            text: "R [kOhm]"
        }

        Rectangle {
            id: input
            width: 50
            height: 20
            color: "white"
            border.color: "gray"
            radius: 5
                
            TextInput {
                anchors.fill: parent
                horizontalAlignment: TextInput.AlignHCenter 
                text: filterCalculator.res
                validator: DoubleValidator {bottom: 0; top: 9999; locale: "en_GB"}
                onEditingFinished: {
                    filterCalculator.setRes(parseFloat(text));
                }
            }
        }

        Label {
            text: "C [nF]"
        }

        Rectangle {
            width: 50
            height: 20
            color: "white"
            border.color: "gray"
            radius: 5
                
            TextInput {
                anchors.fill: parent
                horizontalAlignment: TextInput.AlignHCenter 
                text: filterCalculator.cap 
                validator: DoubleValidator {bottom: 0.; top: 9999.; locale: "en_GB";}
                onEditingFinished: {
                    filterCalculator.setCap(parseFloat(text));
                }
            }
        }

        Label {
            text: "Cut-Off [kHz]"
        }

        Rectangle {
            width: 70
            height: 20
            color: "white"
            border.color: "gray"
            radius: 5
                
            TextInput {
                anchors.fill: parent
                horizontalAlignment: TextInput.AlignHCenter 
                text: (filterCalculator.cutOff).toFixed(2) 
                validator: DoubleValidator {bottom: 0.; top: 9999.; locale: "en_GB";}
                onEditingFinished: {
                    filterCalculator.setCutOff(parseFloat(text));
                }
            }
        }

        Button {
            id: calcButton
            text: "Calculate Parameters"
            onClicked: filterCalculator.calculateCutOff()
            anchors.verticalCenter: input.verticalCenter
        }
    } // filterParameterRow

    ButtonGroup {
        buttons: filterTypeRow.children
        onClicked: filterCalculator.setFilterType(button.text)
    }

    Row {
        id: filterTypeRow
        anchors.top: filterParameterRow.bottom 
        anchors.left: parent.left 
        anchors.topMargin: 10 
        anchors.leftMargin: 10
        spacing: 10 

        Label {
            text: "Filter Type:"
        }
        RadioButton {
            id: lowPassButton
            text: "Low Pass"
        }
        RadioButton {
            id: highPassButton
            text: "High Pass"
        }
        Component.onCompleted: {
            if (filterCalculator.filterType == FilterCalculator.HighPass) {
                highPassButton.checked = true;
            } else {
                lowPassButton.checked = true;
            }
        }
    } // filterTypeRow  

    Image {
        id: bla
        source: filterCalculator.filterType == FilterCalculator.HighPass ? "qrc:/res/Hochpass.svg" : "qrc:/res/Tiefpass.svg"
        anchors.top: filterTypeRow.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 10
    }

    FilterCalculator {
        id: filterCalculator
    }
}
