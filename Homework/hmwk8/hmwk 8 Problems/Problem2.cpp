#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "Book.h"
#include "User.h"
#include "Library.h"
using namespace std;

// Takes a string (the name of the file to be read) and
// populates the users array. Returns the total
// number of users in users array as an integer

// Member Function: Problem 2 - readRatings
int Library :: readRatings(string fileName){
    string rt; //creates a string called rt
    ifstream file (fileName.c_str()); //classifies file as an ifstream
    if (file.is_open()){ //if file is open
        int i = 0; //defines an int i. make that equal to users
        while(getline(file, rt)){ //use the getline function to read through the file. put those strings into rt.
            string R[2]; //creates a new array if strings.
            split(rt, ',', R,2); //splits the strings in rt by the comma and put those new strings intoo the array R
            string usern = R[0]; //sets string usern to the array R[0]
            string rate = R[1]; // sets strung rate equal to R[1]
            string lineRating [50]; //Creates a new array calles lineRating.
            split(R[1], ' ', lineRating, 50); //splits R[1] which holds the string of ratings and splits it by the space then stores it in lineRating with the length of rowcap
            int Ratings = 0; // defines and delcares ratings as an int with the value zero.
            int intRates[50]; //creates an array with the size of 50
            for (int j =0; j<50; j++){
                intRates[j]=stoi(lineRating[j]);
                if(intRates[j]!=0){
                    Ratings++;
                }
            }
            User tempUser (usern, intRates, 50); //creates tempUser
            if (i < 200){ //if i is less then 200
            user [i] = tempUser; //set user at i equal to the tempUser
            cout << tempUser.getUsername() << "..." << endl; //output statement
            }
            else {
                break; //break
            }
            i++;
        } 
        file.close(); //close the file
        return i; //return i subtracted by users + 1
    } 
    else { //else (if the file cannot be opened)
        return -1;  // return -1
    }
}
