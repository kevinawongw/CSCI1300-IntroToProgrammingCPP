#include <iostream>
#include <math.h>
using namespace std;

void MultiplicationTableFor(){
    for (int i =1;i<6;i++){
        for (int j=1;j<i+1;j++){
            cout << j*i <<" ";
        }
    cout<< endl;    
    }
}
int main (){
    MultiplicationTableFor();
}