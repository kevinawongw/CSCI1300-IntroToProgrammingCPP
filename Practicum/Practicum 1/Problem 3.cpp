#include <iostream>
#include <math.h>
using namespace std;

void cardSuit (int suitNum){
    switch (suitNum){
        case 0:
        cout << "Suit 0: Clubs" << endl;
        break;
        case 1:
        cout << "Suit 1: Diamonds" << endl;
        break;
        case 2:
        cout << "Suit 2: Spades" << endl;
        break;
        case 3:
        cout << "Suit 3: Hearts" << endl;
        break;
        default:
        cout <<"Invalid"<< endl;
        break;
    }
}