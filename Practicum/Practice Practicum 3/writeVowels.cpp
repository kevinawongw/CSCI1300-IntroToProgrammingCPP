#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;


int writeVowels(string fileName, string words[], int size){
    int count =0;
    int lines=0;
    string final="";
    for (int i=0;i<size;i++){
        string word = words[i];
        if (word!=""){
            lines++;
            for (int j=0;j<word.length();j++){
                if(word.at(j)=='a'||word.at(j)=='A'||word.at(j)=='e'||word.at(j)=='E'||word.at(j)=='i'||word.at(j)=='I'||word.at(j)=='o'||word.at(j)=='O'||word.at(j)=='u'||word.at(j)=='U'){
                    count++;
                }
            }
        final += word+","+to_string(count)+'\n';    
        count =0; 
        }
    }
    ofstream outFile (fileName);
    outFile <<final<<endl;
    return lines;
}


int main(){
    string lines[] = {"hello","","WORLD"};
    int writeCount = writeVowels("test1.txt", lines, 3);
    cout<<"Number of lines written: "<<writeCount<<endl;
}