import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.1
import AppManager 1.0
import Ft2232HWrapper 1.0
import Ascan 1.0


import "../js/Utils.js" as Utils
Window {
    id: app
    visible: true
    width: 640
    height: 480
    color: "red"
    title: qsTr("Flaw Detection")

    property int focusItemIndex: 0
    // menu 1
    property int gainValue: 20
    property int rangeValue: 200
    property int highVolValue: 0
    property int emitDampValue: 0
    property int filterBandValue: 0
    // menu 2
    property int rectificationTypeValue: 0
    property int transducerTypeValue: 0
    property int tcgGainValue: 0
    property int keyBoardBacklightValue: 0
    property int vgaValue: 0


    AppManager{
        id: appManager
    }

    Ft2232HWrapper{
        id: ft2232HWrapper

        // ft2232h data ready
        onDataReady: {
            ascan.recvData(data)
        }
    }




    Column{
        spacing: 0
        width: parent.width

        Rectangle{
            width: parent.width
            height: 60
            color: "red"

            Text {
                id: name
                anchors.centerIn: parent
                text: qsTr("Flaw Detection App")
            }

            Button{
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("exit")

                onClicked: {
                    ft2232HWrapper.closeFt2232H()
                    appManager.startApp("/opt/Launcher/bin/Launcher")
                }
            }
        }
        Row {
            width: parent.width
            height: 400

            Ascan {
                id: ascan
                width: 512
                height: 400
            }

            Item{
                id: menu_container
                anchors.left: ascan.right
                focus: true
                visible: true

                Keys.onPressed: {

                    if(event.key === Utils.KEY_UP){   //KEY UP, SELECT THE UPSIDE ITEM
                        // control the hasFocus owner
                        if(app.focusItemIndex > 0) app.focusItemIndex -= 1
                        else if(app.focusItemIndex === 0)app.focusItemIndex = 9

                    }
                    else if(event.key === Utils.KEY_DOWN){   //KEY DOWN, SELECT THE DOWNSIDE ITEM
                        if(app.focusItemIndex < 9 /* 9 is now the MAX item num*/) app.focusItemIndex += 1
                        else if(app.focusItemIndex === 9)app.focusItemIndex = 0
                    }
                    else if(event.key === Utils.KEY_RIGHT){   //KEY RIGHT +
                        if(gain.hasFocus){
                            app.gainValue += 2

                            ft2232HWrapper.wrGain(app.gainValue)

                            ft2232HWrapper.testFun(0) // test key sound
                        }
                        else if(range.hasFocus){
                            app.rangeValue += 10

                            ft2232HWrapper.wrRange(app.rangeValue)
                        }
                        else if(high_vol.hasFocus){
                            if(app.highVolValue === 0)app.highVolValue = 1
                            else if(app.highVolValue === 1)app.highVolValue = 3
                            else if(app.highVolValue === 3)app.highVolValue = 7

                            ft2232HWrapper.wrHighVol(app.highVolValue)
                        }
                        else if(emit_damp.hasFocus){
                            if(app.emitDampValue === 0)app.emitDampValue = 1

                            ft2232HWrapper.wrEmitDamp(app.emitDampValue)
                        }
                        else if(filter_band.hasFocus){
                            if(app.filterBandValue === 0)app.filterBandValue = 2
                            else if(app.filterBandValue === 2)app.filterBandValue = 3

                            ft2232HWrapper.wrFilterBand(app.filterBandValue)
                        }
                        // menu 2
                        else if(rectificationType.hasFocus){
                            if(app.rectificationTypeValue < 3)app.rectificationTypeValue += 1

                            ft2232HWrapper.wrrectificationType(app.rectificationTypeValue)
                            ascan.setrectificationType(app.rectificationTypeValue)
                        }
                        else if(transducerType.hasFocus){
                            if(app.transducerTypeValue < 1)app.transducerTypeValue += 1

                            ft2232HWrapper.wrtransducerType(app.transducerTypeValue)
                        }
                        else if(tcgGain.hasFocus){
                            if(app.tcgGainValue < 1)app.tcgGainValue += 1

                            ft2232HWrapper.wrtcgGain(app.tcgGainValue)
                        }
                        else if(keyBoardBacklight.hasFocus){
                            if(app.keyBoardBacklightValue < 3)app.keyBoardBacklightValue += 1

                            ft2232HWrapper.wrkeyBoardBacklight(app.keyBoardBacklightValue)
                        }
                        else if(vga.hasFocus){
                            if(app.vgaValue < 1)app.vgaValue += 1

                            ft2232HWrapper.wrvga(app.vgaValue)
                        }
                    }
                    else if(event.key === Utils.KEY_LEFT){  //KEY LEFT -
                        if(gain.hasFocus){
                            if(app.gainValue >= 2){
                                app.gainValue -= 2

                                ft2232HWrapper.wrGain(app.gainValue)
                            }
                        }
                        else if(range.hasFocus){
                            if(app.rangeValue >= 10){
                                app.rangeValue -= 10

                                ft2232HWrapper.wrRange(app.rangeValue)
                            }
                        }
                        else if(high_vol.hasFocus){
                            if(app.highVolValue === 1)app.highVolValue = 0
                            else if(app.highVolValue === 3)app.highVolValue = 1
                            else if(app.highVolValue === 7)app.highVolValue = 3

                            ft2232HWrapper.wrHighVol(app.highVolValue)
                        }
                        else if(emit_damp.hasFocus){
                            if(app.emitDampValue === 1)app.emitDampValue = 0

                            ft2232HWrapper.wrEmitDamp(app.emitDampValue)
                        }
                        else if(filter_band.hasFocus){
                            if(app.filterBandValue === 3)app.filterBandValue = 2
                            else if(app.filterBandValue === 2)app.filterBandValue = 0

                            ft2232HWrapper.wrFilterBand(app.filterBandValue)
                        }
                        // menu 2
                        else if(rectificationType.hasFocus){
                            if(app.rectificationTypeValue > 0)app.rectificationTypeValue -= 1

                            ft2232HWrapper.wrrectificationType(app.rectificationTypeValue)
                            ascan.setrectificationType(app.rectificationTypeValue)
                        }
                        else if(transducerType.hasFocus){
                            if(app.transducerTypeValue > 0)app.transducerTypeValue -= 1

                            ft2232HWrapper.wrtransducerType(app.transducerTypeValue)
                        }
                        else if(tcgGain.hasFocus){
                            if(app.tcgGainValue > 0)app.tcgGainValue -= 1

                            ft2232HWrapper.wrtcgGain(app.tcgGainValue)
                        }
                        else if(keyBoardBacklight.hasFocus){
                            if(app.keyBoardBacklightValue > 0)app.keyBoardBacklightValue -= 1

                            ft2232HWrapper.wrkeyBoardBacklight(app.keyBoardBacklightValue)
                        }
                        else if(vga.hasFocus){
                            if(app.vgaValue > 0)app.vgaValue -= 1

                            ft2232HWrapper.wrvga(app.vgaValue)
                        }
                    }
                    else if(event.key === Utils.KEY_BACK){   // now use this ESC button to exit application
                        ft2232HWrapper.closeFt2232H()
                        appManager.startApp("/opt/Launcher/bin/Launcher")
                    }

                    console.log("app.focusItemIndex: ", app.focusItemIndex)
                }//Keys.onPressed

                Column{
                    id: menu_1
                    width: 128
                    spacing: 0
                    height: parent.height
                    visible: app.focusItemIndex < 5

                    FunctionButton {
                        id: gain
                        title: qsTr("menu_gain")
                        value: app.gainValue
                        index: 0
                        // for now, gain's hasFocus is true[just for test period]
                        hasFocus: {
                            if(app.focusItemIndex === index) return true
                            else return false
                        }
                    }
                    FunctionButton{
                        id: range
                        title: qsTr("menu_range")
                        value: app.rangeValue
                        index: 1
                        hasFocus: {
                            if(app.focusItemIndex === index) return true
                            else return false
                        }

                    }
                    FunctionButton{
                        id: high_vol
                        title: qsTr("menu_high_vol")
                        value: {
                            if(app.highVolValue === 0) return "50"
                            else if(app.highVolValue === 1) return "100"
                            else if(app.highVolValue === 3) return "200"
                            else if(app.highVolValue === 7) return "400"
                        }
                        index: 2
                        hasFocus: {
                            if(app.focusItemIndex === index) return true
                            else return false
                        }

                    }
                    FunctionButton{
                        id: emit_damp
                        title: qsTr("menu_damp")
                        value: app.emitDampValue === 0 ? qsTr("low_damp") : qsTr("high_damp")
                        index: 3
                        hasFocus: {
                            if(app.focusItemIndex === index) return true
                            else return false
                        }

                    }
                    FunctionButton{
                        id: filter_band
                        title: qsTr("menu_filter_band")
                        value: {
                            if(app.filterBandValue === 0)return "0.5-20MHz"
                            else if(app.filterBandValue === 2)return "2-8MHz"
                            else if(app.filterBandValue === 3)return "0.5-4MHz"
                        }
                        index: 4
                        hasFocus: {
                            if(app.focusItemIndex === index) return true
                            else return false
                        }

                    }
                } //Column end

                Column{
                    id: menu_2
                    width: 128
                    spacing: 0
                    height: parent.height
                    visible: app.focusItemIndex > 4

                    FunctionButton {
                        id: rectificationType
                        title: qsTr("menu_rectificationType")
                        value: {
                            if(app.rectificationTypeValue === 0) return qsTr("rectification_radio")
                               else if(app.rectificationTypeValue === 1) return qsTr("rectification_all")
                               else if(app.rectificationTypeValue === 2) return qsTr("rectification_plus")
                               else if(app.rectificationTypeValue === 3) return qsTr("rectification_minus")
                        }
                        index: 5
                        hasFocus: {
                            if(app.focusItemIndex === index) return true
                            else return false
                        }

                    }
                    FunctionButton{
                        id: transducerType
                        title: qsTr("menu_transducerType")
                        value:{
                            if(app.transducerTypeValue === 0) return qsTr("transducer_single")
                            else if(app.transducerTypeValue === 1) return qsTr("transducer_double")

                        }
                        index: 6
                        hasFocus: {
                            if(app.focusItemIndex === index) return true
                            else return false
                        }

                    }
                    FunctionButton{
                        id: tcgGain
                        title: qsTr("menu_tcgGain")
                        value: {
                            if(app.tcgGainValue === 0) return qsTr("tcg_off")
                            else if(app.tcgGainValue === 1) return qsTr("tcg_on")

                        }
                        index: 7
                        hasFocus: {
                            if(app.focusItemIndex === index) return true
                            else return false
                        }

                    }
                    FunctionButton{
                        id: keyBoardBacklight
                        title: qsTr("menu_keyBoardBacklight")
                        value: {
                            if(app.keyBoardBacklightValue === 0)return qsTr("light_off")
                            else if(app.keyBoardBacklightValue === 1)return qsTr("light_low")
                            else if(app.keyBoardBacklightValue === 2)return qsTr("light_mid")
                            else if(app.keyBoardBacklightValue === 3)return qsTr("light_high")
                        }

                        index: 8
                        hasFocus: {
                            if(app.focusItemIndex === index) return true
                            else return false
                        }

                    }
                    FunctionButton{
                        id: vga
                        title: qsTr("menu_vga")
                        value: {
                            if(app.vgaValue === 0)return qsTr("vga_off")
                            else if(app.vgaValue === 1)return qsTr("vga_on")

                        }
                        index: 9
                        hasFocus: {
                            if(app.focusItemIndex === index) return true
                            else return false
                        }

                    }
                } //Column end

            }



        }
        Rectangle{
            width: parent.width
            height: 20
            color: "blue"
        }
    }





}
