// CSCI1300 Fall 2018
// Author: Kevina Wong CS1300 Fall 2018
// Recitation: 104 – Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/kevinawongw/csci1300
// Project 1 



//Pseudocode
/*
main (already written) directs the computer to run the void game function (which returns nothing).
void game first tells the computer to run intro.
run into outputs a welcome statememt welcoming the user to Jeopardy dice.
then define functions playerTotal and computerTotal as a global variable.
then define finalTotal (which is the player's total after each round) and finalComputerTotal (which is the computer's total after each round) equal to zero.
void game then tells the computer to run the function "playerTotal"
playerTotal runs on a while loop which states that a loop will occur as long as both finalTotal and finalComputerTotal is less than one hundred.
the loop takes the computer to the function "turnTotal"
turnTotal is a function that gets the players score per turn, then at the end of the function, it will find the player's total score for that round and add it to the finalTotal (which is the player's final score at the end of the round)
turnTotalbegins by setting roll and total to zero. Then, there is an outout statement asking the user whether or not they want to roll a dice. If the user inputs yes, then it will enter a while loop which will not break until the user says no. 
In the turnTotal while loop, it tells the computer to generate a new random number, and the followig happens:
if the random number (called "roll") is a 3, the turnTotal will be 15 and the loop will break. It will add 15 to the finalTotal
if the random number (called "roll") is a 2,4, or 5, the turn will be the rolled number added to the previous score. Then it will ask if the user wants to roll again.
if the random number (called "roll") is anything else (meaning a 1 or 6), then the turn total becomes 0 and the loop breaks.
in turnTotal, no matter what number is rolled, it will output a statement saying what the number rolled and what the turnTotal is.
since this function ends goes back to playerTotal and then there is an output statement that states the player's finalTotal and the finalComputerTotal.
then the function playerTotal tells the computer to go to function "computerTotal"
computerTotal starts with an output statement saying that it's the computer's turn.
then it enters a while loop which will run as long as the computer's turn total is less than 10.
within the while loop, a random number will be rolled, and there are if statements that are the same as the if statements in turnTotal (lines 22-24).
the while loop will break if the computer rolls a 1,3, or 6. 
at the end of the function, whatever the computer scored tha round is added to finalComputerTotal
then the function ends and goes back to playerTotal which outputs an output statement saying each of the final scores.
playerTotal loops until either the player or computer reaches 100. When this happens, the loop will break and it will output a statement saying congratulations __ won the game.

*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std;


int playerTotal(); //defines playerTotal as a global varible
int computerTotal(); //defines computerTotal as a global varibale

int finalTotal = 0; //initializes finalTotal equal to zero
int finalComputerTotal = 0; //initializes finalComputerTotal equal to zero 
/**
*intro
* outputs a welcome statement "Welcome to Jeopardy Dice"
*/
int intro() //intro function
{
    cout << "Welcome to Jeopardy Dice!" << endl; //outputs welcome statement
    cout << endl; //endline
}

/**
* rollDice
* returns a random integer between 1 and 6, works as rolling a dice.
* return value, int number (1-6)
*/
int rollDice() //func rolldice
{
    return rand() % 6 + 1; // randomly generates a number between 1 and 6
}
/**
 * turnTotal
 * outputs a statement saying ""It is now human's turn"
 * outputs a staement asking user "Do you want to roll a dice (Y/N)?:" 
 * if the user inputs a "y" or "Y" , it will enter the while loop, which will keep looping as long as the user keeps inputting "y" or "Y"
 * runs func rollDice to get a random interger between 1 and 6 called "roll"
 * if the roll = 3, the while loop breaks, and the total for that round is 15.
 * outputs two statements: one saying that the player rolled a 3 and another saying the turn total is 15.
 * if the roll = 2,4,5 then the total becomes redefined as the old total added to roll.
 * outputs two statements: one saying what the player rolled and another saying the turn total.
 * if the roll is anything else, the turn total becomes zero and the loop breaks.
 * outputs two statements: one saying what the player rolled and another saying the turn total.
 * at the end of the function total is added to finalTotal, which hold the value of the player's total score.
*/
int turnTotal() //function turnTotal
{
    int roll = 0; //intializes roll = 0
    int total = 0; //initializes total = 0 
    cout << "It is now human's turn" << endl << endl; //output statement saying that it is human's turn
    cout << "Do you want to roll a dice (Y/N)?:" << endl; // output statement asking user if they want to roll a dice
    char answer; 
    cin >> answer;
    if (answer=='y'|| answer == 'Y') //if the player inputs y or Y
    {
        while ((answer == 'y' || answer == 'Y')) // while the player inputs y or Y
        {
            roll = rollDice(); //calls rollDice function roll
            if(roll==3) //if roll =3
            {
                total = 15; // total = 15
                cout << "You rolled a 3" << endl; // output statement for what the player rolled
                cout << "Your turn total is 15" << endl; //outout statement for the player's turn total.
                break; //break while loop
            }
            else if (roll == 2 || roll == 4 || roll == 5) //if roll = 2,4,5
            {
                total += roll; //total = total + roll
                cout << "You rolled a " << roll << endl; // output statement for what the player rolled
                cout << "Your turn total is " << total << endl; //output statement for the player's turn total.
            }
            else { //if roll is something else
                total =0;
                cout << "You rolled a " << roll << endl; // output statement for what the player rolled
                cout << "Your turn total is 0" << endl; //output statement for the player's turn total.
            break; // break while loop
            }
            cout << "Do you want to roll again (Y/N)?:" << endl; //asks user if they would like to roll again
            cin >> answer;
        }
        finalTotal += total; // finalTotoal== total+total
    }
}
/**
 * computerTotal
 * outputs a statement saying ""It is now computer's turn"
 * it will enter the while loop, which will keep looping as long as the computer's turn total<10.
 * runs func rollDice to get a random interger between 1 and 6 called "roll"
 * if the roll = 3, the while loop breaks, and the total for that round is 15.
 * outputs two statements: one saying that the computer rolled a 3 and another saying the turn total is 15.
 * if the roll = 2,4,5 then the total becomes redefined as the old total added to roll.
 * outputs two statements: one saying what the computer rolled and another saying the turn total.
 * if the roll is anything else, the turn total becomes zero and the loop breaks.
 * outputs two statements: one saying what the computer rolled and another saying the turn total.
 * at the end of the function total is added to finalTotal, which hold the value of the player's total score.
*/

