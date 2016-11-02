#include "Airline5001b.h"

using namespace std;

Airline5001b::Airline5001b(Portal* p1): Airline(p1)
{
    ts = 0;
    tickets_sold=0;
    reven = 0;
    pk = 0;
    Airline * ta = static_cast<Airline *>(this);
    p1->addAirline(ta);
    name = "A0072";
}
Airline5001b::~Airline5001b()
{
    int s = f.size();
    for(int i=0;i<s;i++)
    {
        delete f[i];
    }
}
string Airline5001b::getName()
{
    return name;
}
void Airline5001b::init(string ifile)
{
    const char * temp = ifile.c_str();
    ifstream myfile;
    myfile.open(temp);
    myfile >> ts;
    string o,des,dep;
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
            string s1 = getName() + "-" + s;
            if(i<nof/2)
            {
                dep = "0000";
            }
            else
            {
                dep = "2359";
            }
            Flight5001 * tf = new Flight5001(o,des,dep,s1,dur,dis,1,this);
            f.push_back(tf);
        }

    }
    /*int sof = ts/f.size();
    cout<<ts<<f.size()<<sof<<endl;
    for(unsigned int i = 0;i<f.size()-1;i++)
    {
        f[i]->setAvailableSeats(sof);
    }
    f.back()->setAvailableSeats(ts-(sof*(f.size()-1)));*/
    myfile.close();
}
float Airline5001b::getPrice(Flight * fl)
{
    string o,des,dep;
    float dur,dis,minp,maxp,dev;
    o = fl->getOrigin();
    des = fl->getDestination();
    getPortal()->routeInfo(o,des,dis,dur,minp,maxp,dev);
    return (fl->getDistance())*(((maxp+minp)/2)+1);
}
void Airline5001b::findFlights(string origin, string destination,vector<Flight *>& flights)
{
    vector<Flight5001 *>::iterator cit;
    for(cit = f.begin();cit<f.end();cit++)
    {
        Flight * tcit = *cit;
        if(tcit->getOrigin()==origin && tcit->getDestination()==destination && tcit->numAvailableSeats()>0)
            flights.push_back(tcit);
    }
}
int Airline5001b::getNumSold()
{
    return tickets_sold;
}
void Airline5001b::getSalesStats(float& revenue,float& passkm)
{
    revenue = reven;
    passkm = pk;
}
bool Airline5001b::issueTicket(Flight* flight)
{
    if(flight->numAvailableSeats()>0)
    {
        tickets_sold++;
        float price = getPrice(flight);
        reven+=price;
        pk+=flight->getDistance();
        Flight5001 * tflight = static_cast<Flight5001 *>(flight);
        tflight->redAvailableSeats();
        cout<<"Ticket issued on flight "<<tflight->getName()<<" from "<<tflight->getOrigin()<<" to "<<tflight->getDestination()<<" of Airline "<<tflight->getAirline().getName()<<" for the price of "<<price<<" Rs"<<endl;
        return true;
    }
    else
    {
        return false;
    }
}
