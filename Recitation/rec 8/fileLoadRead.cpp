#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

int fileLoadRead (string fileName){
    int a =0;
    string read;
    ifstream file (fileName);
    if (file.is_open()){
        while (getline (file, read)){
                a++;
            }
            return a;
        }
    else {
        return -1;
    }
}

int main (){
    cout << fileLoadRead("numbers.txt") << endl;
    cout << fileLoadRead("hello.txt") << endl;
}