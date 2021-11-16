
// CSCI1300 Fall 2018
// Author: <Kevina Wong>
// Recitation: <123> – <Richard Tillquist>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/kevinawongw/csci1300>
// hmwk7 - book.h file

//Function Declarations
#include <iostream>
#include <string>
using namespace std;

#ifndef BOOK_H
#define BOOK_H
class Book{ //creates a class called book
  public: //member functions
  Book(); //default constructor
  Book (string Mytitle, string Myauthor); //parameterized constructor
  
  string getTitle(); // get the title
  void setTitle (string Mytitle ); // set the title
  string getAuthor(); //get the author
  void setAuthor( string Myauthor); //set the author
  
  private: // data members 
  string title; //declare the title as a string
  string author; //declare the author as a string
  int TitleNum; //declare TitleNum as an int
  int AuthorNum; //declare authornum as an int
  
};
#endif