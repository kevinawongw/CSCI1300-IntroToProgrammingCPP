#include <iostream>
#include <string>

using namespace std;

string ReplaceHashTag (string sent){
    for (int i=0;i<sent.length();i++){
        if (sent[i]=='#'){
            sent[i]='@';
        }
    }
    return sent;
}

int main (){
    cout << ReplaceHashTag("#Hello");
    cout << ReplaceHashTag("#Colorado #Rocks");
}