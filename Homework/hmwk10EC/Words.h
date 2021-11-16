#include<string>
using namespace std;

#ifndef WORDS_H
#define WORDS_H

class Words{
    public:
    Words ();
    Words (std::string myWord);
    
    std::string getWord ();
    void setWord (std::string myWord);
  
    private:
    std::string word;
};

#endif 