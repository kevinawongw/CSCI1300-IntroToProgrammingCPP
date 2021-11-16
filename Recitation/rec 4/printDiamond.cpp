#include <iostream>
using namespace std;

void printDiamond (int side){

for (int i = 0; i < side; i++) {
    for (int x = 0; x < (side - i - 1); x++) {
        cout << " ";
    }
    for (int y = 0; y < (2 * i + 1); y++) {
        cout << "*";
    }
    cout << endl;
}

for (int i = 0; i < side; i++) {
    int number = 0;
    number+= 2;
    for (int x = 0; x < (side - side + i + 1); x++) {
        cout << " ";
    }
    for (int y = 0; y < 2*(side-i-1)-1 ; y++) {
        cout << "*";
    }
    cout << endl;
}
}





int main (){
    printDiamond(3);
}