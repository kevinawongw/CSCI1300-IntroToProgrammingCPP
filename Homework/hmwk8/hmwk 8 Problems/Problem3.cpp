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

// Prints all books stored in books array.

// Member Function: Problem 3 - printAllBooks
void Library :: printAllBooks(){
    if (numBooks() == 0){ //if the number of books is equal to zero
        cout << "No books are stored" << endl << endl; //Output statement
    }else{
        cout << "Here is a list of books" << endl; //Output statement
        for(int i = 0; i < numBooks(); i++){ //for loop (iteration)
            cout << book [i].getTitle() << " by " << book [i].getAuthor() << endl; //Output statement
        }
        cout << endl; // endline
    }
}

