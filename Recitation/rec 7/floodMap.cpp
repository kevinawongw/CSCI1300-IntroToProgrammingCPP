#include <iostream>
#include <string>
#include <fstream>
using namespace std; 

int floodMap (double map [][4], int rows, double waterLevel){
    for (int = 0; i < rows; i++){
        for (int j = 0; j < 4; j++){
            if ( map [i][j] >= waterLevel){
                cout << "*";
            }
            else if (map [i][j] <= waterLevel){
                cout << "_";
            }
            if (i==3){
            cout << endl;
        }
    }
}