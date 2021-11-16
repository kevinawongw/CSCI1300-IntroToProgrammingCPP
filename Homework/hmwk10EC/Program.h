#include <string>
#include <vector>
#include "Words.h"
using namespace std;

#ifndef PROGRAM_H
#define PROGRAM_H

class Program{
    public:
    Program();
    
    void readVocabulary(string fileName);
    void readMisspelling(string fileName);
    void fixSpelling();
    string toLowerCase(string str);

    
    private:
    vector <string>wordVec;
    vector <string>incorrectSpelling;
    vector <string>correctSpelling;
};
#endif