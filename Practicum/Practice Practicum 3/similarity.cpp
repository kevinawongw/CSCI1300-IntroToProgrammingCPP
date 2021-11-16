#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;


bool similarity(int a[ ], int aSize, int b[], int bSize){
    bool ans;
    if (aSize ==0 && bSize==0){
        return true;
    }
    else if (aSize!=bSize){
        return false;
    }
    else {
        for (int i=0;i<aSize;i++){
            if (a[i]!=b[i]){
                ans = false;
                break;
            }
            else{
                ans = true;
            }
        }
    return ans;    
    }
}


int main(){
    int arrA[]= {1, 4, 16, 7, 23, 3};
    int arrB[]= {1, 4, 16, 7, 23, 3};
    cout << similarity(arrA, 6, arrB, 6) << endl;

    int arr1[]= {1, 7, 23, 3};
    int arr2[]= {1, 4, 6, 7, 23, 3};
    cout << similarity(arr1, 4, arr2, 6) << endl;   
}