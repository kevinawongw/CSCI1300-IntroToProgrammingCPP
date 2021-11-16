// CSCI1300 Fall 2018
// Author: Kevina Wong CS1300 Fall 2018
// Recitation: 104 – Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/kevinawongw/csci1300
// Recitation 6

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int getScores (string str, string arr[], int length){
   string splitted = str;
    int c =0;
    for (int i = 0; i < splitted.length() && c < length ;i++){
        if (splitted==" "){ 
            arr[c]=splitted.substr(0,i);
            c++;
            splitted = splitted.substr (i+1);
            i=0;
        }else if(i==splitted.length()-1){
            arr[c]=splitted;
            c++;
        }
    }
    int x =stoi(c);
    return x;
}
