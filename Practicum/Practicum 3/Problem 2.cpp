#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;
 int Split (string str, char c, string array[], int size)
 {
    if (str.length() == 0) {
         return 0;
     }
    string word = "";
    int count = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return count ;
 }
 


int parseScores(string fileName){
string line;
int total= 0;
float avg = 0;
int a=0;
    ifstream file (fileName);
    if (file.is_open()){
        while (getline (file, line)){
            for (int i = 0; i<1; i++){
                string info [4];
                Split (line, ',', info, 4);
                int Sa = stoi(info [0]);
                int Sb = stoi(info [1]);
                int Sc = stoi(info [2]);
                string d = info [3];
                float total = Sa + Sb + Sc;
                avg = total/3;
                cout << d << ": " << avg << endl;
                a++;
                return a;
            }
        }
    }
    else{
        return -1;
    }
}


int main (){
    parseScores("Problem2.txt");
}