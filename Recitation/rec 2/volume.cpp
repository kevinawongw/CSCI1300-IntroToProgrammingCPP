#include <iostream>
#include <math.h>
using namespace std;

void sphereVolume (float radius){ //function
    float volume = (4.0/3.0)*M_PI*pow(radius, 3); //equation for volume. It also defines volume as a float
    cout << "volume: " << volume << endl; //output statement that states the volume
}

int main(){
    float radius; //defines radius as a float 
    cout << "Enter Radius" << endl; //statement that tells the user to enter a radius
    cin >> radius; //input radius
    sphereVolume(radius); 
}