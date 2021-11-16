#include <iostream>
#include <string>
using namespace std;

int CountVowels (string a){
    int vowels = 0;
    if (a.length() == 0)
    {
        return -1;
    }
    else 
    {
        for (int i =0; i< a.length(); i++){
            if (a[i] == 'a'|| a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' || a[i] == 'A'|| a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U')
            {
                vowels++;
            }
        }
    }
    return vowels;
}


int main(){
    cout << CountVowels("doggie") << endl;
    cout << CountVowels("ham") << endl;
    cout << CountVowels("") << endl;
    
}