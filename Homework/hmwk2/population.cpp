// Author: Kevina Wong CS1300 Fall 2018
// Recitation: 104 – Your TA
// Cloud9 Workspace Editor Link:https://ide.c9.io/kevinawongw/hmwk2#openfile-README.md
// Homework 2 - Problem # 3 (population)

#include <iostream>
#include <math.h>
using namespace std; 

/**
* Algorithm: calculate the US population
* 1. Year = input (“What is the US Population?”)
* 2. Population= (2,482,000) * year + initial
* 3. output= population
* Input: initial population (int)
* Returns: population
*/

int population (int initial){
    int population = (2482000)*1 + initial; //final population equation
    return population; 
}

int main (){ 
    cout << population(2500) << endl; //test case 1
    cout << population(1)<< endl; //test case 2
}





