#ifndef COFFEE_H
#define COFFEE_H

class Coffee{
    public:
    Coffee();
    Coffee(string myRoastType, float myTemp);
    
    string getRoastType();
    void setRoastType(string myRoastType);
    float getTemp();
    void setTemp (float myTemp);
    
    string drinkability ();
    
    private:
    string roastType;
    float temp=180.0;
};
#endif


Coffee :: Coffee (){
    string roastType= "";
    float temp = 180.0;
}

Coffee :: Coffee (string myRoastType, float myTemp){
    roastType = myRoastType;
    temp = myTemp;
}

string Coffee :: getRoastType(){
    return roastType;
}

void Coffee :: setRoastType(string myRoastType){
    roastType = myRoastType;
}

float Coffee :: getTemp (){
    return temp;
}

void Coffee :: setTemp(float myTemp){
    temp = myTemp;
}

string Coffee :: drinkability(){
    if (temp < 100.0){
        return "Too Cold";
    }
    else if (temp >= 100.0 && temp < 160.0){
        return "Just Right";
    }
    else if (temp >= 160.0 && temp < 180.0){
        return "Hot";
    }
    else if (temp >= 180.0){
        return "Too Hot";
    }
}