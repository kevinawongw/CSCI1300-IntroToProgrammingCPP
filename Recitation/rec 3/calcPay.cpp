#include <iostream>
#include <math.h>
using namespace std;

double calcPay(double hours,double rate){ //function calcPay
    if (hours == 0) //if hours is 0
    {
    cout << "Total Pay: " << 0 << endl;
    }
    else if (hours < 0||rate < 0) //if hours is less than zero and 
    {
    cout << "Pay rate and hours worked cannot be negative values." << endl; //output statement if hours or pay rate is negative
    }  
    else if (hours <= 40 && hours > 0) //if hours is less than or equal to 40 and hours are greater thana zero
    {
    cout << "Total Pay: " << hours*rate << endl;

    }
    else if (hours > 40) //if hours is greater than fourty
    {
    double paybase= 40*rate; //the paybase can be found by multiplying fourty by rate
    double over = (hours - 40)*(rate*1.5); // the over pay can be found by subtracting hours by fourty and then multiplying the rate multiplied by 1.5
    cout << "Total Pay: " << over << endl;
    }
    
} 

int main (){ //main function
    double hours; //defines hours as a double
    double rate; //defines rate as a double
    cout << "Enter hours"; //statement tells user to input hours
    cin >> hours; //makes hours an inout
    cout << "Enther rate"; //statement tells user to input rate
    cin >> rate; //makes rate an input
    calcPay(hours, rate); //function calcPay
}