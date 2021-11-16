#include <iostream>
using namespace std;

int classGreeting (int number){ //function classGreeting
    cout <<"Hello, CS "<< number << " World!"<< endl; //output statement
    return 0;
}

int main(){
    int number; //defines number as an interger
    cout << "Enter a number:" << endl; //statement tells the user to inout a statement
    cin >> number; //makes number an input
    classGreeting(number);
}