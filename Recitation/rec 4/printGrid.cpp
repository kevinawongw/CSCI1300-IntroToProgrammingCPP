#include<iostream>
using namespace std;

void printGrid(int side){
    string border="--+";
    string otherBorder="|";
    for (int i=1;i<side*2+2;i++){
        int count=1;
        if (i%2!=0){ //even
            cout << "+";
            for (int j=0;j<side;j++){
                cout << border;
            }
            cout << endl;
        }
        else if (i%2==0){ //odd
            for (int k=0;k<side+1;k++){
                cout << "|  ";
            }
        cout << endl;
        }
    }
}

int main(){
    printGrid(5);
    // printGrid(3);
}