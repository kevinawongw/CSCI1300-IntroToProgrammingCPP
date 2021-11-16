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


int calcPay(string fileName){
    string line;
    int i=0;
    float total=0;
    ifstream file (fileName.c_str());
    if (file.is_open()){
        while (getline(file, line)){
            string info[3];
            if (line.length()==0){
                continue;
            }
            Split (line, ',', info, 3);
            string name = info[0];
            int hours = stoi(info[1]);
            float pay = stof(info[2]);
            float t=hours*pay;
            total+=t;
            cout << name << ": " << hours*pay << endl;
            i++;
        }
        cout << "Total: " << total << endl;
        return i;    
    }
    else{
        return -1;
    }
}

int main(){
    calcPay("calcPay.txt");
}