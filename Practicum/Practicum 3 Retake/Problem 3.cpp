#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int writePositiveEven(string fileName, int numbers[], int length){
    string s = "";
    for (int i=0;i<length;i++){
        if (numbers[i]>=0 && numbers[i]%2==0){
            s+=to_string(numbers[i])+'\n';
        }
    }
    ofstream outFile (fileName);
    if (outFile.is_open()){
        outFile <<s<<endl;
        return 1;
    }
    else {
        return -1;
    }    
}
    
int main (){
    int numbers[3] = {4, -1, 6};
    writePositiveEven(numbers,3);
}