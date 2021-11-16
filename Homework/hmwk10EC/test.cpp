void Program :: fixSpelling(){
    cout << "Enter the phrase you would like to correct:" << endl;
    string sentence;
    getline (cin,sentence);
    stringstream sent(sentence);
    string wordss;
    bool a = true;
    while (getline (sent, wordss,' ')){
        for (int i =0; i < wordss.length();i++){
            if (wordss[i]==32){
                wordss[i]="";
            }
        }
        for (int i =0; i < wordss.length();i++){
            char c = wordss[i];
            while(!(c >= 65 && c <= 90) && !(c >= 97 && c <= 122)){
                wordss[i]="";
                cout <<"";
            }
        } 
        for (int i =0; i < wordVec.size();i++){
            if (wordss[i]==" "){
                wordss[i]==";"
            }
            if (wordss=="I" || wordss=="i"){
                cout << "I";
                a=true;
            }
            if (regex_match (toLowerCase(wordss),regex(wordVec[i))){
                cout << wordVec[i];
                a=true;
            }
            else if (toLowerCase(wordss)==toLowerCase(correctSpelling[i])){
                cout << correctSpelling[i];
                a=true;
            
            else {
                a=false;
                cout << "unknown";
            }
        }
    }
}