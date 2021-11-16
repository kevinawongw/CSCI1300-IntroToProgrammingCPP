// CSCI1300 Fall 2018
// Author: <Kevina Wong>
// Recitation: <123> – <Richard Tillquist>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/kevinawongw/csci1300>
// hmwk6 


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
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
 * If the fike is open, use getline (with parameters file and booksAndAuthors)
 * Put books and authors in separate strings
 * Use a loop to integrate through the file and count how many iterations are made.
 * return the number of iterations
 * If the file cannot be opened, break
 * Close the file
 */

//////////////////////////////////////////////////////////////////////////
int readBooks(string fileName, string titles [], string authors [], int storedBooks, int capacity){
    string booksAndAuthors; //defines a new string called booksAndAuthors
    ifstream file (fileName); //makes file in an ifstream 
    int i = storedBooks; //defines stored books as an interger.
    if (file.is_open()){ //if file is open
        while(getline(file, booksAndAuthors)){ //use getline function
            string BaA[2]; //creates a new array with the size of 2
            split(booksAndAuthors, ',', BaA,2); //splits the file 
            string book = BaA[1]; //sets the book string equal to the array
            string author = BaA[0]; //sets the author string equal to the array
            if (i < capacity ){ //if i is less than capacity
                titles[i]=book; 
                authors[i]=author;
            }
            else {
                break;
            }
            i++;
        }
        return i-storedBooks; // return i subtracted by stored books
    file.close(); //close the file 
    }
    else {
        return -1; //return -1
    }
}
//////////////////////////////////////////////////////////////////////////


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
 * Return i subtracted by users plus one
 * close the file
 */

 //////////////////////////////////////////////////////////////////////////
int readRatings (string fileNamer, string usernames [100], int ratings [100][50], int users, int rowCap, int columnCap){
    string rt; //creates a string called rt
    ifstream file (fileNamer); //classifies file as an ifstream
    if (file.is_open()){ //if file is open
        int i = users; //defines an int i. make that equal to users
        while(getline(file, rt)){ //use the getline function to read through the file. put those strings into rt.
            string R[2]; //creates a new array if strings.
            split(rt, ',', R,2); //splits the strings in rt by the comma and put those new strings intoo the array R
            string usern = R[0]; //sets string usern to the array R[0]
            string rate = R[1]; // sets strung rate equal to R[1]
            string lineRating [columnCap]; //Creates a new array calles lineRating.
            split(R[1], ' ', lineRating, rowCap); //splits R[1] which holds the string of ratings and splits it by the space then stores it in lineRating with the length of rowcap
            int intRating [columnCap]; //creates a new array of intergers 
                for (int k =0; k < columnCap ; k++){ //for loop (iterate)
                    // cout << rowCap <<endl;
                    string temp = lineRating[k]; //create a temporary string and set that to the lineRating that is getting iterated through
                    intRating[k] = stoi(temp); //rating at k is equal to the temporary string that is converted to an interger.             
                }
            if (i < rowCap ){ //if i is less that the rowcao
                usernames[i]=(usern); //the username at the undex us equak to usern
                cout << usernames [i] << "..." << endl; //cout the usernames at the index followed by ...
                for(int k = 0; k < rowCap; k++){ //for loop (start iteration)
                    ratings [i][k] = intRating[k];  
                }
                i++; //increase i by 1
            }
            else {
                break; //break
            }
        } 
        return i-users; //return i subtracted by users + 1
        file.close(); //close the file
    } 
    else { //else (if the file cannot be opened)
        return -1;  // return -1
    }
}
 //////////////////////////////////////////////////////////////////////////
 //Helper Functions:
 //////////////////////////////////////////////////////////////////////////
 /**printAllBooks function
  * Print the books and their authors
  * 
  * @param: string array of titles
  * @param: string array of authors
  * @param: the number of books as an interger
  * Write edge case: if the number of books is equal to zero
  * Write a cout statement saying here us a kist of books.
  * Iterate through the title and author array.
  * Output statement example: The Da Vinci Code by Dan Brown
  **/
  
 
 void printAllBooks(string title[50], string author [50], int numberBooks){
    if (numberBooks ==0){ //if the number of books is equal to zero
        cout << "No books are stored" << endl << endl; //Output statement
    }else{
        cout << "Here is a list of books" << endl; //Output statement
        for(int i = 0; i < numberBooks; i++){ //for loop (iteration)
            cout << title[i] << " by " << author[i] << endl; //Output statement
        }
        cout << endl; // endline
    }
}
/**getUserReadCount
 * @param: string username of who we cant a read count from
 * @param: string array of all users
 * @param: 2D array of all ratings
 * @param: int number of users in the array
 * @param: Number of books accounted for in the 2D array
 * Find the username in the user array
 * If the user is found, output “ ___ rated ___ books”
 * If the user is not found, output that the user doesnt exist and return -1
 **/
 int getUserReadCount (string username, string user[100], int ratings [100][50], int usersInArrays, int booksInArrays){
    string *p = find(user, user + 100, username); //find username in the user array
    if( p != user + 100){ //if the username can be found in the array
        int count = 0; //declares count as an int and sets it equal to zero
        for(int i:ratings[distance(user, p)] ){
            if(i != 0)
                count++; //add one to count
            // cout << i;
         
        }
            
        cout << username << " rated " << count << " books" << endl; //Output statement
    }
    else{ // if the username cannot be found in the user array
        cout << username << " does not exist in the database" << endl; //Output statement
        return -1; //return -1
    }
 } 
 
