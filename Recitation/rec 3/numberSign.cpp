#include <iostream>
using namespace std;

void numberSign (int number){ //function numbersign
    if (number == 0) //conditional statement says if the number is equal to zero
        { 
        cout << "zero" << endl; //output statement tells it to print zero
        }
    else if (number > 0) //conditional statement says if the number is greater than zero
        {
        cout << "positive" << endl; //output statement tells it to print positive
        }
    else if(number < 0) //conditional statement says if the number is less than zero
        {
        cout << "negative" << endl; //output statement tells it to print negative
        }
}

int main(){ //main func
    int number; //defines the number as an interger
    cout << "enter a number value!" << endl; //statement asks the user to input a number
    cin >> number; //makes the numner an input
    numberSign(number);
}
    
    