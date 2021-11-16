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

// Takes a string (username) and returns the number
// of books read by that user as an integer.

// Member Function: Problem 4 - getCountReadBooks


int Library :: getCountReadBooks(string username){
    int userIndex = -1;
    int count = 0;
    if (numBooks != 0 && numUser != 0 ){
        for (int i = 0; i < 200 ; i++){
            if (user[i].getUsername() == username){
                userIndex = i;
            }
        }    
        if (userIndex  == -1{ // if the username cannot be found in the user array
            cout << username << " does not exist in the database" << endl; //Output statement
            return -2; //return -1
        }
        for (int k = 0; k < 200; k++ ){
            int rating = user[userIndex].getRatingAt(k);
            if (rating != 0){
                count ++;
            } 
        }
        return count; 
    }    
    else{
        cout << "Database has not been fully initialized" << endl;
    }
}