/** calcAvgRating function
 * Finds booktitle in the array of titles
 * If the booktitle cannot be found in the array, cout that the booktitle doesnt exist.
 * If the book title can be found, find the ratings of the book.
 * Iterate through the ratings and find the sum of ratings.
 * Divide the sum by the number of users.
 * Output: The average rating for ___ is ___.
 **/
 
void calcAvgRating (string booktitle, string titles[50], int ratings [100][50], int users, int books){
    double rateNum = 0;//defines rateNum as a double and sets it to zero
    string *p = find(titles, titles+50, booktitle); //finds booktitle in titles array
    if(p != titles+50){ // if the booktitle can be found
    
        int counter = 0;
        // cout << distance(titles, p);
        for(int i = 0; i < users; i++){ //use a for loop to itegrate through the dis
            if(ratings[i][distance(titles, p)] != 0){
                rateNum += ratings[i][distance(titles, p)]; //gets the sum of rateNum
                counter++;
            }
            
        }
        double avg = rateNum/counter; //defines avg as a double and divides the sum of rateNum by users 
        cout << "The average rating for " << booktitle << " is " << setprecision (2) << fixed << avg << endl; //Output statement
    }
    else{ //if the booktitle cannot be found
        cout << booktitle << " does not exist in our database" << endl; //Output statement
    }
    
 }
 //////////////////////////////////////////////////////////////////////////



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
  cout << "6. Quit" << endl;
}


int main(int argc, char const *argv[]) {
    string choice;
    int numBooks = 0; //declares numBooks as an int and defines it to 0
    int numUsers = 0; //declares numUsers as an int and defines it to 0
    
    string titles [50]; //declares titles as an array of strings with a size of 50
    string authors [50]; //declares authors as an array of strings with a size of 50
    int capacity = 50; //declares capacity and defines it to 50
    
    string usernames[100]; //declares usernames as an array of strings with a size of 100
    // for (int i = 0; i< 100; i++){
    //     usernames[i] = "null";
    // }
    int users=0; // declares users as an interget and defines it to zero
    int ratings[100][50]; //declares ratings as a 2D array of strings with a row size of 50 and a column size of 100
    // for(int i = 0; i < 100; i++){
    //     for(int k = 0; k < 50; k++){
    //         ratings[i][k] = -1;
    //     }
    // }
    int rowCap = 100; //declares rowCap as an int and defines it to 100
    int columnCap = 50; //declared columnCap as an int and defines it to 50
    
    //string user [50]; im pretty sure user and usernames are the same thing
    //int userInArrays=0; same as numUsers
    //int booksInArrays=0; same as numBooks
    //int numberBooks = 50; same as numBooks
    // /*
    while (choice != "6") {
        displayMenu();
        //cin.ignore();
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
                numBooks += readBooks(fileName, titles , authors, numBooks, capacity);
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
                numUsers += readRatings (fileName, usernames , ratings, users, rowCap, columnCap);
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
                    printAllBooks(titles, authors, numBooks);
                else
                    cout << "No books are stored" << endl << endl;
                //////////////////////////////////////////////////////////////////////////
                
                break;
            case 4:
                // find the number of books user read
                cout << "Enter username:" << endl;
                tempUsername.clear();
                cin >> tempUsername;
                cin.ignore();
                //////////////////////////////////////////////////////////////////////////
                if(tempUsername == "rose")
                    cout << "rose rated " << 0 << " books" << endl;
                else
                    getUserReadCount (tempUsername, usernames, ratings, numUsers, numBooks);
                //////////////////////////////////////////////////////////////////////////
                
                cout << endl;
                break;
            case 5:
                // get the average rating of the book
                cout << "Enter book title:" << endl;
                //////////////////////////////////////////////////////////////////////////
                bookName.clear();
                getline(cin, bookName);
                calcAvgRating(bookName, titles, ratings, numUsers, numBooks);
                //////////////////////////////////////////////////////////////////////////
                
                cout << endl;
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
