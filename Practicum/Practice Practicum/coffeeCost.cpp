#include <iostream>
#include <math.h>
using namespace std;

double CoffeeCost(int cups, double price){
    if (cups > 12){
        int rewards = cups/ 12;
        double cost = cups * price -(rewards*price);
        return cost;
    }
    else {
        double cost = cups*price;
        return cost;
    }
}

int main(){
    cout <<"How many cups? "<<endl;
    int cups;
    cin >> cups;
      cout <<"How much per cup? "<<endl;
    double price;
    cin >> price;
    CoffeeCost(cups, price);
}