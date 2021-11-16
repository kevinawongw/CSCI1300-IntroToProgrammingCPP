// CSCI1300 Fall 2018
// Author: <Kevina Wong>
// Recitation: <123> – <Richard Tillquist>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/kevinawongw/csci1300>
// hmwk8 / Project2


#include <iostream>
#include <iomanip>
#include "Book.h"
#include "User.h"
#include "Library.h"
using namespace std;

/* displayMenu:
 * displays a menu with options
 * DO NOT MODIFY THIS FUNCTION
 */
 
 void displayMenu(){
     cout << "Select a numerical option:" << endl;
     cout << "======Main Menu=====" << endl;
     cout << "1. Read book file" << endl;
     cout << "2. Read user file" << endl;
     cout << "3. Print book list" << endl;
     cout << "4. Find number of books user rated" << endl;
     cout << "5. Get average rating" << endl;
     cout << "6. Add a User" << endl;
     cout << "7. Checkout a book" << endl;
     cout << "8. View Ratings" << endl;
     cout << "9. Get Recommendations" << endl;
     cout << "10. Quit" << endl;
 }



int main(int argc, char const *argv[])
{
    string choice;
    Library lib;
    int numBooks;
    int numUsers;
    
    while (choice != "10") {
        int count, newRating;
        string username, title;
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
                fileName.clear();
                cin >> fileName;
                cin.ignore();
                //////////////////////////////////////////////////////////////////////////
                numBooks = lib.readBooks(fileName);
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
                numUsers = lib.readRatings(fileName);
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
                lib.printAllBooks();
                //////////////////////////////////////////////////////////////////////////
                
                break;
            case 4:
                cout << "Enter username:" << endl;
                // string fileName;
                cin >> username;
                cin.ignore();
                count = lib.getCountReadBooks(username);
                if(count < 0){
                    cout << endl;
                }else{
                    cout << username << " rated " << count << " books " << endl << endl;
                }
                
                
                break;
            case 5:
                cout << "Enter book title:" << endl;
                getline(cin,title);
                //cin.ignore();
                if(lib.calcAvgRating(title) < 0){
                    cout<< endl;
                }else{
                    cout << "The average rating for " << title << " is " << setprecision (2) << fixed << lib.calcAvgRating(title) << endl << endl;
                }
                break;
            case 6:
                cout << "Enter username:" << endl;
                // string fileName;
                cin >> username;
               cin.ignore();
                if (lib.addUser(username)){
                    cout << "Welcome to the library " << username << endl << endl;
                }
                else{
                    cout << username << " could not be added in the database" << endl << endl;
                }
                
                break;
                
            case 7:
                cout << "Enter username:" << endl;
                cin >> username;
                cin.ignore();
                
                cout << "Enter book title:" << endl;
                getline(cin,title);
                //cin.ignore();
                
                cout << "Enter rating for the book:" << endl;
                cin >> newRating;
                cin.ignore();
                
                if (lib.checkOutBook(username, title, newRating)){
                    cout << "We hope you enjoyed your book. The rating has been updated" << endl << endl;
                }
                else {
                    cout << username << " could not check out " << title << endl << endl;
                }

                break;
                
            case 8:
                cout << "Enter username:" << endl;
                cin >> username;
                cin.ignore();
                game.meetCustomers(username);
                cout << endl;
                break;
                
            case 9: 
                cout << "Enter username:" << endl;
                getline(cin, username);
                lib.getRecommendations (username);
                cout << endl;
                break;
                
            case 10:
                // quit
                cout << "good bye!" << endl;
                break;
            default:
                cout << "invalid input" << endl << endl;
        }
    }
    return 0;
}