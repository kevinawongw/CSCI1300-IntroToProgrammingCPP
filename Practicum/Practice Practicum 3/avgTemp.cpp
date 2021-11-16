#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;


int split (string str, char c, string array[], int size)
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



int averageTemp (string fileName){
    string line;
    int i=0;
    float totalTemp=0;
    float avg=0;
    ifstream file (fileName.c_str());
    if (file.is_open()){
        while (getline(file, line)){
            string dayAndTemp[2];
            if (line.length()==0){
                continue;
            }
            split (line, ',', dayAndTemp, 2);
            string day = dayAndTemp[0];
            float temp = stof(dayAndTemp[1]);
            totalTemp+=temp;
        }
        float avg = totalTemp/7;
        return avg;
    }
    else{
        return -1;
    }
}

int main(){
    cout << averageTemp("temp.txt") << endl;
    cout << averageTemp("DNE.txt") << endl;
}