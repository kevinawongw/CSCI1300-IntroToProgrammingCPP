#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <algorithm>
#include "Program.h"
#include "Words.h"

using namespace std;

Program :: Program (){
    
}

void Program :: readVocabulary(string fileName){
    string line;
    int i=0;
    ifstream file (fileName.c_str());
    if (file.is_open()){
        while (getline(file, line)){
            wordVec.push_back(line);
            i++;
        }
        cout << "Read " << i << " words from " << fileName << endl;
    }
    else{
        cout << fileName << " does not exist" << endl;
    }
}

void Program :: readMisspelling(string fileName){
    string line;
    int i=0;
    ifstream file (fileName.c_str());
    if (file.is_open()){
        while (getline(file, line)){
            stringstream wordList(line);
            string right;
            wordList >> right;
            correctSpelling.push_back(right);
            string wrong;
            wordList >> wrong;
            incorrectSpelling.push_back(wrong);
            i++;
        }
        cout << "Read " << i << " words from " << fileName << endl;
    }
    else{
        cout << fileName << " does not exist" << endl;
    }
}

void Program :: fixSpelling(){
    cout << "Enter the phrase you would like to correct:" << endl;
    string sentence;
    getline (cin,sentence);
    stringstream sent(sentence);
    string wordss;
    int b =0;
    while (getline (sent,wordss,' ')){
        if (b ==0){
            for (int i =0;i<wordss.length();i++){
                char c = wordss [i];
                if (!(c >= 65 && c <= 90) && !(c >= 97 && c <= 122)){
                    wordss = "";
                    cout << "";
                    b++;
                }
            }
        }
        bool c = false;
        if (wordss=="I" || wordss == "i"){
                cout << wordss;
                c=true;
        }
        bool a = false;
        for (int i=0;i<incorrectSpelling.size();i++){
            if (regex_match(wordss,regex(incorrectSpelling[i]))){
                cout << correctSpelling[i];
                a = true;
                break;
            }
            else if (toLowerCase(wordss)==toLowerCase(correctSpelling[i])){
                cout << correctSpelling[i];
                a=true;
                break;
            }
            else if (toLowerCase(wordss)==toLowerCase(wordVec[i])){
                cout << wordVec[i];
                a=true;
                break;
            }
        }
        if (a==false){
            if (wordss != ""){
                cout << "unknown";
            }
        }
    cout << " ";    
    }
}

string Program :: toLowerCase(string str){
    string ans = "";
    for(int i = 0; i < str.length(); i++){
        ans += tolower(str[i]);
    }
    return ans;
}