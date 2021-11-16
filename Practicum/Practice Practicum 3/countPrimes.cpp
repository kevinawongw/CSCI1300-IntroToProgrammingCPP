#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;


bool IsPrime (int number){
    bool ans = true;
    if (number >1){
        if (number%1==0){
            ans=true;
        }
        if (number%2==0 && number != 2){
            return false;
        }
        if (number%3==0 && number != 3){
            ans = false;
        }
        if (number%4==0 && number != 4){
            ans = false;
        }
        if (number%5==0 && number != 5){
            ans = false;
        }
        if (number%6==0 && number != 6){
            ans = false;
        }
        if (number%7==0 && number != 7){
            ans = false;
        } 
        if (number%8==0 && number != 8){
            ans = false;
        }
        if (number%9==0 && number != 9){
            ans = false;
        }
        if (number%10==0 && number !=10 ){
            ans = false;
        }
        return ans;
    }
    else{
        return false;
    }
}

int countPrimes(int array[], int size){
    int count =0;
    for (int i =0; i < size; i++){
        int number = array[i];
        if (IsPrime(number)==true){
            count++;
        }
    }
    return count;
}

int main (){
    int arrayaa[5] = {1, 2, 3, 4, 0};
    cout << countPrimes(arrayaa, 5);
    
    int array[10] = {1, 2, 3, 14, 5, 6, 7, 8, 9, 10};
    cout << countPrimes(array, 10);
    
}