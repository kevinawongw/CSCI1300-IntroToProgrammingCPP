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

// Takes a string (the title of a book) and returns the
// average rating of the specified book as a double

// Member Function: Problem 5 - calcAvgRating

double Library :: calcAvgRating(string title){
    int bookIndex = -1;
    int sumRatings = 0;
    double usersRated = 0;
    if (numBooks!=0 || numUsers !=0){
        for (int i =0; i < 200 ; i++){
            if (book[i].getTitle() == title){
                bookIndex = i;    
            }
        }
        if (bookIndex == -1){
            cout << title << "does not exist in the database" << endl;
            return -2;
        }
        for (int i = 0; i < 200; i++){
            int ratingAt = user[i].getRatingAt(bookIndex);
            if (ratingAt !=0){
                sumRatings += ratingAt;
                usersRated ++;
            }
        }
        double avg = sumRatings/usersRated;
        return avg;
    } else {
        cout << "Database has not been fully initialized" << endl;
        return -1; 
    }    
}
