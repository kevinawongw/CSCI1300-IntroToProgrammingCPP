#include <iostream>
#include <string>
using namespace std;

string RemoveHashTag (string sent){
    string a = "##";
    string b = "###";
    for (int i=0;i<sent.length();i++){
        if (sent.substr(i,3)==b){
            sent.erase(sent.begin()+i,sent.begin()+i+3);
        }
        else if (sent.substr(i,2)==a){
            sent.erase(sent.begin()+i,sent.begin()+i+2);
        }
        else if (sent[i]!='#'){
            sent[i]=sent[i];
        }
        else{
            sent.erase(sent.begin()+i);
        }
    }
    return sent;
}

int main (){
    cout << RemoveHashTag("#Hello #There") << endl;
}