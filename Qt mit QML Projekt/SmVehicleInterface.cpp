/*smvehicleinterface.cpp; Projekt zur QML-CPP-Integration: P3-QML-Basis-Projekt  WS1920
Anleitung: In dieser Datei sollten sie nichts anpassen muessen.
Inhalt: siehe Beschreibung im Header

 * \author Yahya, Ashraf (AY)
 * \version: Last one
*/
#include<QObject>
#include<QDebug>
#include<QString>
#include<string>

#include "smvehicleinterface_header.h"

Q_INVOKABLE void SmVehicleInterface::runProcessEventWithQString(QString driverInputQString) {
    char driverInputChar= this->getFirstChar(driverInputQString);
    this->runProcessEvent( driverInputChar);
    this->printInfoToDebugConsole();
}

void SmVehicleInterface::printInfoToDebugConsole( void) {
       static std::string s_old;
       std::string s_new= this->getSmVehicleString();
       if( s_new != s_old){
        qDebug() << s_new.c_str();
        s_old= s_new;
       }
}

//Hilfsfunktionen zum Zeichen(-ketten) Konvertieren:
char SmVehicleInterface::getFirstChar(QString s){ //lokale Hilfsfunktion
    return s.at(0).toLatin1();
}

//(QML kann kein std::string uebergeben werden nur ein QString)
Q_INVOKABLE QString SmVehicleInterface::runGetSmVehicleQString(void){
    return QString::fromStdString(this->getSmVehicleString());
}
