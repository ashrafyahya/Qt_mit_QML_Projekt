/*! \file_name statemachine.cpp
 * \author Yahya, Ashraf (AY)
 * \version: Last one
*/
#include<iostream>
#include<string>
#include "fahrzeug_header.h"
#include"statemachine_header.h"

using namespace std;

void Sm::processEvent(char fahrbefehl){

        if(fahrbefehl=='a'){this->veh_ptr->accel(); this->state="Accel ";}
        //else if(fahrbefehl=='e'){state = off_state;}
        // Wie halte ich das Auto durch ein Satet an ????
        else if(fahrbefehl =='u'){veh_ptr->up(); state ="Up ";}
        else if(fahrbefehl =='d'){veh_ptr->down(); state="Down ";}
        else if(fahrbefehl =='r'){veh_ptr->decel(); state="Decel ";}
        else if(fahrbefehl=='0'){veh_ptr->roll(); state="Decel ";}
}
//getStateString gibt den aktuellen Zustand des Autos als String zurück
string Sm::getStateString(void){

    return state;
}

