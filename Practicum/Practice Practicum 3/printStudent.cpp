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



int PrintStudents (string fileName,int minScore, string outputFile){
    string line; 
    string a;
    int count =0;
    ifstream file (fileName.c_str());
    if (file.is_open()){
        while (getline(file, line)){
            string profile[3];
            split (line, ',', profile, 3);
            string name = profile[0];
            int score = stof(profile[1]);
            string classes = profile[2];
            count++;
            if (score >= minScore){
                a+= name+", "+classes+"\n";
            }
        }
    }
    else {
        return -1;
    }
    ofstream outFile (outputFile);
    outFile <<a;
    file.close();
    outFile.close();
    return count;
}



int main(){
    PrintStudents("students.txt",80,"goodStudents.txt");
}