#ifndef CHILDGROWTH_H
#define CHILDGROWTH_H

class ChildGrowth{
    public:
    ChildGrowth ();
    ChildGrowth (string n);
    ChildGrowth (string n, int a);
    ChildGrowth (string n, int a, float h [], float w []);
    
    string getName ();
    void setName (string n);
    int getCurrentAge();
    void setCurrentAge (int a);
    void setHeight (float h[]);
    void setWeight (float w[]);
    
    float feetToMeter (float feet);
    float poundToKg (float pound);
    float calculateBmi (int age);
    string getCategory (int age);
    
    private:
    string name;
    int currentAge;
    float height [10];
    float weight [10];
    float weightMetricConversion;
};

#endif 