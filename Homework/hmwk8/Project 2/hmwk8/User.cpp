
// CSCI1300 Fall 2018
// Author: <Kevina Wong>
// Recitation: <123> – <Richard Tillquist>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/kevinawongw/csci1300>
// hmwk7 - user.cpp file

//Function Declarations
#include "User.h"

User :: User(){ //look into user class and find the default constructor
    string username = ""; //sets username to an empty string
    numRatings = 0; // deifnes numRatings to zero
    size = 200; //defines the suze to be 200
    for (int i = 0; i < 200; i++ ){ //iterate
        ratings[i] = -1; //for all elements in the array, assign to -1
    }
}

User :: User(string Myusername, int Myratings [200], int MynumRatings){ //parameterized constructor
    username = Myusername; //set username equal to username
    for (int i = 0; i < 200; i++){ //iterate
        ratings [i] = Myratings[i]; // set ratings is equal to ratings at every index
    }
    numRatings=MynumRatings; //set numratings equal to numratings
}

string User :: getUsername(){ //get username
    return username; //return
}
void User :: setUsername(string Myusername){ //set username
    username = Myusername; //set username to username
}
int User :: getRatingAt(int index){ //get rating at
    int ratingAt; //declares a new variable called ratingAt as an interger
    if (index >= 200){ //if index is greater then or equal to 50 (edge case)
        return -1; //return -1
    }    
    else {
        return ratings[index]; //return the rating at index
    }
}
bool User :: setRatingAt(int index, int value){ //set rating as
    if (index < 200 && value >= 0 && value <=5){ // if the index is less than 200 and the vakue is between zero and five
        ratings [index] = value; // the ratings at the index is equal to the value
        return true; //bool: return true
    }
    else{
        return false; //bool: return false
    }
}
int User :: getNumRatings(){ //get numRatings
    return numRatings;  // return 
}
void User :: setNumRatings (int MynumRatings){ //set numRatings
    numRatings = MynumRatings; // setnumRatings equal to numRatings
}
int User :: getSize (){ //getsize
    return size; //return
}