#include <iostream>
#include <string>
using namespace std;



int split (string str, char c, string array[], int size){
    int count=0;
    int index;
    int i=0;
    string newString;
    
    for (int k=0;k<str.length();k++){
            // cout <<"FOR" << endl;
        newString= "";
        while (str[i]!=c && i <str.length()){
            // cout << "WHile" << endl;
            newString+=str[i];
            i++;
            k++;
        }
        cout << newString << endl;
        if (newString.size()!=0){
            array[k]=newString;
            count++;
            i++;
        }
        else{
            i++;
            // k++;
        }

    }
    // cout << count<< endl;
    return count;
}

int main (){
    string str = "pig/cow/dog";
    string str2 = "/pig//cow/ant";
    char c = '/';
    int size=3;
    string array[3];

    // cout <<"HI" << endl;
    cout << split(str2,c,array,3 )<<endl;
    for (int i=0;i<size;i++){
        cout << array[i] <<endl;
    }
}