#ifndef PORTAL5001_H_INCLUDED
#define PORTAL5001_H_INCLUDED
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include "Portal.h"
#include "Airline5001.h"
#include "Route5001.h"

class Portal5001 : public Portal
{
    vector<Route5001 *> r;
    vector<Airline5001 *> a;
    string lo,ld;
    vector<Flight *> sortFlights(string origin, string destination, SortField sortField = Airline,SortOrder sortOrder = Descending);
    Flight * retTopFlight(SortField sortField,SortOrder SortOrder,string air);
public:
    Portal5001();
    void initRoutes(string routeInfo);
    //void addAirline(Airline* airline);
    void routeInfo(string origin, string destination, float& dist, float& duration,float& minPrice, float& maxPrice, float& timeVariation);
    void showFlights(string origin, string destination, SortField sortField = Airline,SortOrder sortOrder = Descending);
    void processUserInput(string inputFileName);
    bool buyTicket(BuyOption cirteria, string airline = NULL);
};


#endif // PORTAL5001_H_INCLUDED
