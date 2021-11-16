#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Program.h"
#include "Words.h"

using namespace std;

int main(){
    Program pro;
    pro.readVocabulary("vocabulary.txt");
    pro.readMisspelling("misspell.csv");
    pro.fixSpelling();
}