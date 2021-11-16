// Author: Kevina Wong CS1300 Fall 2018
// Recitation: 104 – Your TA
// Cloud9 Workspace Editor Link: https://ide.c9.io/kevinawongw/csci1300
// Homework 3: countDigits

#include <iostream>
#include <math.h>
using namespace std;

/*
*If a number has one digit, it should be less than 10 
*If a number has two digits, it should be less than 100 and greater than 9.
*If a number has three digits, it should be greater than 99 and less than 1000.
*Using this patterns I put in if statements
*If theres one digit, output 1, if theres two 2 digits output 2...
*/

/**
 *countDigits
 *checks to see how many digits are in a number.
 */
 
int countDigits(int number){ //function countDigits
    if (number==0) //if the number is equal to zero
    {
        cout << 1 << endl; //output statment (this isn't in my code for moodle)
        return 1; //return 1
    }
    else if (abs(number) >= 0 && abs(number) <=9) //if the adsolute value of the number is greater or equal to zero and less than or equal to 9
    {
        cout << 1 << endl; //output statment (this isn't in my code for moodle)
        return 1; //return 1
    }
    else if (abs(number) >= 10 && abs(number) <=99) //if the absolute value of the number is greater or equal to ten and less than or equal to 99
    {
        cout << 2 << endl;//output statment (this isn't in my code for moodle)
        return 2; //return 2
    }
    else if (abs(number) >= 100 && abs(number) <=999) //if the absolute value of the number is greater or equal to 100 and less than or equal to 999
    {
        cout << 3 << endl; //output statment (this isn't in my code for moodle)
        return 3; //return 3
    }
}

int main() { //main func
    countDigits(125); //Test Case 1 (expect "3")
    countDigits(21); //Test Case 1 (expect "2")
}