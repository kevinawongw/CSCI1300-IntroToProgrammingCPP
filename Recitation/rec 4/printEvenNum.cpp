// Author: Kevina Wong CS1300 Fall 2018
// Recitation: 104 – Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/kevinawongw/csci1300
// Recitation 4: printEvenNum

#include <iostream>
using namespace std; 

void printEvenNums(int num){ //name of the function
    int evenno=0; //defines evenno as zero
    while (evenno < num-1 ){ //loop while evenno is smaller than the number minus one
        evenno++; //evenno add one
        evenno++; //evenno add one
        cout << evenno << endl; //output statement
    }
    
}

int main (){
    printEvenNums(15); //test case 1
}