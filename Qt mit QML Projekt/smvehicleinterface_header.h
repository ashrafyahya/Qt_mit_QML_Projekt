/*! \file_name smcehicleinterface_header.h
 * \author Yahya, Ashraf (AY)
 *          Omar, Ali (AO)
 * \version: Last one
*/
#ifndef SMVEHICLEINTERFACE_HEADER_H
#define SMVEHICLEINTERFACE_HEADER_H
/* smvehicleinterface.h; Projekt QML-CPP-Integration: P3-QML-Basis-Projekt WS1920
Anleitung: In dieser Datei sollten sie nichts anpassen muessen (ausser runGetYPos).
Inhalt: Hier wird eine Schnittstelle definiert,
 ...deren Realisierung wird dann als Pflicht an SmVehicle vererbt.

 Ausserdem wird hier das Durcheinander char-string-QString erledigt/transformiert.
*/
#include<QObject>
#include<QString>
#include<string>

class SmVehicleInterface : public QObject  //viele wird geerbt von der QT-Basisklasse QObject
{   //weitere Dinge in Klasse "hereinzauber" mit Macro Q_OBJECT fuer den "Meta-Object-Compiler" von Qt:
    Q_OBJECT
public:
    // ---------Diese Member-Funktionen muessen spaeter in SmVehicle bereit stehen.----------
    // In SmVehicle wird diese Pflicht geerbt  -- damit man sich (in QML) darauf verlassen kann.
    // "Q_INVOKABLE" sorgt dafuer, dass die QML-GUI die Funktionen aufrufen kann.

    Q_INVOKABLE virtual double runGetXPos( void)=0;
    Q_INVOKABLE virtual double runGetYPos( void)= 0;   //FUER SPAETER
    Q_INVOKABLE virtual void runSimulate( void)= 0;
    virtual void runProcessEvent(char driverInputChar)= 0; //indirekter Aufruf via runProcessEventWithQString unten
    Q_INVOKABLE virtual std::string getSmVehicleString(void)= 0;

    //------------Diese Member-Funktionen sind schon erledigt, siehe cpp-Datei:------------------
    Q_INVOKABLE void runProcessEventWithQString(QString driverInputQString);
    //...leitet die Ereignisse von QML an processEvent weiter und ruft bei "t" runSimulatePhysics auf.
    void printInfoToDebugConsole( void);                // nutzt getSmVehicleString()
    Q_INVOKABLE QString runGetSmVehicleQString(void);      // ruft getSmVehicleString() auf und konvertiert nach QString
    explicit SmVehicleInterface(QObject *parent = nullptr): QObject(parent){}
private:
    char getFirstChar(QString s);  //lokale Hilfsfunktion
};

#endif // SMVEHICLEINTERFACE_header_H
