#ifndef PORTAL5001_H_INCLUDED
#define PORTAL5001_H_INCLUDED
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>
#ifndef PORTAL_H_INCLUDED
#define PORTAL_H_INCLUDED
#include "Portal.h"
#endif // PORTAL_H_INCLUDED
#ifndef AIRLINE_H_INCLUDED
#define AIRLINE_H_INCLUDED
#include "Airline.h"
#endif // AIRLINE_H_INCLUDED
#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED
#include "Flight.h"
#endif // FLIGHT_H_INCLUDED
#include "Route5001.h"

class Airline;
class Flight;

class Portal5001 : public Portal
{
    vector<Route5001 *> r;
    vector<Airline *> a;
    string lo,ld;
    vector<Flight *> sortFlights(string origin, string destination, SortField sortField = Airlines,SortOrder sortOrder = Descending);
    Flight * retTopFlight(SortField sortField,SortOrder SortOrder,string air);
    class myfunctor
    {
        SortField sortField;
        SortOrder sortOrder;
    public:
        myfunctor(SortField s,SortOrder so);
        bool operator()(Flight * f1,Flight * f2);
    };
public:
    Portal5001();
    void initRoutes(string routeInfo);
    void addAirline(Airline* airline);
    void routeInfo(string origin, string destination, float& dist, float& duration,float& minPrice, float& maxPrice, float& timeVariation);
    void showFlights(string origin, string destination, SortField sortField = Airlines,SortOrder sortOrder = Descending);
    void processUserInput(string inputFileName);
    bool buyTicket(BuyOption cirteria, string airline = "");
};


#endif // PORTAL5001_H_INCLUDED
