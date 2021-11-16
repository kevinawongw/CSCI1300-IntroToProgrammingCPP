// Author: Kevina Wong CS1300 Fall 2018
// Recitation: 104 – Your TA
// Cloud9 Workspace Editor Link:https://ide.c9.io/kevinawongw/hmwk2#openfile-README.md
// Homework 2 - Problem # 2 (celsiusToFahrenheit)

#include <iostream>
#include <math.h>
using namespace std;

/**
* Algorithm: convert the celsius to fahrenheit.  
* 1. Temperature in Celsius (int) = Input (“What is the celsius given the fahrenheit?”)
* 2. Fahrenheit = (9/5)*Celsius + 32  
* 3. Output = "The temperature of (input) in fahrenheit is (celsius)"
* Input: Celsius (int)
* Output: Fahrenheit (float) 
* Returns: nothing
*/


void celsiusToFahrenheit (int tempInCelsius){
    float Fahrenheit = ((9.00/5.00)*tempInCelsius)+32.00;
    cout << "The temperature of " << tempInCelsius << " in fahrenheit is " << Fahrenheit << endl; //output statement
}

int main()
{
    celsiusToFahrenheit(22); //test case 1
    celsiusToFahrenheit(15); //test case 2
}



