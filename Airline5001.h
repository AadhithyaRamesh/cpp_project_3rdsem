#ifndef AIRLINE5001_H_INCLUDED
#define AIRLINE5001_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include "Portal.h"
#include "Airline.h"
#include "Flight5001.h"


class Airline5001 : public Airline
{
    int ts;
    string name;
    float reven,pk;
    vector<Flight5001 *> f;
public:
    Airline5001(Portal *p1);
    string getName();
    void init(string ifile);
    void findFlights(string origin, string destination,vector<Flight5001 *> & flights);
    float getPrice(Flight *flight);
    bool issueTicket(Flight *flight);
    int getNumSold();
    void getSalesStats(float& revenue, float& passKm);
};


#endif // AIRLINE5001_H_INCLUDED
