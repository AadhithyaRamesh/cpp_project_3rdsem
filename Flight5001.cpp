#include "Flight5001.h"
using namespace std;
Flight5001::Flight5001(string o,string des,string dep,string n,float dur,float dis,int nos,Airline* ar)
{
    origin = o;
    destination = des;
    departure = dep;
    name = n;
    duration = dur;
    distance = dis;
    num_of_seats = nos;
    a = ar;
}
string Flight5001::getName()
{
    return name;
}
string Flight5001::getDestination()
{
    return destination;
}
string Flight5001::getDeparture()
{
    return departure;
}
string Flight5001::getOrigin()
{
    return origin;
}
float Flight5001::getDuration()
{
    return duration;
}
float Flight5001::getDistance()
{
    return distance;
}
int Flight5001::numAvailableSeats()
{
    return num_of_seats;
}
void Flight5001::redAvailableSeats()
{
    num_of_seats--;
}
void Flight5001::setAvailableSeats(int s)
{
    num_of_seats = s;
}
Airline & Flight5001::getAirline()
{
    return * a;
}
