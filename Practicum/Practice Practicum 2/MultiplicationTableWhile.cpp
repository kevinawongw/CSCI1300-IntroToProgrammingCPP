#include <iostream>
#include <math.h>
using namespace std;

void MultiplicationTableWhile(){
    int i = 1;
    while (i < 6){
    int j=1;
        while (j<i+1){
            cout << j*i <<" ";
            j++;
        }
    cout << endl;
    i++; 
    }
}
    
int main (){
    MultiplicationTableWhile();
}