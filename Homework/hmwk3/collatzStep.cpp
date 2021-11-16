// Author: Kevina Wong CS1300 Fall 2018
// Recitation: 104 – Your TA
// Cloud9 Workspace Editor Link: https://ide.c9.io/kevinawongw/csci1300
// Homework 3: CollatzStep

#include <iostream>
#include <math.h>
using namespace std; 

/*
*If it's an even number, number divide by two
*If it's an odd number, number *3+1
*Use if statements
*/

int collatzStep (int number) //function collatzStep
{
    if (number == 0) // if the number is equal to zero
    {
        return 0; //return 0
    }
    if (number > 0 && number % 2 ==0) // if the number is greater than 0 and divisible by 2
    {
        int out = number/2; //divide number by two
        cout << out << endl; //output statement (on moodle autograder, I typepd return out;)
    }
    else if (number > 0 &&number %2 !=0) //if the number is greater than zero and not divisible by two
    { 
        int out = (3*number)+1; //multiply the number by three and add one
        cout << out << endl; //output statement (on moodle autograder, I typepd return out;)
    }
    else if (number < 0) //if the number is smaller than 0
    {
        return 0; //return zero
    }
}

int main (){ //main func
    collatzStep(342); //Test case 1 (expected 171)
    collatzStep(27); //Test case 2 (expected 82)
    //These test cases were chosen to test one odd and one even number.
}