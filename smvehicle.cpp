/*! \file_name smvehicle.cpp
 * \author  Yahya, Ashraf (AY)
 *          Omar, Ali (AO)
 * \version: Last one
*/
#include "fahrzeug_header.h"
#include "SmVehicle_header.h"
#include "statemachine_header.h"

void SmVehicle::runSimulate( void) {
    this->myVehicle.simulate();
}

//--- Member-Funktionen fuer statemachine-Anteil:
void SmVehicle::runProcessEvent(char driverInputChar) {
    this->mySm.processEvent(driverInputChar);
}

//--- Member-Funktionen fuer vehicle-Anteil:
double SmVehicle::runGetXPos( void){return this->myVehicle.getXPos();}
double SmVehicle::runGetYPos(void){myVehicle.getYPos(); return 0;};

//--- Member-Funktionen fuer beide Anteile:
std::string SmVehicle::getSmVehicleString(void){
    return this->myVehicle.getVehicleString()+this->mySm.getStateString();
}

void SmVehicle::runaccel(void){myVehicle.accel();}
void SmVehicle::rundecel(void){myVehicle.decel();}
void SmVehicle::runroll(void){myVehicle.roll();}

std::string SmVehicle::rungetStateString(void){return this->mySm.getStateString();}






