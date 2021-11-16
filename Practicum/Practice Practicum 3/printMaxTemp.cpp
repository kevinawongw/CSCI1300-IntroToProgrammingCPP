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


float maxTemp (string fileName){
    string line;
    int i=0;
    float max=0;
    ifstream file (fileName.c_str());
    if (file.is_open()){
        while (getline(file, line)){
            string dayAndTemp[2];
            if (line.length()==0){
                continue;
            }
            Split (line, ',', dayAndTemp, 2);
            string day = dayAndTemp[0];
            float temp = stof(dayAndTemp[1]);
            if (temp>=max){
                max=temp;
            }
        }
    }
    else {
        return -1;
    }
    return max;
}

int main (){
    cout << maxTemp("temp.txt");
}