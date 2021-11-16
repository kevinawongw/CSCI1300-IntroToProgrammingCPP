#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

string checkFile (string fileName){
    ifstream file (fileName);
    if (file.is_open()){
        return "true";
    }
    else {
        return "false";
    }
    file.close();
}

int main (){
    
}