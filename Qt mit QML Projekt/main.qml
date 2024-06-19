import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: myWindo
    width: 880
    height: 680
    visible: true
    title: "My Car"
    color: "gray"

    property bool buttonOn
    Button{
        x: 20; y:30;
        text:  "ST/SP"
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
        x: 80; y:30;
        text:  "Restart"
        property bool buttOn: false
        onClicked: if(buttOn== false)
                   {buttOn=true;
                       if(buttonOn== true) buttonOn=false;
                       mySmVehicle.runProcessEventWithQString( "0" );
                       timer2.triggered();
                       mySmVehicle.runSimulate();
                       car1.x= mySmVehicle.runGetXPos()+100;
                       tur.y=95;
                       car1.color="red";
                       dach.color="green"
                       boden.color="green"
                       myGoal.color="green"
                       tur.color="green"
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
            if(Math.abs(myGoal.x - car1.x) <= 95){
                timer1.running=false
                car1.x= myGoal.x - 95
                car1.color="green"
                dach.color="red"
                boden.color="red"
                myGoal.color="red"
                tur.color="red"
                tur.y=172; }
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
        x: mySmVehicle.runGetXPos() + 100
        y: 220       //später anpassen: myWindow.height/2


        Image {
                id: carImage
                source: "qrc:/car.png" // Replace with the path to your image file
                width: 200
                height: 100
                fillMode: Image.PreserveAspectFit
                anchors.centerIn: parent
            }

        Text {
            id: text1
            text: "car.x: "+ car1.x
            font.family: "Monotype Corsiva"
            font.bold: true
            font.italic: true
            font.pointSize: 10
            y: -40
        }

    }
    Rectangle {
        id: boden
        x: 620
        y: 252
        width: 202
        height: 6
        color: "green"
    }

    Rectangle {
        id: dach
        x: 620
        y: 170
        width: 200
        height: 6
        color: "green"
    }

    Rectangle {
        //Die Wand
        id: myGoal
        x: 818
        y: 170
        width: 6
        height: 85
        color: "green"
    }

    Rectangle {
        //Die Tuer
        id: tur
        x: 620
        y: 95
        width: 6
        height: 80
        color: "green"
    }

}
