#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;


bool similarity(int a[][3], int aRow, int b[][3], int bRow){
    bool ans;
    if (aRow==0 && bRow==0){
        return true;
    }
    else if (aRow != bRow){
        return false;
    }
    else{
        for (int x=0;x<aRow;x++){
            for (int y=0;y<3;y++){
                if (a[x][y] == b[x][y]){
                    ans=true;
                }
                else{
                    ans=false;
                    goto lable;
                }
            }
        }
        lable:
    return ans;    
    }
}


int main(){
    int arrA[3][3]= {{1, 4, 6}, {17, 23, 3}, {5, 15, 25}};
    int arrB[3][3]= {{1, 4, 6}, {17, 23, 3}, {5, 15, 25}};
    cout << similarity(arrA, 3, arrB, 3) << endl;

    int arr1[3][3]= {{1, 4, 6}, {7, 23, 3}, {5, 15, 25}};
    int arr2[2][3]= {{1, 4, 6}, {7, 23, 3}};
    cout << similarity(arr1, 3, arr2, 2) << endl;
}