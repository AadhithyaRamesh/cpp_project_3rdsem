#ifndef ROUTE5001_H_INCLUDED
#define ROUTE5001_H_INCLUDED

class Route5001
{
    string origin,destination;
    float distance,duration,min_price,max_price,deviation;
public:
    Route5001(string o,string des,float dis,float dur,float minp,float maxp,float dev);
    string retOrigin();
    string retDestination();
    float retminp();
    float retmaxp();
    float retdev();
    float retdis();
    float retdur();
};


#endif // ROUTE5001_H_INCLUDED
