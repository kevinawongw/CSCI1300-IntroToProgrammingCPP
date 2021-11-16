#ifndef DICE_H
#define DICE_H
#include "Dice.h"
#include "Player.h"

class Dice {
    
    private:
        const int faceValue;      // dice value variable

    public:
        Dice();             // default constructor
        void roll();        // to roll the dice
        int getFaceValue(); // to get the dice face value

};
#endif