#include "Flight5001.h"
#include "Airline5001.h"
#include "Airline5001b.h"
#include "Portal5001.h"
#include <iostream>
using namespace std;
int main()
{
    Portal5001 p1;
    p1.initRoutes("C:/github local reps/cpp_project_srdsem/routes.txt");
    Airline5001 a1(&p1);
    Airline5001b a2(&p1);
    a1.init("C:/github local reps/cpp_project_srdsem/airline1.txt");
    a2.init("C:/github local reps/cpp_project_srdsem/airline1.txt");
    p1.processUserInput("C:/github local reps/cpp_project_srdsem/userInput.txt");
}
