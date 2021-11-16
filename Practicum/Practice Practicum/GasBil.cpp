#include <iostream>
#include <math.h>
using namespace std;



double GasBill( int unit){

    if (unit ==0){
        return 0;
    }
    else if (unit <0 ){
        cout << "Incorrect input" << endl;
        return 0;
    }
    else if ( unit > 0 && unit <= 100){
        double cost = unit * 1.23;
        return cost;
    }
    else if (unit > 100 && unit <= 200 ){
        double cost = (100*1.23) + (unit-100)*1.14;
        return cost;
    }
    else if (unit>200){
        int x= unit-200;
        double cost = (100*1.23) + (100)*1.14 + (unit-200)*1.08;
        return cost;
    }
}
int main(){
    cout <<"How many units of gas do you want to fil?" << endl;
    int unit;
    cin >> unit;
    GasBill(unit);
}