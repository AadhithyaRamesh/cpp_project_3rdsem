#ifndef AIRLINE5001B_H_INCLUDED
#define AIRLINE5001B_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#ifndef PORTAL_H_INCLUDED
#define PORTAL_H_INCLUDED
#include "Portal.h"
#endif // PORTAL_H_INCLUDED
#include <sstream>
#ifndef AIRLINE_H_INCLUDED
#define AIRLINE_H_INCLUDED
#include "Airline.h"
#endif // AIRLINE_H_INCLUDED
#include "Flight5001.h"

class Airline5001b : public Airline
{
    int ts,tickets_sold;
    string name;
    float reven,pk;
    vector<Flight5001 *> f;
public:
    Airline5001b(Portal *p1);
    ~Airline5001b();
    string getName();
    void init(string ifile);
    void findFlights(string origin, string destination,vector<Flight *> & flights);
    float getPrice(Flight *flight);
    bool issueTicket(Flight *flight);
    int getNumSold();
    void getSalesStats(float& revenue, float& passKm);
};


#endif // AIRLINE5001B_H_INCLUDED
