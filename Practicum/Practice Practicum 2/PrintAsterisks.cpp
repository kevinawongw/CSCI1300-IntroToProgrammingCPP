#include <iostream>
using namespace std;

void PrintAsterisks (){
    for (int i=0;i<3;i++){
        for (int j=0;j<4;j++){
            cout << "*";
        }
    cout << endl;    
    }
}

int main (){
    PrintAsterisks();
}