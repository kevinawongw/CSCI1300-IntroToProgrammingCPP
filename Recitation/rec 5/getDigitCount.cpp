#include <iostream>
#include <string>
using namespace std;

int getDigitCount(string input){
    int digits = 0;
    for (
    {
        if (isdigit(input[i]))
        {
       digits++;
        }
    }
        return digits;
}

int main(){
    cout << "Enter a statement: " << endl;
    string input;
    cin >> input;
    getDigitCount(input);
    
}