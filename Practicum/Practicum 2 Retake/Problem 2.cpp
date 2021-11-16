#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void rightHalfPyramid(int num) {
  int counter = 0;
  for (int i=0; i <= num; i++) { 
    for (int j=0; j < i; j++){ 
        cout << counter % 10<< " ";;
        counter += 1; 
        }
    if (i!=0){    
        cout << endl;
        }
    }
} 


int main(){
    rightHalfPyramid(4);
}