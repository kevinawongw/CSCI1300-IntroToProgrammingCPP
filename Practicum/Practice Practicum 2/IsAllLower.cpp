
#include <iostream>
#include <string>
using namespace std;


int IsAllLower(string a){
    bool ans = true;
    if (a.length() == 0){
        return true;
    }
    else {
        for (int i = 0; i<a.length(); i++)
        {
            if(islower(a.at(i))==0){
                ans = false;
            }
        }
    }
    return ans;
}

int main(){
    cout << IsAllLower("HELLO");
    cout << IsAllLower("buHjbK22");
}