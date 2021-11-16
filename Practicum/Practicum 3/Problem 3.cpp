#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int writePositiveOdd(string fileName, int array[], int length){
string numbers;   
    ifstream file (fileName);
    if (file.is_open()){
        while (getline (file, numbers)){
            for (int i=0; i<length; i++){
            numbers [i];
            cout << numbers[0];
            }    
        }    
    }
    else{
        return -1;
    }
}
 
int main (){
    int array [5];
    writePositiveOdd("numbers.txt", array, 5);
}