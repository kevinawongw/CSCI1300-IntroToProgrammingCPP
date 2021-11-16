#ifndef DOGPROFILE_H
#define DOGPROFILE_H

class DogProfile{
    public:
    DogProfile();
    DogProfile (string myName, string myTemperament, float myBitingProbability);    
    
    string getName();
    void setName(string myname);
    string getTemperament();
    void setTemperament (string myTemperament);
    float getBitingProbability ();
    void setBitingProbability (float myBitingProbability);
    
    string goodBoy ();
    
    private:
    string name = "Fido"; 
    string temperament = "always wags tail";
    float bitingProbability = -100.0;
};
#endif


DogProfile :: DogProfile (){
    string name= "Fido";
    string temperament = "always wags tail";
    float bitingProbability = -100.0;
}

DogProfile :: DogProfile (string myName, string myTemperament, float myBitingProbability){
    name = myName;
    temperament = myTemperament;
    bitingProbability=myBitingProbability;
}

string DogProfile :: getName(){
    return name;
}

void DogProfile :: setName(string myName){
    name = myName;
}

string DogProfile :: getTemperament (){
    return temperament;
}

void DogProfile :: setTemperament(string myTemperament){
    temperament=myTemperament;
}

float DogProfile :: getBitingProbability (){
    return bitingProbability;
}

void DogProfile :: setBitingProbability(float myBitingProbability){
    bitingProbability = myBitingProbability;
}

string DogProfile :: goodBoy (){
    if (bitingProbability <= 1000.0){
        return "Good Boy";
    }
    else{
        return "Bad Boy";
    }
}