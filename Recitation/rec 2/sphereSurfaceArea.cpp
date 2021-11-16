#include <iostream>
#include <math.h>
using namespace std;

void sphereSurfaceArea( float radius){ //function called sphereSurfaceArea
    float surface_area = 4.0*M_PI*pow(radius,2); //equation for sa and also defines sa is a float
    cout << "surface area: " << surface_area << endl; //output statement
}

int main(){ //main func
    float radius; //defines the radius as a float
    cout << "Enter Radius" << endl; //statement that asks user to input a value.
    cin >> radius; //defines the radius value as an inout
    sphereSurfaceArea(radius); 
}