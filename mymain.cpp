#include "Flight5001.h"
#include "Airline5001.h"
#include "Portal5001.h"
#include <iostream>
using namespace std;
class Portal5001;
class Airline5001;
class Flight5001;
int main()
{
    Portal5001 p1;
    Airline5001 a1(&p1);
    Flight5001 f("a","b","c","d",1.0,1.0,2,&a1);
    cout<<"a";
}
