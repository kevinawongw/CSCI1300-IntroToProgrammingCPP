#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


void printVectorRecursive(vector<int> myVector){
    if (myVector.size() == 0){
        return;
    }
    else{
        cout << myVector[0] << " ";
        myVector.erase(myVector.begin());
        printVectorRecursive(myVector);
    }
}

int sumVector(vector<int> myVector, int sum){
    if (myVector.size() == 0){
        return sum;
    }
    else{
        sum += myVector[0];
        myVector.erase(myVector.begin());
        return sumVector(myVector,sum);
    }
}


vector<int> getVector(vector<int> temp, int stop){
    if (temp.size() == 0){
        temp.push_back(1);
        int sum = 1;
        return getVector(temp,stop - sumVector(temp,0));
    }
    else if (stop == 0){
        return temp;
    }
    else{
        int tempSum = sumVector(temp,0);
        if (sumVector(temp,0) < stop){
            temp.push_back(sumVector(temp,0));
            return getVector(temp,stop - tempSum);
        }
        else{
            temp.push_back(sumVector(temp,0));
            return temp;
        }
    }
    
}

void fillCumulativeSum(int stop){
    vector<int> vect;
    vect = getVector(vect, stop);
    printVectorRecursive(vect);
}
    
    
int main(){

    fillCumulativeSum(1);
    fillCumulativeSum(15);

}

