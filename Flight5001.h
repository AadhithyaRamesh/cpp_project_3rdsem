#ifndef FLIGHT5001_H_INCLUDED
#define FLIGHT5001_H_INCLUDED
#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED
#include "Flight.h"
#endif // FLIGHT_H_INCLUDED

class Airline5001;
class Flight5001 : public Flight
{
    string origin,destination,departure,name;
    float duration,distance;
    int num_of_seats;
    Airline * a;
public:
    Flight5001(string o,string des,string dep,string n,float dur,float dis,int nos,Airline* ar);
    string getName();
    string getOrigin();
    string getDestination();
    string getDeparture();
    float getDuration();
    float getDistance();
    int numAvailableSeats();
    void redAvailableSeats();
    void setAvailableSeats(int s);
    Airline& getAirline();
};

#endif // FLIGHT5001_H_INCLUDED
