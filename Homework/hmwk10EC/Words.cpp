#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "Words.h"

using namespace std;

Words :: Words(){
    string word="";
}

Words :: Words(string myWord){
    word=myWord;
}

string Words::getWord(){
    return word;
}

void Words::setWord(string myWord){
    word=myWord;
}