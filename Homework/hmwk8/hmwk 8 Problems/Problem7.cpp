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

// Takes two strings and an integer for username, title
// of book, and a new rating, respectively (in this
// order). Returns True if the rating is successfully
// updated. Otherwise, returns False.

// Member Function: Problem 7 - checkOutBook
bool Library :: checkOutBook (string username, string title, int newRating){
    int bookIndex = -1;
    int userIndex = -1;
    if (numUsers == 0 || numBooks == 0){
        cout << " Database has not been fully intitialized" << endl;
        return false;
    }
    
    for (int i = 0; i < 200 ; i++){
        if (user[i].getUsername() == username){
            userIndex = i;
        }
    if (userIndex == -1){
        cout << username << "does not exist in the database" << endl;
        return false;
    }
    for (int k =0; k < 200 ; k++){
        if (book[i].getTitle() == title){
            bookIndex = k;    
        }
    if (bookIndex == -1){
            cout << title << "does not exist in the database" << endl;
            return false;    
    }
    if (newRating == 0 || newRating > 5){
        cout << newRating << "is not valid" << endl;
        return false;
    }
    user[userIndex].setRatingAt(bookIndex, newRating);
    return true;
}