#ifndef PLAYERS_H
#define PLAYERS_H

class Players{
    public:
    Players();
    Players (string myName, float mySalaries[]);
    
    void ReadFile(string fileName);
    float MaxSalary();
    string MaxSalaryName();
    
    private:
    string names [50];
    float salaries [50];
};

#endif

Players :: Players(){
    for (int i = 0; i < 50; i++){
        names[i]="";
    }
    for (int i = 0; i < 50; i++ ){ 
        salaries[i] = -1.0; 
    }
}

Players :: Players (string myName, float mySalaries[50]){
    for (int i = 0; i < 50; i++){
        names[i]=myName[i];
    }    
    for (int i = 0; i < 50; i++){
        salaries[i]=mySalaries[i];
    }
}

void Players :: ReadFile (string fileName){
    string line;
    int i=0;
    ifstream file (fileName.c_str());
    if (file.is_open()){
        while (getline(file, line)){
            string nameSal[2];
            split (line, ',', nameSal, 2);
            string nameA = nameSal[0];
            float salary = stof(nameSal[1]);
            names[i]=nameA; 
            salaries[i]=salary; 
            i++;
        }
    }
}

float Players :: MaxSalary (){
    float maxSalary=0;
    for (int i=0; i < 50; i++){
        if (salaries[i]>maxSalary){
            maxSalary = salaries[i];
        }
    }
    return maxSalary; 
}

string Players ::  MaxSalaryName (){
    float maxSalary=0;
    string salaryName = "";
    for (int i=0; i < 50; i++){
        if (salaries[i]>maxSalary){
            salaryName = names[i];
        }    
    }
    return salaryName;
}