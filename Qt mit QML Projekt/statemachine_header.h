/*! \file   Sm_header.h
 *  \author Yahya, Ashraf (AY)
 *  \version: Last one
*/
#ifndef STATEMACHINE_HEADER_H
#define STATEMACHINE_HEADER_H
#include<string>
#include"fahrzeug_header.h"

class Sm{
public:
    std::string state;
    Fahrzeug *veh_ptr;
    Sm(Fahrzeug *veh_ptr_in): veh_ptr(veh_ptr_in){}

    //enum enum_getStateString{off_state, neutral_state, decel_state, accel_state};

    std::string getStateString(void);
    void processEvent(char driverInput);
    std::string getState(void);
};

#endif // STATEMACHINE_HEADER_H
