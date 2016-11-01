
#include "Airline5001.h"

using namespace std;

Airline5001::Airline5001(Portal* p1): Airline(p1)
{
    ts = 0;
    Airline * ta = static_cast<Airline *>(this);
    p1->addAirline(ta);
    name = "A0071";
}
Airline5001::~Airline5001()
{
    int s = f.size();
    for(int i=0;i<s;i++)
    {
        delete f[i];
    }
}
string Airline5001::getName()
{
    return name;
}
void Airline5001::init(string ifile)
{
    const char * temp = ifile.c_str();
    ifstream myfile;
    myfile.open(temp);
    myfile >> ts;
    string o,des;
    int nof;
    float dur,dis,minp,maxp,dev;
    while(myfile>>o>>des>>nof)
    {
        getPortal()->routeInfo(o,des,dis,dur,minp,maxp,dev);
        for(int i=0;i<nof;i++)
        {
            string s;
            stringstream out;
            out<<i;
            s = out.str();
            Flight5001 * tf = new Flight5001(o,des,"0000",s,dur,dis,5,this);
            f.push_back(tf);
        }
    }
    myfile.close();
}
float Airline5001::getPrice(Flight * fl)
{
    return fl->getDistance();
}
void Airline5001::findFlights(string origin, string destination,vector<Flight *>& flights)
{
    vector<Flight5001 *>::iterator cit;
    for(cit = f.begin();cit<f.end();cit++)
    {
        Flight * tcit = *cit;
        if(tcit->getOrigin()==origin && tcit->getDestination()==destination && tcit->numAvailableSeats()>0)
            flights.push_back(tcit);
    }
}
int Airline5001::getNumSold()
{
    return ts;
}
void Airline5001::getSalesStats(float& revenue,float& passkm)
{
    revenue = reven;
    passkm = pk;
}
bool Airline5001::issueTicket(Flight* flight)
{
    if(flight->numAvailableSeats()>0)
    {
        ts--;
        reven+=getPrice(flight);
        pk+=flight->getDistance();
        Flight5001 * tflight = static_cast<Flight5001 *>(flight);
        tflight->redAvailableSeats();
        return true;
    }
    else
    {
        return false;
    }
}
