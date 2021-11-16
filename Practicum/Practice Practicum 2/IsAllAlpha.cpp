#include <iostream>
#include <string>
using namespace std;


bool IsAllAlpha (string a){
    bool ans = true;
    if (a.length() == 0){
        return true;
    }
    else {
        for (int i = 0; i<a.length(); i++)
        {
            if(isalpha(a.at(i))==0){
                ans = false;
            }
        }
    }
    return ans;
}

int main(){
    cout << IsAllAlpha("HELLO");
    cout << IsAllAlpha("buHjbK22");
}

