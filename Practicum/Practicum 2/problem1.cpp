#include <iostream>
#include <string>
using namespace std;

int CountAtoJ (string a){
    if (a.length () == 0){
        return -1;
    }
    int letter =0;  
    for (int i =0; i<= a.length(); i++){
        if (a[i] == 'A'|| a[i] == 'B'||a[i] == 'C'||a[i] == 'D'|| a[i] == 'E'||  a[i] == 'F'|| a[i] == 'G'|| a[i] == 'H'||  a[i] == 'I'|| a[i] == 'J'){
            letter++;
        }
    }
            if (letter == 0){
                return -2;
            }
            else{
                return letter;
                }
        }    


int main(){
    cout << CountAtoJ("AzB") << endl;
    cout << CountAtoJ("zzz") << endl;
    cout << CountAtoJ("JABB") << endl;
    
}