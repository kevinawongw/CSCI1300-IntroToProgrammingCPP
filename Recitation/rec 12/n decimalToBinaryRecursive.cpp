// Author: Kevina Wong CS1300 Fall 2018
// Recitation: 104 – Tillquist
// Cloud9 Workspace Editor Link:https://ide.c9.io/kevinawongw/hmwk2#openfile-README.md
// Recitation 12 - Problem # 1 (decimalToBinaryIterative)

#include <iostream>
#include <math.h>
using namespace std;


string decimalToBinaryRecursive(int number){
    if (number == 0){
        return "";
    }
    else{
        if (number % 2 == 0){
            return decimalToBinaryRecursive(number/2) + "0";
        }
        else{
            return decimalToBinaryRecursive(number/2)+ "1";
        }
    }
}
int main (){
    // cout << decimalToBinaryIterative(5);
    cout << decimalToBinaryRecursive(26);
}