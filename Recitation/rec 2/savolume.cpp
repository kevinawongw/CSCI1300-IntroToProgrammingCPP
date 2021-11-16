#include <iostream>
#include <math.h>
using namespace std;


int main(){
    cout << "Enter a radius: " << endl; //output statement asks user to input a radius value
    float radius; //defines the raduis as a float 
    cin >> radius; //makes the radius an input
    float volume ; //defines the volume as a float 
    volume = (4.0/3.0) * M_PI * pow(radius, 3); //equation to find volume.
    cout << "volume: " << volume << endl; //output statement that states what the calculated volume is
   float surface_area ; // defines surface area as a float
    surface_area = 4.0 * M_PI * pow(radius, 2); //equation for surface area
    cout << "surface area: " << surface_area << endl; //output statement that states what surface area is
    return 0;    
}
