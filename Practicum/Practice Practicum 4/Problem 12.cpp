#ifndef TEMPERATURES_H
#define TEMPERaTURES_H

class Temperatures{
    public:
    Temperatures();
    Temperatures(float myTemp_values [], string myDays []);

    void ReadFile(string fileName);
    float getMinTemp();
    string getMinTempDay();
    
    private:
    float temp_values[7];
    string days [7];
};

#endif

Temperatures :: Temperatures(){
    for (int i = 0; i < 7; i++){
        temp_values[i]=120.0;
    }
    for (int i =0; i < 7; i++){
        days[i]="";
    }
}

Temperatures :: Temperatures (float myTemp_values [], string myDays []){
    for (int i = 0; i < 7; i++){
        temp_values[i]=myTemp_values[i];
    }
    for (int i =0; i < 7; i++){
        days[i]=myDays[i];
    }
}

void Temperatures :: ReadFile (string fileName){
    string line;
    int i=0;
    ifstream file (fileName.c_str());
    if (file.is_open()){
        while (getline(file, line)){
            string tempAndDay[2];
            split (line, ',', tempAndDay, 2);
            string dayOfWk = tempAndDay[0];
            float temp = stof(tempAndDay[1]);
            days[i]=dayOfWk; 
            temp_values[i] = temp;
            i++;
        }
    }
}

float Temperatures :: getMinTemp(){
    float minTemp=0;
    for (int i = 0; i < 7; i++){
        if (temp_values[i]<=minTemp){
            minTemp=temp_values[i];
        }
    }
return minTemp;
}

string Temperatures :: getMinTempDay(){
    float minTemp=0;
    string minDay="";
    for (int i = 0; i < 7; i++){
        if (temp_values[i]<=minTemp){
            minTemp=temp_values[i];
            minDay=days[i];
        }
        if (minDay == "1"){
            minDay = "Sunday";
        }
        if (minDay == "2"){
            minDay = "Monday";
        }
        if (minDay == "3"){
            minDay = "Tuesday";
        }
        if (minDay == "4"){
            minDay = "Wednesday";
        }
        if (minDay == "5"){
            minDay = "Thursday";
        }
        if (minDay == "6"){
            minDay = "Friday";
        }
        if (minDay == "7"){
            minDay = "Saturday";
        }
    }
return minDay;
}