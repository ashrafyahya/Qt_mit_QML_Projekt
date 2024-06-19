/*! \file   SmVehicle_header.h
 *  \author Yahya, Ashraf (AY)
 *  \version: Last one
*/
#ifndef SMVEHICLE_HEADER_H
#define SMVEHICLE_HEADER_H
#include<QObject>
#include<string>
#include"fahrzeug_header.h"
#include<statemachine_header.h>
#include "smvehicleinterface_header.h"

class SmVehicle:public SmVehicleInterface{
public:
    Fahrzeug myVehicle;
    Sm mySm;
    SmVehicle(void):myVehicle(),mySm(&myVehicle){}
    void runSimulate(void)override;
    void runProcessEvent(char dirverInput) override;
    std::string rungetStateString(void);
    void runaccel(void);
    void rundecel(void);
    void runroll(void);
    double runGetXPos(void) override;
    double runGetYPos(void) override;
    std::string getSmVehicleString(void) override;
};
#endif // SMVEHICLE_HEADER_H
