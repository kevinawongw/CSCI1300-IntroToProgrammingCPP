#include <string>
#include <vector>
// #include "Words.h"
using namespace std;

#ifndef PROGRAM_H
#define PROGRAM_H

class Program{
    public:
    Program();
    void readVocabulary(string fileName);
    void readMisspelling(string fileName);
    void fixSpelling();
    string toLowerCase(string str);
    string normalizeString(string str);
    
    private:
    vector <string>wordVec;
    vector <string>incorrectSpelling;
    vector <string>correctSpelling;

};
#endif

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <algorithm>
// #include "Program.h"
// #include "Words.h"

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

string Program :: normalizeString(string str){
    stringstream ss(str);
    string temp;
    string normalizedStr = "";
    int count = 0;
    while(ss >> temp){
        bool hasSymbol = false;
        bool hasChar = false;
        
        for(char c: temp){
            if (!(c >= 65 && c <= 90) && !(c >= 97 && c <= 122)){
                hasSymbol = true;
            }
            if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
                hasChar = true;
            }
        }
        
        if(!hasSymbol){
            normalizedStr = normalizedStr + " " + temp;
        }else if(hasSymbol && hasChar){
            int i = 0;
            while(!(temp[i] >= 65 && temp[i] <= 90) && !(temp[i] >= 97 && temp[i] <= 122)){
                i++;
            }
            normalizedStr = normalizedStr + " " + temp.substr(i, temp.length()-i);
        }else if(hasSymbol && count != 0){
            normalizedStr = normalizedStr + " " + temp;
        }else if(hasSymbol){
            bool isNumber = true;
            for(char c:temp){
                if(!(c >= 48 && c <= 57)){
                    isNumber = false;
                }
            }
            if(isNumber)
                normalizedStr = normalizedStr + " " + temp;
        }
        count ++;
    }
    
    return normalizedStr.substr(1, normalizedStr.length()-1);
}

void Program :: readMisspelling(string fileName){
    string line;
    int i=0;
    ifstream file (fileName.c_str());
    if (file.is_open()){
        while (getline(file, line)){
            stringstream wordList(line);
            string right;
            getline(wordList, right, ',');
            correctSpelling.push_back(right);
            string wrong;
            getline(wordList, wrong, ',');
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
    bool aa = false;
    int k=0;
    cout << "Enter the phrase you would like to correct:" << endl;
    string sentence;
    getline (cin,sentence);
    if (sentence.length()==0){
        cout <<"";
    }
    string normalizedSentence = normalizeString(sentence);
    stringstream sent(normalizedSentence);
    string wordss;
    while (getline (sent,wordss,' ')){
        aa = false;
        int j = 0;
        while((wordss[j] >= 65 && wordss[j] <= 90) || (wordss[j] >= 97 && wordss[j] <= 122)){
            j++;
        }
        
        string punct;
        bool hasPunct = false;
        if(j != wordss.length()){
            punct = wordss.substr(j, wordss.length()-j);
            wordss = wordss.substr(0, j);
            hasPunct = true;
        }

        
        
        if (wordss=="c++"|| wordss=="C++"){
            cout << "c++";
            goto START;
        }
        for (int i =0; i < wordVec.size();i++){
            if (toLowerCase(wordss)==toLowerCase(wordVec[i])){
                cout << toLowerCase(wordVec[i]);
                goto START;
            }
        }
        for (int i=0;i<incorrectSpelling.size();i++){
            if (regex_match(toLowerCase(wordss),regex(incorrectSpelling[i]))){
                cout << correctSpelling[i];
                goto START;
            }
        }
        

        for (char c: wordss){
            if (isdigit(c)){
                cout << c;
                aa = true;
            }    
        }
        
        if(aa)
            goto START;
        
        if (wordss != ""){
            cout << "unknown";
        }
        
        START:
        if(hasPunct){
            cout << punct;
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

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <regex>
#include <algorithm>
// #include "Program.h"
// #include "Words.h"

using namespace std;

int main(){
    Program pro;
    pro.readVocabulary("vocabulary.txt");
    pro.readMisspelling("misspelling.csv");
    pro.fixSpelling();
    // for(string s: pro.correctSpelling){
    //     cout << s << endl;
    // }
}