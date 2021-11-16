#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <math.h>
using namespace std;

int fileLoadWrite (string fileName){
    ofstream outFile(fileName);
        outFile << "1" << endl;
        outFile << "4" << endl;
        outFile << "9" << endl;
        outFile << "16" << endl;
        outFile << "25" << endl;
        outFile << "36" << endl;
        outFile << "49" << endl;
        outFile << "64" << endl;
        outFile << "81" << endl;
        outFile << "100" << endl;
    return 0;
}

int main (){
    cout << fileLoadWrite("test.txt") << endl;
}