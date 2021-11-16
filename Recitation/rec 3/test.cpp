#include <iostream>
using namespace std;

int test(){
   string s = "1234";
for (int i = 0; i <= 4; i++)
{
   cout << s.substr (i, 1);
}
}

int main(){
    test();
}