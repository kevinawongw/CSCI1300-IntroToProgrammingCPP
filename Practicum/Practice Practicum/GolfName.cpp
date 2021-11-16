#include <iostream>
using namespace std;
string GolfName(int number){
    switch (number){
    case -2:
        return "EAGLE";
        break;
    case -1:
        return "BIRDIE";
        break;
    case 0:
        return "PAR";
        break;
    case 1:
        return "BOGIE";
        break;
    case 2:
        return "DOUBLE BOGIE";
        break;
    case 3:
        return "TRIPLE BOGIE";
        break;
    default:
        return "NO COMMENT";
        break;
    }
}

int main(){
    cout<< "enter number:";
    int number;
    cin >> number;
    GolfName(number);
}