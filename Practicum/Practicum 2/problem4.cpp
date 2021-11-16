#include <iostream>
#include <string> 
using namespace std;

string removeStars(string a){
    for ( int i = 0; i < a.length(); i++){
        if (a.at(i) != '*'){
            return a;
        }
    }
}
int main (){
    cout << removeStars("He*llo");
    cout << removeStars("**You* h");
    // cout << removeStars("");
}