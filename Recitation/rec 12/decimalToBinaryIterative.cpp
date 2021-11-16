// Author: Kevina Wong CS1300 Fall 2018
// Recitation: 104 – Tillquist
// Cloud9 Workspace Editor Link:https://ide.c9.io/kevinawongw/hmwk2#openfile-README.md
// Recitation 12 - Problem # 1 (decimalToBinaryIterative)

#include <iostream>
#include <math.h>
using namespace std;

string decimalToBinaryIterative(int number){
    if (number == 0){
        return "0";
    }
    string b;    
    while (number > 0){
        int a = number % 2;
        b = to_string(a) + b;
        if (a == 1){
            number = ((number-1)/2);
        }
        else {
            number = (number/2);
        }
    }
    return b;
}


int main (){
    cout << decimalToBinaryIterative(5);
    // cout << decimalToBinaryIterative(26);
}