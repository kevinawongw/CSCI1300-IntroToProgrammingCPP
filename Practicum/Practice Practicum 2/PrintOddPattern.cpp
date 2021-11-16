#include <iostream>

using namespace std;

void PrintOddPattern(){
    for (int i=0;i<3;i++){
        for (int j=0;j<5;j++){
            if (j%2!=0){
                cout << "*";
            }
            else{
                cout << "$";
            }
        }
    cout << endl;    
    }
}

int main (){
    PrintOddPattern();
}