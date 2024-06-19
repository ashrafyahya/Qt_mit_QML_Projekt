/*! \file_name main.cpp
 * \author  Yahya, Ashraf (AY)
 * \version: Last one
*/
#include <QGuiApplication>
#include <QQmlApplicationEngine>


#include <QQmlContext> // Tranfer QML <--> C++

#include "smvehicleinterface_header.h"
#include "SmVehicle_header.h"
#include "fahrzeug_header.h"
#include "statemachine_header.h"

int main(int argc, char *argv[]){

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    SmVehicleInterface *mySmVehiclePtr = new SmVehicle;
    // Objekt in QML (unter ggf. neuem Namen) verfuegbar machen:
    engine.rootContext()->setContextProperty("mySmVehicle", mySmVehiclePtr);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
        if (engine.rootObjects().isEmpty())
            return -1;
        return app.exec();
}
