#include <iostream>
#include <string>
using namespace std;

int getLastIndex(char a, string b){
    if (b.length() ==0)
    { 
        return -1;
    }
    else
    {
        int last=0;
            for (int i=0; i<=b.length(); i++)
            { 
                if (b[i]==a)
                { 
                    last = i;
                }
            }
        if (last ==0)
        { 
            return -2;
        }
        else
        { 
            return (last);
        }
    }    
}

int main(){
    int last1 = getLastIndex('r',"tomorrow");
    cout << "last1= " << last1 << endl; 
    int last2 = getLastIndex('g',"penguin"); 
    cout << "last2= " << last2 << endl; 
 
}