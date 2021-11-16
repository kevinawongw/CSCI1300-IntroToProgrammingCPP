#include <iostream>
#include <string>
#include "Book.h"
#include "User.h"
#include "Library.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

// Takes a string (the name of the file to be read) and
// populates the books array. Returns the total
// number of books in books array as an integer

// Member Function: Problem 1 - readBooks
int Library :: readRatings(string fileName){
    const int numberBooks = 200;
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
            if (i < numberBooks ){ //if i is less than capacity
                book[i]=tempBook; //sets the book array equal to tempbook
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
