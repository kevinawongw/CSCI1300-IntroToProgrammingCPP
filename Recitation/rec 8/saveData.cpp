#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

void saveData(string fileName, string data[], int n, int size) {
    ofstream file;
    file.open(fileName); 
    if (file.is_open()){ 
        if (n>0){ 
        double avg=0; 
        for (int i=0;i<n;i++){ 
            if (data[i]!=""){ 
                avg=avg+stof(data[i]); 
            }
        }
        avg=avg/n;
        string name = data[n];
        file << "Name: " << name<<endl; 
        if (n != 0){
           file << "Avg: " << avg<< endl;
        }
        file.close(); 
        }
    }
}
