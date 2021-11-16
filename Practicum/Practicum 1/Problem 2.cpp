#include <iostream>
#include <math.h>
using namespace std;

string mileage(int flightDistance){
    if (flightDistance < 0){
        return "INVALID";
    }
    else if (flightDistance >= 0 && flightDistance <= 10000){
        return "Bronze";
    }
    else if (flightDistance >= 10001 && flightDistance <= 15000){
         return "Silver";
    }
    else if (flightDistance >= 15001 && flightDistance <= 30000){
         return "Gold";
    }
    else if (flightDistance > 30000){
         return "Platinum";
    }
}