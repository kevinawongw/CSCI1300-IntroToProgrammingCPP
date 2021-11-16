#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;



int diagonalSum(int arr[][3], int row){
    int ans =0;
    for (int x=0;x<row;x++){
        for (int y=0;y<3;y++){
            if (x==y){
                ans+=arr[x][y];
            }
        }        
    }
    return ans;
}


int main(){
    int arr[3][3]= {{1, 4, 6}, {7, 23, 3}, {5, 15, 25}};
    cout << diagonalSum(arr, 3) << endl;
}