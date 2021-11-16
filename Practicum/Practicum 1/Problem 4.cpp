#include <iostream>
#include <math.h>
using namespace std;

double largestNumber(double a, double b, double c){
    if (a > b && a >c){
        return a;
        if (a==b || a ==c){
        return a;
        }
        cout << a;
    }
    else if (b>a && b>c){
        return b;
        if (b==a || b ==c){
        return b;
        }
        cout << b;
    }
    else if (c>a && c>b){
        return c;
        if (c==a||c==b){
            return c;
        }
        cout << c;
    }
}

int main(){
    largestNumber(6,6.0,2.5);
}