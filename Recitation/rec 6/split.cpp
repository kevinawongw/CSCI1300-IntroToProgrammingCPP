// CSCI1300 Fall 2018
// Author: Kevina Wong CS1300 Fall 2018
// Recitation: 104 – Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/kevinawongw/csci1300
// Recitaion 6


int split (string str, char word, string arr[], int length){
    //pass initial test cases
    if(str == ""){
        return 0;
    }
    
    //normalize str
    for(int i = 0; i < str.length(); i++){
        if(str.at(i) != word){
            break;
        }else{
            str = str.substr(1);
            i--;
        }
    }
    
    for(int i = str.length()-1; i >= 0; i--){
        if(str.at(i) != word){
            break;
        }else{
            str = str.substr(0,i);
        }
    }
    
    for(int i = 0; i < str.length()-1; i++){
        if(str.at(i) == word && str.at(i+1) == word){
            str = str.substr(0,i) + str.substr(i+1);
            i--;
        }
    }

    //split str
    string splitted = str;
    int c =0;
    for (int i = 0; i < splitted.length() && c < length ;i++){
        if (splitted.at(i)==word){ 
            arr[c]=splitted.substr(0,i);
            c++;
            splitted = splitted.substr (i+1);
            i=0;
        }else if(i==splitted.length()-1){
            arr[c]=splitted;
            c++;
        }
    }
    
    //return stuff
    int wordNum = 1;
    for(int i = 0; i < str.length(); i++){
        if(str.at(i) == word){
            wordNum++;
        }
    }
    if(wordNum <= length){
        return c;
    }else{
        return -1;
    }
}