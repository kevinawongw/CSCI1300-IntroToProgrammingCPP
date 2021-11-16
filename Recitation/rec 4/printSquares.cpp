#include <iostream>
#include <math.h>
using namespace std; 

void printSquares(int width){
    int x= 1;
    int y= 1;
    for (x=1; x <= width; x++){
        for (y = 1; y <= width; y++){
            cout<<"*";
        }
        cout <<" ";
        for (y = 1; y<= width; y++){
            if (x>1 && x<width && y>1 && y<width){
            cout<<" ";
        }
            else {
                cout << "*";
            }
        }
        cout << endl;
}
}
 int main(){
     printSquares(5);
 }