int computerTotal() //func computerTotal
{
    int computerTurn = 0; //sets computerTurn = 0
    cout << "It is now computer's turn" << endl << endl; // output statement saying that it is the computer's turn
    while (computerTurn<10 ) // begins while loop which will loop as long as computerturn<10
    {
    int roll = rollDice(); //calls rollDice roll
        if(roll==3) //if roll =3
        {
            computerTurn = 15; // the computerTurn value becomes 15
            cout << "Computer rolled a 3" << endl; //output statement for what the computer rolled.
            cout << "Computer turn total is 15" << endl; //output statement for the computer's turn total.
            break; // breaks while loop
        }
        else if (roll == 2 || roll == 4 || roll == 5) // if roll = 2,4, or 5
        {
            computerTurn += roll; //computerTurn=computerTurn+roll
            cout << "Computer rolled a " << roll << endl; //output statement for what the computer rolled.
            cout << "Computer turn total is " << computerTurn << endl; //output statement for the computer's turn total.
        }
        else
        {
            computerTurn= 0; //computerTurn is 0
            cout << "Computer rolled a " << roll << endl; //output statement for what the computer rolled.
            cout << "Computer turn total is 0" << endl; //output statement for the computer's turn total.
            break;
        }
    }
    finalComputerTotal += computerTurn; //finalComputerTotal = computerTurn+computerTurn
}
/**
 * playerTotal
 * while the finalTotal < 100 and finalComputerTotal < 100
 * run function turnTotal then outputs two statemets stating the final score of the player and computer for that round.
 * run function computerTotal then outputs two statemets stating the final score of the player and computer for that round.
 * once the player or computer reaches 100 the loop will break.
 * there will be an output statement congratuating the winner.

*/
int playerTotal() //function playerTotal
{

  while (finalTotal < 100 && finalComputerTotal < 100)  { // while loop which will keep looping as long as neither of the players reached a final score of 100
        turnTotal(); //run func turnTotal
        cout << "computer: " << finalComputerTotal<< endl; //output statement which states the finalComputerTotal
        cout << "human: " << finalTotal << endl<< endl; // outout statement which states the finalTotal
        if (finalTotal >= 100){ //if finalTotal is greater than/ equal to 100
            break; //break the while loop
        }
        computerTotal(); //run func computerTotal
        cout << "computer: " << finalComputerTotal<< endl; // outout statement which states the finalComputerTotal
        cout << "human: " << finalTotal << endl << endl; // outout statement which states the finalTotal
  }
  if (finalTotal >= 100){ ////if finalTotal is greater than/ equal to 100
    cout << "Congratulations! human won this round of jeopardy dice!" << endl; //output congratulations statement
  }
  else if (finalComputerTotal >= 100){//if finalComputerTotal is greater than/ equal to 100
    cout << "Congratulations! computer won this round of jeopardy dice!" << endl; //outputs congratulations statement 
  }
}


/**
* game ()
* driver function to play the game
* the function does not return any value
*/

void game()
{
    intro();
    playerTotal();
}

int main()
{
    game();
    return 0;
}
