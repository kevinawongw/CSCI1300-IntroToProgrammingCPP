// Author: Kevina Wong CS1300 Fall 2018
// Recitation: 104 – Your TA
// Cloud9 Workspace Editor Link:https://ide.c9.io/kevinawongw/hmwk2#openfile-README.md
// Homework 2 - Problem # 1 (convertSeconds)

#include <iostream>
#include <math.h>
using namespace std; 

///**
//* Algorithm: convert the seconds to hours and minutes 
//* 1. Define that one hour is 3600 seconds 
//* 2. Define that one minute is 60 seconds. 
//* 3. Divide the seconds by 3600 and get an interger value of how many hours. 
//* 4. Change the definition of seconds to make seconds equal to seconds minus the number of hours times 3600. 
//* 5. Divide the new seconds by 60 and get an interger value of how many minutes. 
//* 6. Redefine seconds to make it equal to seconds minus the number of minutes times 60.
//* Input parameters: seconds (interger)
//* Output: x hour(s) y minute(s) z second(s)
//* Returns: nothing
//*/


void convertSeconds (int seconds){
    int X = seconds/3600; //finds x hours
    seconds = seconds -(X*3600); //finds remainder of seconds after finding x hours 
    int Y = seconds/60; //finds y minutes 
    seconds = seconds -(Y*60); //finds remainder of y minutes
    int Z = seconds; //find remainder seconds
    cout << X << " hour(s) " << Y << " minute(s) " << Z << " second(s)" << endl; //output statement
}

int main ()
{
    cout << "Enter seconds: " << endl;
    convertSeconds(305); 
    convertSeconds(605); 
}

