#include <iostream>
#include <math.h>
using namespace std;

double calculateCost (double distance, double avgSpeed, double gasPrice){
    if (avgSpeed>62 && distance > 0 && avgSpeed >0 && gasPrice >0){
        double tripCost = (distance / 26 ) * gasPrice;
        return tripCost;
        //cout << tripCost << endl;
    }
    else {
        double tripCost = (distance / 30 ) * gasPrice;
        return tripCost;
        //cout << tripCost << endl;
    }
}

int main (){
    cout << "enter a"<< endl;
    double distance;
    cin >> distance;
    cout << "enter b"<< endl;
    double avgSpeed;
    cin >> avgSpeed;
    cout << "enter c"<< endl;
    double gasPrice;
    cin >> gasPrice;
}