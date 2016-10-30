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
string Route5001::string retOrigin()
{
    return origin;
}
string Route5001::string retDestination()
{
    return destination;
}
float Route5001::string retminp()
{
    return min_price;
}
float Route5001::string retmaxp()
{
    return max_price;
}
float Route5001::string retdev()
{
    return deviation;
}
float Route5001::string retdis()
{
    return distance;
}
float Route5001::string retdur()
{
    return duration;
}
