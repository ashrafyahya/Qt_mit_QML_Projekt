/*! \file   fahrzeug_header.h
 *  \author Yahya, Ashraf (AY)
 *  \version: Last one
*/
#ifndef FAHRZEUG_HEADER_H
#define FAHRZEUG_HEADER_H
#include <iostream>
#include <string>
#include <complex>

class Fahrzeug{
private:
    double mass;
    double f_max;
    double dt = 1;
public:
    Fahrzeug(void): mass(1500), f_max(200), dt(1){}
    std::complex<double> s = std::complex<double>(0. , 0.);
    std::complex<double> v = std::complex<double>(0. , 0.);
    std::complex<double> a = std::complex<double>(0. , 0.);
    std::complex<double> f_akt = std::complex<double>(0. , 0.);

    void set_mass(double a){mass=a;};
    void set_f_max(double b){f_max=b;};
    void set_dt(double c){dt=c;};

    double get_mass(void){return mass;};
    double get_f_max(void){return f_max;};
    double get_dt(void){return dt;};

    void initVehicle(std::complex<double> s_in=std::complex<double>(0. , 0.),std::complex<double> v_in=std::complex<double>(0. , 0.), std::complex<double> a_in=std::complex<double>(0. , 0.), std::complex<double> f_akt_in=std::complex<double>(0. , 0.),double f_max_in=200, double mass_in=1500, double dt_in=1);
    void accel(void);
    void decel(void);
    void simulate(void);
    void roll(void);
    double getXPos(void);
    double getYPos(void);
    std::string getVehicleString();
    void testVehicleSimulation(void);
    void up(void);
    void down(void);
    void enum_getStateString(void);

};
std::string to_string_with_precision(double number_in, int precision_in);
#endif // FAHRZEUG_HEADER_H
