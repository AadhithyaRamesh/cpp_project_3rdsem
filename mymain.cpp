#include "Flight5001.h"
#include "Airline5001.h"
#include "Portal5001.h"
#include <iostream>

int main()
{
    Airline5001 a1(& p1);
    Flight5001 f("a","b","c","d",1.0,1.0,2,&a1);
    cout<<"a";
}
