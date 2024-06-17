/*! \file_name class_Fahrzeug.cpp
 * \author Yahya, Ashraf (AY)
 * \version: Last one
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <complex>
#include <cmath>
#include <sstream>
#include "fahrzeug_header.h"
using namespace std;

//verschiedene Fahrzeugzustände testen
void Fahrzeug::initVehicle(complex<double> s_in,complex<double> v_in,complex<double> a_in,complex<double> f_akt_in,double f_max_in, double mass_in, double dt_in){

    set_f_max(f_max_in);
    set_mass(mass_in);
    s = s_in;
    v = v_in;
    a = a_in;
    f_akt= f_akt_in;
    set_dt(dt_in);
}

void Fahrzeug::simulate(void){
    cout<<"Alte Werte: "<< endl;
    cout<<s<<"m, "<<v<<"m/s, "<<a<<"m/s^2"<<f_akt<<"N"<<endl;

    a= f_akt / get_mass();
    v= v+ a * get_dt();
    s= s+ v * get_dt();
    f_akt+= complex<double>(0. , 0.);

    cout<<"Neue Werte:"<<endl;
    cout<<s<<"m, "<<v<<"m/s, "<<a<<"m/s^2"<<f_akt<<"N"<<endl;
}

//beschleunigt das Fahrzeug durch f_max
void Fahrzeug::accel(void){
    f_akt+= complex<double>(get_f_max(), 0.);
}

//das Fahrzeug bremsst mithilfe von -f_max ab
void Fahrzeug::decel(void){
    f_akt+= complex<double>(-(get_f_max()), 0.); }

//stzt f_akt= 0, lässt das Fahrzeug mit konstanter v rollen.
void Fahrzeug::roll(void){
    f_akt=0.;}

//gibt die X-Position (Realteil)
double Fahrzeug::getXPos(void){
    return s.real();}

//gibt die X-Position (Imaginärteil)
double Fahrzeug::getYPos(void){
    return s.imag();}

//string Fahrzeug::getVehicleString(){
//    return "s.x=" + to_string(s.real()) + ", s.y=" + to_string(s.imag()) + ", v.x=" + to_string(v.real()) + ", v.y=" + to_string(v.imag()) + ", a.x=" + to_string(a.real()) + ", a.y=" + to_string(a.imag()) + ", mass=" + to_string(get_mass()) + ", F_akt_x=" + to_string(f_akt.real()) + ", F_akt_y=" + to_string(f_akt.imag()) + ", F_max= " + to_string(get_f_max()) + ", dt=" + to_string(get_dt()) ;}

//macht Bewegung mit f_max in pos. y-Richtung (Imaginär-Richtung)
void Fahrzeug::up(void){
    f_akt+= complex<double>( 0., get_f_max());}

//macht Bewegung mit f_max in neg. y-Richtung (Imaginär-Richtung)
void Fahrzeug::down(void){
    f_akt+= complex<double>( 0., -(get_f_max()));}


//Hilfsfunktion zur Zahlen-Formatierung (falls ihnen to_string() nicht gefaellt):
string to_string_with_precision( double number_in, int precision_in){
    std::stringstream sstr1; //stringstreams haben wir nicht behandelt
    sstr1 << fixed << setprecision( precision_in) << number_in;
    return sstr1.str();
}

string Fahrzeug::getVehicleString(void){
    //return to_string(this->s);
    return to_string_with_precision( this->s.real(), 2); //Alternative mit obiger Hilfsfunktion
}

