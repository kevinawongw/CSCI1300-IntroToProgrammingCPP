#include <iostream>
#include <string>
using namespace std; 

int getMatchCount (string s, string sub)
{
    int times =0;
    if (s.length()==0)
    {
        return -1;
    }
    else if (sub.length()==0)
    {
    return-1;
    }
    else if (sub.length()<s.length())
    {
        return -2;
    }
    for (int i=0;i<=sub.length();i++)
    {
        if (sub.substr(i,s.length())==s)
        {
            times++;
        }
    }
    return times;
}

int main (){
    cout << "Enter a sentence: "<< endl;
    string s;
    cin >> s;
    cout << "Enter a sub: "<< endl;
    string sub;
    cin >> sub;
    getMatchCount(s,sub);
}