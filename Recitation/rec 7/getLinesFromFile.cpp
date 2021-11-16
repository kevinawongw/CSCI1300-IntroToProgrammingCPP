#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int getLinesFromFile (string filename, int intStore [], int length){
    string line;
    ifstream file (filename);
    if (file.is_open()){
        int i = 0;
        while (getline (file, line)){
            try{
                if( i < length ){
                    intStore[i] = stoi(line);
                }else{
                    break;
                }
                i++;
            }catch(...){
                continue;
            }
        }
        return i++;
    }else{
        return -1;
    }
}