#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;


int countCharacter(string array[ ], int size, char ch){
int character;
   for (int i = 0; i < size; i++){
       string word = array [i];
       for (int k = 0; k < size; k++){
           if (word [k] == ch){
               character ++;
           }
       }
   }
   return character;
}


int main(){
   string array[6] = {"elephant", "english", "elegant", "america", "united", "apple"};
   char ch = 'e';
   cout << countCharacter(array, 6, ch) << endl;
}