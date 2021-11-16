#include <iostream>
#include <string>
using namespace std;


void replaceNums (int myArray [], int a){
    int temp[a];  
    for (int i=0; i<=a-1; i++){
        temp [i] = myArray[i];
    }
        for (int i=0; i<=a-1; i++){
            if (i == 0 || i == a-1 ){
                myArray[i] = {temp[i]};
            }
            else if (i!=a-1 && i!=0 ){
                if (temp[i-1] > temp[i+1]){
                    myArray[i] = {temp[i-1]};
                }
                else if (temp[i+1] > temp[i-1]){
                    myArray[i] = {temp[i+1]};
                }
                else if (temp[i+1] == temp[i-1]){
                    myArray [i] = {temp[i-1]};
                }
            }
        }
    }

