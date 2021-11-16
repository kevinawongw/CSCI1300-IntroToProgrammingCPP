string removeStars (string sent){
    string a = "**";
    string b = "***";
    string c = "****";
    string d = "*****";
    string e = "******";
    string f = "**********";
    for (int i=0;i<sent.length();i++){
        if (sent.substr(i,10)==f){
            sent.erase(sent.begin()+i,sent.begin()+i+10);
        }
        else if (sent.substr(i,6)==e){
            sent.erase(sent.begin()+i,sent.begin()+i+6);
        }        
        else if (sent.substr(i,5)==d){
            sent.erase(sent.begin()+i,sent.begin()+i+5);
        }
        else if (sent.substr(i,4)==c){
            sent.erase(sent.begin()+i,sent.begin()+i+4);
        }        
        else if (sent.substr(i,3)==b){
            sent.erase(sent.begin()+i,sent.begin()+i+3);
        }
        else if (sent.substr(i,2)==a){
            sent.erase(sent.begin()+i,sent.begin()+i+2);
        }
        else if (sent[i]!='*'){
            sent[i]=sent[i];
        }
        else{
            sent.erase(sent.begin()+i);
        }
    }
    return sent;
}
