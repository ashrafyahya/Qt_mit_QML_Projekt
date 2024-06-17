import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: myWindo
    width: 680
    height: 680
    visible: true
    title: "Hello World"
    color: "gray"

    property bool buttonOn
    Button{
        x: 20; y:10;
        text:  "press me"
        property bool buttonOn: false
        onClicked: {
            if (buttonOn== false){
                mySmVehicle.runProcessEventWithQString( "a" );
                mySmVehicle.runSimulate();
                buttonOn= true;
                timer1.running=true;
            } else {
                buttonOn=false;
                timer1.running=false;
                mySmVehicle.runSimulate();
            }
        }
    }

    property bool buttOn
    Button{
        x: 80; y:10;
        text:  "press for again"
        property bool buttOn: false
        onClicked: if(buttOn== false)
                   {buttOn=true;
                       if(buttonOn== true) buttonOn=false;
                       mySmVehicle.runProcessEventWithQString( "0" );
                       timer2.triggered();
                       car1.x= mySmVehicle.runGetXPos();
                       tur.y=12;
                       car1.color="red";
                       buttOn=false}
    }


    Timer{
        id: timer1
        interval: 50; running: false; repeat: true
        onTriggered:
        {
            mySmVehicle.runProcessEventWithQString("t"); //("t" ist leider automatisch vom Typ QString)
            mySmVehicle.runSimulate();
            car1.x= mySmVehicle.runGetXPos()
            if(Math.abs(myGoal.x - car1.x) <= 60){
                timer1.running=false
                car1.x= myGoal.x - 60
                car1.color="green"
                dach.color="red"
                boden.color="red"
                myGoal.color="red"
                tur.color="red"
                tur.y=72; }
        }
    }

    Timer{
        id: timer2
        onTriggered: if(buttOn== false){
                         buttOn=true;}
    }

    Rectangle{
        // car1.x.max = 572
        id: car1
        x: mySmVehicle.runGetXPos()
        y: 90       //später anpassen: myWindow.height/2
        width: 46
        height: 40
        color: "red"
        border.width: 2

        Text {
            id: text1
            text: "car1: "+ car1.x
            font.family: "Monotype Corsiva"
            font.bold: true
            font.italic: true
            font.pointSize: 10
        }
        Rectangle{
            //x:25; y:25;
            anchors.bottom: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width/2; height: width/2
            color: "blue"
            //radius: width/2
        }

    }
    Rectangle {
        id: boden
        x: 539
        y: 132
        width: 84
        height: 6
        color: "green"
    }

    Rectangle {
        id: dach
        x: 538
        y: 70
        width: 82
        height: 6
        color: "green"
    }

    Rectangle {
        //Die Wand
        id: myGoal
        x: 618
        y: 70
        width: 6
        height: 65
        color: "green"
    }

    Rectangle {
        //Die Tuer
        id: tur
        x: 535
        y: 12
        width: 6
        height: 65
        color: "green"
    }

}
