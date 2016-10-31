#include "Route5001.h"


Route5001::Route5001(string o,string des,float dis,float dur,float minp,float maxp,float dev)
{
    origin = o;
    destination = des;
    distance = dis;
    duration = dur;
    min_price = minp;
    max_price = maxp;
    deviation = dev;
}
string Route5001::retOrigin()
{
    return origin;
}
string Route5001::retDestination()
{
    return destination;
}
float Route5001::retminp()
{
    return min_price;
}
float Route5001::retmaxp()
{
    return max_price;
}
float Route5001::retdev()
{
    return deviation;
}
float Route5001::retdis()
{
    return distance;
}
float Route5001::retdur()
{
    return duration;
}
