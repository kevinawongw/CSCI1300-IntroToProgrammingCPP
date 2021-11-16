
// CSCI1300 Fall 2018
// Author: <Kevina Wong>
// Recitation: <123> – <Richard Tillquist>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/kevinawongw/csci1300>
// hmwk7 - main

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

#include "Book.h"
#include "User.h"

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
/** readBooks function
 * the function reads a book file from the text into book and author arrays
 *
 * @param: string, the name of the file to be read
 * @param: string array, titles
 * @param: string array, authors
 * @param: int, the number of books currently stored in the arrays
 * @param: int, capacity of the authors/titles arrays [assume to be 50]
 * @return: the total number of books in total
 * Open the file
 * If the file is open, use getline (with parameters file and booksAndAuthors)
 * Put books and authors in separate strings
 * Create books and put tiles and arrays into the book at that iteration.
 * Use a loop to integrate through the file and count how many iterations are made.
 * return the number of iterations
 * If the file cannot be opened, break
 * Close the file
 */
int readBooks(string fileName, Book books [], int numbooKs, int capacity){
    string booksAndAuthors; //defines a new string called booksAndAuthors
    ifstream file (fileName.c_str()); //makes file in an ifstream 
    int i = numbooKs; //defines stored books as an interger.
    if (file.is_open()){ //if file is open
        while(getline(file, booksAndAuthors)){ //use getline function
            string BaA[2]; //creates a new array with the size of 2

            split(booksAndAuthors, ',', BaA,2); //splits the file 

            string book = BaA[1]; //sets the book string equal to the array
            string author = BaA[0]; //sets the author string equal to the array

            Book tempBook(book,author); //creates a book called tempbook 

            if (i < capacity ){ //if i is less than capacity
                books[i]=tempBook; //sets the book array equal to tempbook
            }
            else {
                break;
            }
            i++;
        }
        return i; // return i subtracted by stored books
    file.close(); //close the file 
    }
    else {
        return -1; //return -1
    }
}

/** readRatings function
 * Read the user ratings from the file and store them
 * into users array and ratings array
 *
 * @param: string, the name of the file to be read
 * @param: string array, usernames
 * @param: 2D int array, list of ratings for each user (first index specifies user)
 * @param: int, the number of users currently stored in the array
 * @param: int, row capacity of the 2D array (convention: array[row][column]) [assume to be 100]
 * @param: int, column capacity of the 2D array [assume to be 50]
 * @return: the number of users in total
 * Opens a file
 * If the file is open, use the getline function to read through each line of the file and put those into string rt.
 * Split the lines in file rt by the comma, and put those into two arrays.
 * Create a new array with length rowcap
 * Split the strings in R by the space and put the two new strings into the linerating array.
 * Create a new array of integers
 * iterate through linerating. Convert the string to an integer at that index.
 * iterate through usernames. output the username at the index and followed by ...
 * Assign those to the temp User.
 * Return i 
 * close the file
 */

int readRatings (string fileNamer, User user [] , int users, int capacity){
    string rt; //creates a string called rt
    ifstream file (fileNamer.c_str()); //classifies file as an ifstream
    if (file.is_open()){ //if file is open
        int i = users; //defines an int i. make that equal to users
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

/**printAllBooks function
  * Print the books and their authors
  * 
  * @param: string array of titles
  * @param: string array of authors
  * @param: the number of books as an interger
  * Write edge case: if the number of books is equal to zero
  * Write a cout statement saying here us a list of books.
  * Iterate through the title and author array.
  * get the book at that array and get the title and the author from the book.
  * Output statement example: The Da Vinci Code by Dan Brown
  **/
  
 void printAllBooks(Book books [], int numberBooks){
    if (numberBooks ==0){ //if the number of books is equal to zero
        cout << "No books are stored" << endl << endl; //Output statement
    }else{
        cout << "Here is a list of books" << endl; //Output statement
        for(int i = 0; i < numberBooks; i++){ //for loop (iteration)
            cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl; //Output statement
        }
        cout << endl; // endline
    }
}

void displayMenu(){
  cout << "Select a numerical option:" << endl;
  cout << "======Main Menu=====" << endl;
  cout << "1. Read book file" << endl;
  cout << "2. Read user file" << endl;
  cout << "3. Print book list" << endl;
  cout << "4. Find number of books user rated" << endl;
  cout << "5. Get average rating" << endl;
  cout << "6. Quit" << endl;
}


int main(){ 
    Book collection[200];
    User users[200];
    int numUsers = 0;
    int numBooks = 0;
    string choice;
    
    while (choice != "6") {
        displayMenu();
        cin >> choice;
        cin.ignore();
        string fileName;
        string tempUsername;
        string bookName;
        int choiceNum = stoi(choice);
        switch (choiceNum) {
            case 1:
                // read book file
                cout << "Enter a book file name:" << endl;
                // string fileName;
                fileName.clear();
                cin >> fileName;
                cin.ignore();
                //////////////////////////////////////////////////////////////////////////
                numBooks = readBooks(fileName, collection, numBooks, 200);
                //////////////////////////////////////////////////////////////////////////
                
                if(numBooks > 0){
                    cout << "Total books in the database: " << numBooks << endl;
                }
                else{
                    cout << "No books saved to the database"<<endl;
                    if(numBooks == -1)
                        numBooks++;
                }
                cout << endl;
                break;
                
            case 2:
                // read user file
                cout << "Enter a rating file name:" << endl;
                // string fileName;
                fileName.clear();
                cin >> fileName;
                cin.ignore();
                //////////////////////////////////////////////////////////////////////////
                numUsers = readRatings(fileName, users, numUsers, 200);
                //////////////////////////////////////////////////////////////////////////
                if(numUsers != -1){
                    cout << "Total users in the database: " << numUsers << endl;
                }
                else{
                    cout << "No users saved to database"<<endl;
                    if(numUsers == -1)
                        numUsers++;
                }
                cout << endl;
                break;
            case 3:
                // print the list of the books
                
                //////////////////////////////////////////////////////////////////////////
                if(numBooks > 0)
                    printAllBooks(collection, numBooks);
                else
                    cout << "No books are stored" << endl << endl;
                //////////////////////////////////////////////////////////////////////////
                
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                // quit
                cout << "good bye!" << endl;
                break;

            default:
                cout << "invalid input" << endl << endl;
        }
    }
    // */
    return 0;
    
}