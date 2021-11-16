// CSCI1300 Fall 2018
// Author: <Kevina Wong>
// Recitation: <123> – <Richard Tillquist>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/kevinawongw/csci1300>
// hmwk7 - Library.h file

#ifndef LIBRARY_H
#define LIBRARY_H

class Library{
    private:
    Book book [200]; //an array of book objects
    User user [200]; //an array of user objects
    int numBooks; //number of books in the library
    int numUsers; //numbers of users in the library
    int sizeBook; //the capacity of books in the library (200 *constant)
    int sizeUser; //the capactity of users in the library (200 *constant)
    
///////////////////////////////////////////////////////////////////////////////////////////////////    
    
    public:
    //default constructors
    Library();
    int readBooks (string fileName);
    int readRatings (string fileName);
    void printAllBooks();
    int getCountReadBooks (string username);
    double calcAvgRating (string title);
    bool addUser(string username);
    bool checkOutBook (string username, string title, int newRating);
    void viewRatings (string username);
    void getRecommendations (string username);
    string toUpperCase(string str);
};

#endif