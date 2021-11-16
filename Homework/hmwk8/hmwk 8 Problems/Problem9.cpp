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

// Takes a string username and prints the first 5 book
// recommendations from the most similar (other)
// user.

// Member Function: Problem 9 - getRecommendation
void Library :: getRecommendation(string username){
    if (numBooks == 0 || numUsers == 0){
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
    
    user mostSimilar;
    int lowestSsd = INT_MAX;
    int userRatingAt;
    int paramRatingAt;
    for (int i = 0; i < 200 < i++){
        if (user[userIndex]!= user[i]){
            int ssd=0;
            for (int k = 0; k < 50 , k++){
                userRatingAt = user[i].getRatingAt(k);
                paramRatingAt = user[userIndex].getRatingAt(k);
                ssd += pow (paramRatingAt-userRatingAt, 2);
            }
            if(ssd < lowestSsd){
                lowestSsd = ssd;
                mostSimilar = user[i];
            }
        }    
    }
    for (int k = 0; k< 200; k++){
        if (mostSimilar.getRatingAt(k)==3,4,5 && user[userIndex].getRatingAt(k) == 0){
            cout << book[k].getTitle() << " by " << book[k].getAuthor();
        }
    }
}
