#include <iostream>
using namespace std;

int miain (){
    stack <int> s;
    s.push(1);
    s.push(5);
    s.push(6);
    s.pop();
    s.push(3);
    s.push(4);
    s.push(8);
    s.pop();
    s.pop();
    
    
    cout << s << endl;
}