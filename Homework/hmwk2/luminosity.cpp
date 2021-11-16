// Author: Kevina Wong CS1300 Fall 2018
// Recitation: 104 – Your TA
// Cloud9 Workspace Editor Link:https://ide.c9.io/kevinawongw/hmwk2#openfile-README.md
// Homework 2 - Problem # 4 (luminosity)

#include <iostream>
#include <math.h>
using namespace std; 
/**
* Algorithm: find the luminosity
* 1. brightness = input 
* 2. distance = input
* 3. output= population
* 4. L=4*brightness*pi*distance^2
* Output: "Population Value:"
* Returns: nothing
*/

int luminosity (double brightness, double distance){
    double luminosity = 4*brightness*3.14159* pow(distance, 2); //luminosity equation
    return luminosity;
}


int main()
{
    cout << luminosity (12, 12) << endl; //test case 1 
    cout << luminosity (15, 20) << endl; //test case 2
}






