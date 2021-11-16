#include <iostream>
#include <string> 
using namespace std;

// void PrintNonLetters(string a ){
//     if (a.length() == 0){
//         cout << "NULL" << endl;
//     }
//     for (int i = 0 ; i < a.length(); i++ ){
//         if (isalpha(a.at(i))==0){
//             cout << a.at(i);
//         }
//     }
// }

void PrintNonLetters(string sentence){
    int k=0;
    if (sentence.length()==0){
        cout << "NULL";
    }
    for (int i=0;i<sentence.length();i++){
        if (isalpha(sentence.at(i)) || islower(sentence.at(i))){
            cout << "";
            k++;
        }   
        else{
            cout << sentence.at(i);
        }
        if (k==sentence.length()){
            cout<< "-2";
        }
    }
    cout << endl;
}

int main(){
    PrintNonLetters("HELLO");
    PrintNonLetters("buH77jbK");
}
