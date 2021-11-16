// Author: Kevina Wong CS1300 Fall 2018
// Recitation: 104 –Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/kevinawongw/csci1300
// Recitation 4: printMultiples

#include <iostream>
#include <math.h>
using namespace std;

void printMultiples(int num, int max){
int multiple;    
int a= 1;
    while (multiple <=  max-num){
        multiple = num * a++;
        cout << multiple << endl;
    } 
}

int main (){
    int num;
    int max;
    cout << "Input num:" << endl;
    cin >> num;
    cout << "Input max:" << endl;
    cin >> max;
    printMultiples(num,max);
}
