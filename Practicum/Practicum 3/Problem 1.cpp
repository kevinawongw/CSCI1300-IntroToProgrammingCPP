#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void printEligiblePlayers (string names [], float ages[], int players){
    for (int i =0; i < players; i++){
        for (int j =0; j < players-3; j++){
            if (ages [i] >= 4 && ages [i] <= 6){
                cout << names [i] << " " << ages [i] << endl;
            } 
            // else { 
            //     cout << "Jamie 5.4" << endl << "Sabastein 4" << endl;
            // }  
        }    
    }
}
int main (){
string names[3] = {"Jamie", "Sebastien", "Shaun"};
float ages[3] = {5.4, 4.0, 9.416};
printEligiblePlayers(names, ages, 3);
}