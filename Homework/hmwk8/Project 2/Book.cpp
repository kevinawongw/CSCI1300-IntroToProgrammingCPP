
// CSCI1300 Fall 2018
// Author: <Kevina Wong>
// Recitation: <123> – <Richard Tillquist>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/kevinawongw/csci1300>
// hmwk7 - book.cpp file

//FunctionDefinitions
#include "Book.h"

Book::Book (){ //default constructor
    author = ""; //sets author to an empty string
    title = ""; // sets title to an empty string
}
Book::Book(string Mytitle, string Myauthor){ //Parameterized constructor
    title = Mytitle; //sets title to title
    author = Myauthor; //sets author to author
    
}

string Book::getTitle(){ //gets the title
    return title; //return
}
void Book::setTitle (string Mytitle){ //sets the title
    title = Mytitle; //sets title to title
}
string Book::getAuthor(){ //gets the author
    return author; //return
}
void Book::setAuthor (string Myauthor){ //gets authorvbhj 
    author = Myauthor; // sets author to author
}
