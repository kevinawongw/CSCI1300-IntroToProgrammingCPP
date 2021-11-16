#include <iostream>
#include <string>
using namespace std;

void PrintCommas(string str) {
    for (int i = 0; i <= str.length(); i++) {
        if (str[i] == ',') {
            cout << str[i];
            i++;
        }
    }
}

int main(){
    cout << PrintCommas(",,,") << endl; 
}