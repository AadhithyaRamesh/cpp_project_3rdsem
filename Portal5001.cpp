
#include "Portal5001.h"

Portal5001::Portal5001()
{
    lo = "";
}
/*Flight * Portal5001::retTopFlight(SortField sortField,SortOrder SortOrder,string air = NULL)
{
    class myfunctor
    {
        SortField sortField;
        SortOrder sortOrder;
        public:
        myfunctor(SortField s,SortOrder so):sortField(s),sortOrder(so){}
        bool operator()(Flight * f1,Flight * f2)
        {
            bool answer;
            if(sortField==Airline)
            {
                answer = (f1->getAirline().getName().compare(f2->getAirline.getName())<0);
            }
            else if(sortField==Price)
            {
                answer = f1->getAirline().getPrice(f1)<f2->getAirline.getPrice(f2);
            }
            else if(sortField==Duration)
            {
                answer = f1->getDuration()<f2->getDuration();
            }
            else
            {
                answer = f1->getDeparture()<f2->getDeparture();
            }
            if(sortOrder==Descending)
                answer = !(answer);
            return answer;
        }
    };
    vector<Flight *> f;
    f.clear();
    if(air!=NULL)
    {
        vector<Airline *>::iterator cit;
        for(cit=a.begin();cit<a.end();cit++)
        {
            if(*cit.getName()==air)
            {
                *cit.findFlights(origin,destination,f);
            }
        }
        if(f==NULL)
        {
            vector<Airline *>::iterator cit;
            for(cit=a.begin();cit<a.end();cit++)
            {
                *cit.findFlights(origin,destination,f);
            }
        }
    }
    else
    {
        vector<Airline *>::iterator cit;
        for(cit=a.begin();cit<a.end();cit++)
        {
            *cit.findFlights(origin,destination,f);
        }
    }
    myfunctor retgreater(sortField,sortOrder);
    sort(f.begin(),f.end(),myfunctor(retgreater()));
    return f[0];
}*/
/*vector<Flight *> Portal5001::sortFlights(string origin, string destination, SortField sortField = Airline,SortOrder sortOrder = Descending)
{
    lo = origin;
    ld = destination;
    vector<Flight *> f;
    vector<Airline *>::iterator cit;
    for(cit=a.begin();cit<a.end();cit++)
    {
        *cit.findFlights(origin,destination,f);
    }
    class myfunctor
    {
        SortField sortfield;
        SortOrder sortOrder;
        public:
        myfunctor(SortField s,SortOrder so):sortfield(s),sortOrder(so){}
        bool operator()(Flight * f1,Flight * f2)
        {
            bool answer;
            if(sortField==Airline)
            {
                answer = (f1->getAirline().getName().compare(f2->getAirline.getName())<0);
            }
            else if(sortField==Price)
            {
                answer = f1->getAirline().getPrice(f1)<f2->getAirline.getPrice(f2);
            }
            else if(sortField==Duration)
            {
                answer = f1->getDuration()<f2->getDuration();
            }
            else
            {
                answer = f1->getDeparture()<f2->getDeparture();
            }
            if(sortOrder==Descending)
                answer = !(answer);
            return answer;
        }
    };
    myfunctor retgreater(sortField,sortOrder);
    sort(f.begin(),f.end(),myfunctor(retgreater()));
    return f;
}*/
void Portal5001::initRoutes(string routeInfo)
{
    const char * temp = routeInfo.c_str();
    ifstream myfile;
    myfile.open(temp);
    while(!myfile.eof())
    {
        string o,des;
        float dis,dur,minp,maxp,dev;
        myfile>>o>>des>>dis>>dur>>minp>>maxp>>dev;
        Route5001 * tr =  new Route5001(o,des,dis,dur,minp,maxp,dev);
        r.push_back(tr);
    }
    void close();
}
void Portal5001::addAirline(Airline* airline)
{
    a.push_back(airline);
}
void Portal5001::routeInfo(string origin, string destination, float& dist, float& duration,float& minPrice, float& maxPrice, float& timeVariation)
{
    vector<Route5001 *>::iterator cit;
    for(cit = r.begin();cit<r.end;cit++)
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
void Portal5001::showFlights(string origin, string destination, SortField sortField = Airline,SortOrder sortOrder = Descending)
{
    vector<Flight *> f;
    f = sortFlights(origin,destination,sortField,sortOrder);
    vector<Flight *>::iterator it;
    for(it=f.begin();it<f.end();it++)
    {
        cout<<(*it)->getOrigin()<<" "<<(*it)->getDestination<<" "<<(*it)->getDeparture()<<" "<<(*it)->getDuration()<<" "<<(*it)->getairline.getPrice(*it)<<endl;
    }
}
bool Portal5001::buyTicket(BuyOption criteria, string airline = NULL)
{
    Flight *f;
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
    bool r = f->getAirline.issueTicket(f);
    return r;
}

void Portal5001::processUserInput(string inputFileName)
{

    string o,des,icrit,comm,iord;
    SortField crit;
    SortOrder ord;
    fstream myfile;
    myfile.open(inputFileName,ios::in);
    myfile>>o>>des;
    map<string,SortField> m;
    m["Airline"] = Airline;
    m["Time"] = Time;
    m["Duration"] = Duration;
    m["Price"] = Price;
    map<string,SortOrder> mo;
    mo["Ascending"] = Ascending;
    mo["Descending"] = Descending;
    while(!myfile.eof())
    {
        myfile>>comm>>icrit>>iord;
        ord = mo[iord];
        crit = m[icrit];
        if(comm=="sort")
        {
            showFlights(o,des,crit,ord);
        }
        else
        {
            buyTicket(crit,ord);
        }
    }
}
