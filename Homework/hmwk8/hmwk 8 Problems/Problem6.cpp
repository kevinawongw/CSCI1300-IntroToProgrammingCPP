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

// Takes a string (username) and returns True if the
// username is successfully added to the database.
// Otherwise, returns False.

// Member Function: Problem 6 - addUser
bool Library :: addUser (string username){
    if (numUser == 200){
        cout << "Database full" << endl;
        return false; 
    }
    for (int i = 0; i < 200; i++){
        string usernameAt = user[i].getUsername
        if (toupper (usernameAt) == toupper (username)){
            cout << username << "already exists in the database" << endl;
            return false;
        }
    }
    int Myratings [200] = {0};
    for (int k = 0; k < 1; k++){
        user temp (username, Myratings, 0);
        user [numUsers] = temp;    
    }
    numUsers ++;
    return true;
}