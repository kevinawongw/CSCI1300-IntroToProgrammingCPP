// Author: Kevina Wong CS1300 Fall 2018
// Recitation: 104 – Your TA
// Cloud9 Workspace Editor Link: https://ide.c9.io/kevinawongw/csci1300
// Homework 3; daysOfMonth

#include <iostream>
using namespace std;
/*
*Use a switch case
*The number input is the month ( for example, January is 1, February is 2...)
*For inputs 1,3,5,7,8,10,12, ouput a statement that says that Month __ has 31 days.
*For inputs 4,6,9,11 , output a statement that says that Month __ has 30 days.
*For input 2, output a statement that Month 2 has 28 or 29 days.
*Make a default case for if a number was inputted that was not 1-12. State that it is an invalid month number
*/

/**
 * daysOfMonth
 * Uses a switch case to output how many days are in a month.
 */
 
void daysOfMonth(int month){
    switch (month) //switch
    {
        case 1://for month 1
        case 3://for month 3
        case 5://for month 5
        case 7://for month 7
        case 8://for month 8
        case 10://for month 10
        case 12://for month 12
            cout << "Month " << month << " has " << " 31 days " << endl; //output statement
            break; 
        case 4: //for month 4
        case 6: //for month 6
        case 9: //for month 9
        case 11://for month 11
            cout << "Month " << month << " has " << " 30 days " << endl; //output statement 
            break;
        case 2: //for month two
            cout << "Month " << month << " has 28 or 29 days " << endl; //output statement
            break;
        default: //if non of the above cases are true
            cout << "Invalid month number" << endl; //output statement
            break;
    }
}
int main (){ // main func
    daysOfMonth(1); //Test Case 1 (expect "Month 1 has 31 days")
    daysOfMonth(11); //Test Case 1 (expect "Month 11 has 30 days")
    daysOfMonth(13); //Test Case 1 (expect "Invalid month number")
    //These test cases were chosen to test different cases.
    
}