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

// Takes a string (username) and prints all the books
// a user has provided ratings for.

// Member Function: Problem 8 - viewRatings

void Library :: viewRatings(string username){
    int userIndex = -1;
    if (numBooks == 0 || numUsers ==0){
        cout << "Database has not been fully initialized" << endl;
    } 
    for (int i = 0; i < 200; i++){
        string usernameAt = user[i].getUsername
        if (toupper (usernameAt) == toupper (username)){
            userIndex = i;
        }
    }
    if (userIndex == -1){
        cout << username << "does not exist in the database" << endl;
    }
    if (user[i].getNumRatings() == 0) {
        cout << username << "has not rated any books yet" << endl;
    }
    cout << "Here are the books that " << username << " rated " << endl;
    for (int i = 0; i < 200; i++){
        (if user[userIndex].getRatingAt (i) != 0){
            cout << "Title: " << book[i] << endl;
            cout << "Rating: " << user[userIndex].getRatingAt(i) << endl;
            cout << "-----" << endl;
        }
    }
}
