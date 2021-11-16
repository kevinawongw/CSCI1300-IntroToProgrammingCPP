#ifndef ODDEVEN_H
#define ODDEVEN_H

class OddEven{
    public:
    OddEven();
    OddEven(int myNumber[]);

    void ReadFile(string fileName);
    int getOddCount();
    int getEvenCount();
    
    private:
    int numbers[50];
};

#endif

OddEven :: OddEven(){
    for (int i = 0; i < 50; i++ ){ 
        numbers[i] = -1; 
    }
}

OddEven :: OddEven (int myNumbers[50]){
    for (int i = 0; i < 50; i++){
        numbers[i]=myNumbers[i];
    }
}

void OddEven :: ReadFile (string fileName){
    string line;
    int i=0;
    ifstream file (fileName.c_str());
    if (file.is_open()){
        while (getline(file, line)){
            int value = stoi(line);
            numbers[i]=value;
            i++;
        }
    }
}

int OddEven :: getOddCount(){
    int count=0;
    for (int i = 0 ; i < 50; i++){
        if (numbers[i]%2==1){
           count++;
        }
    }
return count;    
}


int OddEven :: getEvenCount(){
    int count=0;
    for (int i = 0 ; i < 50; i++){
        if (numbers[i]%2==0){
           count++;
        }
    }
return count;    
}