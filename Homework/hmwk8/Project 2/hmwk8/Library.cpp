// CSCI1300 Fall 2018
// Author: <Kevina Wong>
// Recitation: <123> – <Richard Tillquist>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/kevinawongw/csci1300>
// hmwk7 - Library.cpp file

#include <iostream>
#include <string>
#include "Book.h"
#include "User.h"
#include "Library.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cctype>
using namespace std;
/* split function
 * the function to split the given string into array of string with respect to a delimiter
 *
 * @param : string , the string we are going to split
 * @param : char, the delimiter
 * @param : string array, the array of string we save after spliting
 * @param : int, size of the  indicates the maximum number of split-apart string pieces
*/
 
int split (string str, char c, string array[], int size)
 {
    if (str.length() == 0) {
         return 0;
     }
    string word = "";
    int count = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return count ;
 }


// Default Constructors:
Library :: Library (){
    numBooks = 0;
    numUsers = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////// 
 
// Member Function: Problem 1 - readBooks

/** readBooks Function:
 * @param: string fileName
 * Open the file. If the file cannot be opened, return-1.
 * Get every line in the file 
 * Split the lines by the comma to split it by book titles and book authors.
 * Fill in each data into the a new book object each time (populate the book array with all of the books in the file).
 * Return the number of books in the file. 
 **/

int Library :: readBooks(string fileName){
    const int sizeBook = 200; //defines and declares numberBooks as a const int and set to 200. 
    string booksAndAuthors; //defines a new string called booksAndAuthors
    ifstream file (fileName.c_str()); //makes file in an ifstream 
    int i = numBooks; //defines stored books as an interger.
    if (file.is_open()){ //if file is open
        while(getline(file, booksAndAuthors)){ //use getline function
            string BaA[2]; //creates a new array with the size of 2
            split(booksAndAuthors, ',', BaA,2); //splits the file 
            string bookname = BaA[1]; //sets the book string equal to the array
            string author = BaA[0]; //sets the author string equal to the array
            Book tempBook(bookname,author); //creates a book called tempbook 
            if (i < sizeBook ){ //if i is less than capacity
                book[i] = tempBook; //sets the book array equal to tempbook
            }
            else {
                break; //break
            }
            i++; //i+1
        }
        file.close(); //close the file 
        numBooks = i;
        return i; //return i subtracted by temp
    }
    else {
        return -1; //return -1
    }
    numBooks = i;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

// Member Function: Problem 2 - readRatings

/**readRating Function:
 * @param: string fileName
 * Open the file. If the file cannot be opened, return -1.
 * Get everyline in the file. 
 * Split the lines in the file by the comma, which splits the lines by user and their list of ratings.
 * Fill each user object with the data (username and ratings) for each user and fill the user array with all of the users. 
 * Write an output statement of each user's username followed by a "..."
 * Return the number of users in the file.
 **/

int Library :: readRatings(string fileName){
    string rt; //creates a string called rt
    ifstream file (fileName.c_str()); //classifies file as an ifstream
    if (file.is_open()){ //if file is open
        int i = numUsers; //defines an int i. make that equal to users
        while(getline(file, rt)){ //use the getline function to read through the file. put those strings into rt.
            string R[2]; //creates a new array if strings.
            split(rt, ',', R,2); //splits the strings in rt by the comma and put those new strings intoo the array R
            string usern = R[0]; //sets string usern to the array R[0]
            string rate = R[1]; // sets strung rate equal to R[1]
            string lineRating [200]; //Creates a new array calles lineRating.
            split(R[1], ' ', lineRating, 200); //splits R[1] which holds the string of ratings and splits it by the space then stores it in lineRating with the length of rowcap
            int Ratings = 0; // defines and delcares ratings as an int with the value zero.
            int intRates[200]; //creates an array with the size of 50
            for (int j =0; j<200; j++){
                if(lineRating[j] == ""){
                    continue;
                }else{
                    intRates[j]=stoi(lineRating[j]);
                    if(intRates[j]!=0){
                        Ratings++;
                    }
                }
                
            }
            User tempUser (usern, intRates, 200); //creates tempUser
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
        numUsers = i;
        return i; //return i subtracted by temp
    } 
    else { //else (if the file cannot be opened)
        return -1;  // return -1
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

// Member Function: Problem 3 - printAllBooks

/** printAllBooks Function:
 * Check to make sure the database is initialized. 
 * Print out a list of bookos and their authors.
 **/

void Library :: printAllBooks(){
    if (numBooks ==0){ //if the number of books is equal to zero
        cout << "Database has not been fully initialized" << endl << endl; //Output statement
    }else{
        cout << "Here is a list of books" << endl; //Output statement
        for(int i = 0; i < numBooks; i++){ //for loop (iteration)
            cout << book [i].getTitle() << " by " << book [i].getAuthor() << endl; //Output statement
        }
        cout << endl; // endline
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

// Member Function: Problem 4 - getCountReadBooks

/** getCountReadBooks Function:
 * @param: string username
 * Make sure the database is intitialized
 * Find the username in the User array
 * If the user cannot be found, return -2.
 * Loop through to count how many books the user has rated
 * Return the number of books.
 **/

int Library :: getCountReadBooks(string username){
    int userIndex = -1; //declare and define userIndec as an int equal to -1
    int count = 0; //declare and define count as an int and equal to 0
    if (numBooks != 0 && numUsers != 0 ){ //If numBooks and numUser is not equal to zero (Makes sure the database is initialized). 
        for (int i = 0; i < 200 ; i++){ //iteration
            if (toUpperCase (user[i].getUsername()) == toUpperCase(username)){ // if the username at the index is the same as the username
                userIndex = i; //this is the index that the user is found
            }
        }    
        if (userIndex  == -1){ // if the username cannot be found in the user array
            cout << username << " does not exist in the database" << endl; //Output statement
            return -2; //return -2
        }
        for (int k = 0; k < 200; k++ ){ //iteration
            int rating = user[userIndex].getRatingAt(k); //gets each rating for the user
            if (rating > 0 && rating <= 5){ //if the rating is not equal to zero
                count ++; //count =+1
            } 
        }
        return count; //return count
    }    
    else{
        cout << "Database has not been fully initialized" << endl; //output statement
        return -1;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

// Member Function: Problem 5 - calcAvgRating
 
/** calcAvgRating Function:
 * @param: string title
 * Check too make sure database is initialized 
 * Look for the book title in the book array
 * If the book has been found, find out what number index it is in the book array
 * Find its rating for that book for each user in the database
 * Sum together those ratings then divide by the number of users that rated that book.
 * If the book hasn't been found return -2
 * Return the average
 **/

double Library :: calcAvgRating(string title){
    int bookIndex = -1; //declares and defines book index
    int sumRatings = 0; //declares and defines sumRatings
    double usersRated = 0; //declares and defines usersRated
    if (numBooks!=0 || numUsers !=0){ //makes sure database is initialized
        for (int i =0; i < 200 ; i++){ //iteration
            if (toUpperCase(book[i].getTitle()) == toUpperCase(title)){ //if the book title at i is equal to title
                bookIndex = i; //this is the index that the book is found
            }
        }
        if (bookIndex == -1){ //if bookIndex is equal to -1
            cout << title << " does not exist in the database" << endl; //output statement (that book could'nt be found in that list of books)
            return -2; //return -2
        }
        for (int i = 0; i < 200; i++){ //iteration
            int ratingAt = user[i].getRatingAt(bookIndex); //get the ratings for that book for every user
            if (ratingAt !=0 && ratingAt != -1){ //if the rating is not equal to zero
                sumRatings += ratingAt; //sum up the ratings 
                usersRated ++; //usersRated +1
            }
        }
        double avg = sumRatings/usersRated; //sumratings divided by userRated
        return avg; //return avg
    } else {
        cout << "Database has not been fully initialized" << endl; //output statement
        return -1; //return -1
    }    
}

///////////////////////////////////////////////////////////////////////////////////////////////////

// Member Function: Problem 6 - addUser

/** addUser Function:
 * @param: string username
 * Check if the username already exists. If it does, return false.
 * Check if the user array is already full. If it is, return false. 
 * Create a temporary user and fill in the username and ratings for the temporary user. 
 * Add one to numUsers to update the number of users in the array
 **/

bool Library :: addUser (string username){ 
    if (numUsers == 200){ //if numUser is equal to 200 
        cout << "Database full" << endl; //output statement
        return false; // return false
    }
    for (int i = 0; i < 200; i++){ //iteration
        string usernameAt = user[i].getUsername(); //defines usernameAt as a string and sets that equal to the username for the user at i
        if (toUpperCase (usernameAt) == toUpperCase (username)){ //if the usernames are the same
            cout << username << " already exists in the database" << endl; //output statement
            return false; //return false
        }
    }
    int Myratings [200] = {0}; //sets every vlaue in the ratings array equal to 0
    for (int k = 0; k < 1; k++){ //iteration
        User temp (username, Myratings, 0); //creates a temp user and fills in the data with the username, the array of 0 ratings, and 0 ratings
        user [numUsers] = temp; //adds the temp user to the user array as a new user
    }
    numUsers++; //numUsers+1
    return true; //returns true
}

///////////////////////////////////////////////////////////////////////////////////////////////////

// Member Function: Problem 7 - checkOutBook
bool Library :: checkOutBook (string username, string title, int newRating){
    int bookIndex = -1; //sets bookIndex equal to -1
    int userIndex = -1; //sets userindex equal to -1
    bool userBool = true;
    bool titleBool = true;
    bool ratingBool = true;
    if (numUsers == 0 || numBooks == 0){ //if numUsers or numBooks are equal to zero
        cout << "Database has not been fully initialized" << endl; //output statement
        return false; //return false
    }
    
    for (int i = 0; i < 200 ; i++){ //iteration
        if (toUpperCase(user[i].getUsername()) == toUpperCase(username)){ //if the usernames are the same
            userIndex = i; //i is the userIndex
        }
    }
    if (userIndex == -1){ //if the userIndex is equal to -1
        cout << username << " does not exist in the database" << endl; //output statement
        userBool = false; //return false
    }
    for (int k =0; k < 200 ; k++){ //iteration
        if (toUpperCase(book[k].getTitle()) == toUpperCase(title)){ //if the booktitle is equal to the title
            bookIndex = k; // k is the bookIndex
        }
    }
    if (bookIndex == -1){ //if bookIndex euqals -1 
            cout << title << " does not exist in the database" << endl; //putput statement
            titleBool = false; //return false
    }
    if (newRating == 0 || newRating > 5){ //of the new rating is equal to 0 or is greater than 5
        cout << newRating << " is not valid" << endl; //output statement
        ratingBool = false; //return false
    }
    
    if(userBool && ratingBool && titleBool){
        user[userIndex].setRatingAt(bookIndex, newRating); //set the new rating for that user for the book
        return true; //return true
    }else{
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

// Member Function: Problem 8 - viewRatings

/** viewRatings Function:
 * Check to make sure books and ratings files have been read.
 * Check to make sure the user exists in the database.
 * Check if it is a user that has not read any books in the database.
 * Print out the books and the ratings a user has rated.
 **/

void Library :: viewRatings(string username){
    int userIndex = -1; //sets userIndex equal to -1 
    if (numBooks == 0 || numUsers ==0){ //makes sure the database is fully initialized and files have been read
        cout << "Database has not been fully initialized" << endl; //output statement
        return;
    } 
    for (int i = 0; i < 200; i++){ //iteration
        string usernameAt = user[i].getUsername(); //usernameAt is equal to the username at the index
        if (toUpperCase (usernameAt) == toUpperCase (username)){ //if the username at the index is equal to the username 
            userIndex = i; //userIndex is the index where the user is found
        }
    }
    if (userIndex == -1){ //if the userIndex =-1
        cout << username << " does not exist in the database" << endl; //output statement
        return;
    }
    if (user[userIndex].getNumRatings() == 0) { //if the number of ratings for that usr is equal to zero
        cout << username << " has not rated any books yet" << endl; //output statement
        return;
    }
    cout << "Here are the books that " << username << " rated " << endl; //output statement
    for (int i = 0; i < 200; i++){ //iteration
        if (user[userIndex].getRatingAt (i) > 0 && user[userIndex].getRatingAt (i) <= 5){ //if the rating of the book is not zero
            cout << "Title : " << book[i].getTitle() << endl; //output statement
            cout << "Rating : " << user[userIndex].getRatingAt(i) << endl; //output statement
            cout << "-----" << endl; //outtput statement
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

// Member Function: Problem 9 - getRecommendation
void Library :: getRecommendations(string username){
    int userIndex = -1;
    
    if (numBooks == 0 || numUsers == 0){ //makes sure the database is fully initialized 
        cout << "Database has not been fully initialized" << endl; //output statement
        return;
    } 
    for (int i = 0; i < 200; i++){ //iteration
        string usernameAt = user[i].getUsername(); //usernameAt is equal to the username for the user at the index
        if (toUpperCase (usernameAt) == toUpperCase (username)){ //if the usernames are the same
            userIndex = i; //this is the index at which the user is found
        }
    }
    if (userIndex == -1){
        cout << username << " does not exist in the database" << endl;
        return;
    }
    
    User mostSimilar; //creates a user object called most similar 
    int lowestSsd = 6000; // declares a variable called lowestSSd and defines it equal to INT_MAX
    int userRatingAt; //creates a new variable called userRatingAt
    int paramRatingAt; //creates a new variable called paramRatingAt
    for (int i = 0; i < 200 ; i++){ //iteration
        if (user[userIndex].getUsername()!= user[i].getUsername()){ //if the user at the index is not the same as the user 
            int ssd=0; 
            bool isNewUser = true;
            for (int k = 0; k < 200 ; k++){ //iteration
                userRatingAt = user[i].getRatingAt(k); //userRatingAt is found by getting the raiting for that user at the index
                paramRatingAt = user[userIndex].getRatingAt(k);
                ssd += pow(paramRatingAt-userRatingAt, 2);
                if(userRatingAt != 0){
                    isNewUser = false;
                }
            }
            if(ssd == 0 && isNewUser){
                ssd = 6000;
            }
            if(ssd < lowestSsd){
                lowestSsd = ssd;
                mostSimilar = user[i];
            }
        }    
    }
      
    int counter = 0;
    for (int k = 0; k< 200 && counter < 5; k++){
        if ((mostSimilar.getRatingAt(k)==3 || mostSimilar.getRatingAt(k) == 4 || mostSimilar.getRatingAt(k) == 5) && (user[userIndex].getRatingAt(k) == 0 || user[userIndex].getRatingAt(k) == -1)){
            //cout << book[k].getTitle() << " by " << book[k].getAuthor() << endl;
            counter++;
        }
    }
    
    if(counter == 0){
        cout << "There are no recommendations for " << username << " at the present" << endl;
        return;
    }
    cout << "Here are the list of recommendations:" << endl;
    counter = 0;
    for (int k = 0; k< 200 && counter < 5; k++){
        if ((mostSimilar.getRatingAt(k)==3 || mostSimilar.getRatingAt(k) == 4 || mostSimilar.getRatingAt(k) == 5) && (user[userIndex].getRatingAt(k) == 0 || user[userIndex].getRatingAt(k) == -1)){
            cout << book[k].getTitle() << " by " << book[k].getAuthor() << endl;
            counter++;
        }
    }

}

string Library :: toUpperCase(string str){
    string ans = "";
    for(int i = 0; i < str.length(); i++){
        ans += toupper(str[i]);
    }
    return ans;
}
///////////////////////////////////////////////////////////////////////////////////////////////////