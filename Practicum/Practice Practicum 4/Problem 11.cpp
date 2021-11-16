#ifndef STATS_H
#define STATS_H

class Stats{
    public:
    Stats();
    Stats(string myData [], int myDataSize);

    void ReadFile(string fileName);
    float getAvgStringLength ();
    string getLongestString();
    
    private:
    string data[50];
    int dataSize = 50;
};

#endif

Stats :: Stats(){
    for (int i=0; i < 50; i++){
        data[i]="";
    }
    int dataSize = 50; 
}

Stats :: Stats (string myData [50], int myDataSize){
    for (int i = 0; i<50; i++){
        data[i]=myData[i];    
    }
        dataSize=myDataSize;
}

void Stats :: ReadFile (string fileName){
    string line;
    int i=0;
    ifstream file (fileName.c_str());
    if (file.is_open()){
        while (getline(file, line)){
            data[i]=line;
            // int a = line.length();
            // dataSize[i]=a;
            i++;
        }
    }
}

float Stats :: getAvgStringLength(){
    float sum=0;;
    float count=0;
    for (int i=0;i<50;i++){
        if (data[i].length()!=0){
            sum += data[i].length();
            count++;
        }
    }
float avg = sum/count;
return avg;
}

string Stats :: getLongestString (){
    float maxSize=0;
    string longest ="";
    for (int i =0; i < 50; i ++){
        if (data[i].length()>=longest.length()){
            longest = data[i];
        }    
    }
return longest;    
}