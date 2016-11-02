
#include "Portal5001.h"

Portal5001::Portal5001()
{
    lo = "";
    ld = "";
    r.clear();
    a.clear();
}
Portal5001::~Portal5001()
{
    for(unsigned int i = 0;i<r.size();i++)
    {
        delete r[i];
    }
}
Portal5001::myfunctor::myfunctor(SortField s,SortOrder so):sortField(s),sortOrder(so){}
bool Portal5001::myfunctor::operator()(Flight * f1,Flight * f2)
    {
        bool answer;
        if(sortField==Airlines)
        {
            answer = ((f1->getAirline()).getName().compare((f2->getAirline()).getName())<0);
        }
        else if(sortField==Price)
        {
            answer = f1->getAirline().getPrice(f1)<f2->getAirline().getPrice(f2);
        }
        else if(sortField==Duration)
        {
            answer = f1->getDuration()<f2->getDuration();
        }
        else
        {
            int a = atoi((f1->getDeparture()).c_str());
            int b = atoi((f2->getDeparture()).c_str());
            answer = a<b;
        }
        if(sortOrder==Descending)
            answer = !(answer);
        return answer;
    }
vector<Flight *> Portal5001::retTopFlight(SortField sortField,SortOrder sortOrder,string air)
{
    vector<Flight *> f;
    f.clear();
    if(air!="")
    {
        vector<Airline *>::iterator cit;
        for(cit=a.begin();cit<a.end();cit++)
        {
            if((*cit)->getName()==air)
            {
                (*cit)->findFlights(lo,ld,f);
            }
        }
        if(f.empty())
        {
            vector<Airline *>::iterator cit;
            for(cit=a.begin();cit<a.end();cit++)
            {
                (*cit)->findFlights(lo,ld,f);
            }
        }
    }
    else
    {
        vector<Airline *>::iterator cit;
        for(cit=a.begin();cit<a.end();cit++)
        {
            (*cit)->findFlights(lo,ld,f);
        }
    }
    myfunctor retgreater(sortField,sortOrder);
    sort(f.begin(),f.end(),retgreater);
    return f;
}
vector<Flight *> Portal5001::sortFlights(string origin, string destination, SortField sortField,SortOrder sortOrder)
{
    lo = origin;
    ld = destination;
    vector<Flight *> f;
    vector<Airline *>::iterator cit;
    for(cit=a.begin();cit<a.end();cit++)
    {
        (*cit)->findFlights(origin,destination,f);
    }
    myfunctor retgreater(sortField,sortOrder);
    sort(f.begin(),f.end(),retgreater);
    return f;
}
void Portal5001::initRoutes(string routeInfo)
{
    const char * temp = routeInfo.c_str();
    ifstream myfile;
    myfile.open(temp);
    string o,des;
    float dis,dur,minp,maxp,dev;
    while(myfile>>o>>des>>dis>>dur>>minp>>maxp>>dev)
    {
        Route5001 * tr =  new Route5001(o,des,dis,dur,minp,maxp,dev);
        r.push_back(tr);
    }
    myfile.close();
}
void Portal5001::addAirline(Airline * airline)
{
    a.push_back(airline);
}
void Portal5001::routeInfo(string origin, string destination, float& dist, float& duration,float& minPrice, float& maxPrice, float& timeVariation)
{
    vector<Route5001 *>::iterator cit;
    for(cit = r.begin();cit<r.end();cit++)
    {
        if((*cit)->retOrigin()==origin && (*cit)->retDestination()==destination)
        {
            duration = (*cit)->retdur();
            dist = (*cit)->retdis();
            minPrice = (*cit)->retminp();
            maxPrice = (*cit)->retmaxp();
            timeVariation = (*cit)->retdev();
        }
    }
}
void Portal5001::showFlights(string origin, string destination, SortField sortField,SortOrder sortOrder)
{
    vector<Flight *> f;
    f = sortFlights(origin,destination,sortField,sortOrder);
    vector<Flight *>::iterator it;
    for(it=f.begin();it<f.end();it++)
    {
        cout<<(*it)->getName()<<" "<<(*it)->getOrigin()<<" "<<(*it)->getDestination()<<" "<<(*it)->getDeparture()<<" "<<(*it)->getDuration()<<" "<<(*it)->numAvailableSeats()<<" "<<(*it)->getAirline().getPrice(*it)<<endl;
    }
}
bool Portal5001::buyTicket(BuyOption criteria, string airline)
{
    vector<Flight *> f;
    if(criteria==Earliest)
    {
        f = retTopFlight(Time,Ascending,airline);
    }
    else if(criteria==Latest)
    {
        f = retTopFlight(Time,Descending,airline);
    }
    else if(criteria==Cheapest)
    {
        f = retTopFlight(Price,Ascending,airline);
    }
    else
    {
        f = retTopFlight(Duration,Ascending,airline);
    }
    if(f.empty())
    {
        return false;
    }
    bool r = (f[0]->getAirline()).issueTicket(f[0]);
    return r;
}

void Portal5001::processUserInput(string inputFileName)
{
    string o,des,icrit,comm,iord,ibuy,preferred_airline,line;
    SortField crit;
    SortOrder ord;
    BuyOption buy;
    const char * temp = inputFileName.c_str();
    ifstream myfile;
    myfile.open(temp);
    myfile>>o>>des;
    map<string,SortField> m;
    m["Airline"] = Airlines;
    m["Time"] = Time;
    m["Duration"] = Duration;
    m["Price"] = Price;
    map<string,SortOrder> mo;
    mo["ascending"] = Ascending;
    mo["descending"] = Descending;
    map<string,BuyOption> mb;
    mb["cheapest"] = Cheapest;
    mb["earliest"] = Earliest;
    mb["latest"] = Latest;
    mb["fastest"] = Fastest;
    while(myfile>>comm)
    {
        if(comm=="sort")
        {
            myfile>>icrit>>iord;
            ord = mo[iord];
            crit = m[icrit];
            showFlights(o,des,crit,ord);
        }
        else
        {
            myfile>>ibuy;
            getline(myfile,line);
            if(line=="")
                preferred_airline = "";
            else
                preferred_airline = line.substr(1,line.length()-1);
            buy = mb[ibuy];
            bool r = buyTicket(buy,preferred_airline);
            if(r==false)
            {
                cout<<"No tickets available\n";
            }
        }
    }
    myfile.close();
    float r,p;
    int ticksold;
    for(unsigned int i=0;i<a.size();i++)
    {
        a[i]->getSalesStats(r,p);
        ticksold = a[i]->getNumSold();
        cout<<"Airline "<<a[i]->getName()<<" sold "<<ticksold<<" tickets with a total revenue of "<<r<<" and passenger kilometers of "<<p<<endl;

    }
}
