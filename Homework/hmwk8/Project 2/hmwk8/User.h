// CSCI1300 Fall 2018
// Author: <Kevina Wong>
// Recitation: <123> – <Richard Tillquist>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/kevinawongw/csci1300>
// hmwk7 - user.h file

//Function Definitions
//Function Declarations
#include <iostream>
#include <string>
using namespace std;


#ifndef USER_H
#define USER_H
class User{ //creates a class user
    public: // member functions
    User (); //default constructor
    User (string Myusername, int Myratings [], int MynumRatings); //parameterized constructor
    
    string getUsername(); //username getter
    void setUsername(string Myusername); //username setter
    int getRatingAt(int index); //ratingAt getter
    bool setRatingAt(int index, int value); //ratingAt setter
    int getNumRatings(); //numRatings getter
    void setNumRatings (int MynumRatings); //numratings setter
    int getSize ();//size getter
    
    private: //data members
    string username; //declares username as a string
    int ratings [200]; //declares rating as an array with a size of 200
    int numRatings; //declareas numRating as an int
    int size; // declares size as an int

};
#endif