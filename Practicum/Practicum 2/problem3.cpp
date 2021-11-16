#include <iostream>
#include <string>
using namespace std;


void dotsAndDashes(int n)
{
  for (int i =1 ; i <=n; i++)
  {
    for(int j=0; j<i; j++)
    {
      if(i%2==0)
      {
        cout<<"-";
      }
      else
      {
        cout<<".";
      }
    }
    cout <<endl;
  }
}


int main(){
    dotsAndDashes(4);
}

