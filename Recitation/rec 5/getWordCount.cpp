// Author: Kevina Wong CS1300 Fall 2018
// Recitation: 104 – Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/kevinawongw/csci1300
// Recitation 5

#include <iostream>
#include <string>
using namespace std;
 /**
  * getWordCount
  * returns the number of words in a sentence.
  **/
int getWordCount (string s){
    int words= 0;
    for (int i = 0; i < s.length();i++){
        if (s[i] == ' '){
        words++;
        }
    }
    if (s.length() == 0){
        return 0;
    }
    else {
    return words +1;
    }
}
/**
 * main
 * allows test cases
 **/
int main (){
    cout << "Enter a sentence: "<< endl;
    string s;
    cin >> s;
    getWordCount(s);
}