#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void printEligibleAthletes (string athletes[],float ages [],int numAthletes){
    for (int i=0; i<numAthletes;i++){
        if (ages[i]>=14 && ages[i]<=18){
            cout << athletes[i] << ", " << ages[i]<< endl;
        }
    }
}

int main (){
string names[3] = {"Jamie", "Sebastien", "Shaun"};
float ages[3] = {15.4, 14.0, 9.416};
printEligibleAthletes(names, ages, 3);
}