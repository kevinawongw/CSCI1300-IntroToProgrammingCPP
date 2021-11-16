#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;


void findDuplicate (int values[],int size){
    int k=0;
    for (int i =0; i < size; i++){
        int number = values[i];
        for (int j=i+1;j<size;j++){
            if (number == values[j]){
                cout << number;
                k++;
            }
        }
    }
    if (k<1){
        cout << "-1";
    }
}


int main(){
    int array[10] = {2,3,5,6,11,20,4,8,4,9};
    findDuplicate(array,10);
}