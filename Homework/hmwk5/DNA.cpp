// CSCI1300 Fall 2018
// Author: Kevina Wong CS1300 Fall 2018
// Recitation: 104 – Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/kevinawongw/csci1300
// Homework 5

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

/**
 * PSEUDOCODE:
 * 
 *simScore Pseudocode:
 * Make sure that the length of string A and string B are equal to each other. Use an if statement.
 * Write edge cases: If the lengths are unequal, return 0 & if the string (either one is empty) , return 0
 * Step through each character in the string.
 * If the characters are unequal at the index, add one to hamming. 
 * simScore = (string length - hamming)/ string length
 * return simScore
 * 
 * analyzer Pseudocode:
 * Write edge cases: 
 * 1.)If genome lengths are not the same.
 * 2.)Sequence is empty.
 * 3.)Sequence length is lonoger than the genome length.
 * All edge cases should output an error statement saying what is wrong ex.) "Genome lengths must be the same."
 * Make in if statement for the case that the genome lengths are equal to the bacteria length. 
 * In the case above, they should run the simScore function to get a matchA, matchB, or matchC value.
 * Make an else if statement for if the lengths are unequal.
 * In the case above, make a for loop that steps through the genome sequence in lengths of how long the bacteria is. Each time it steps, calculate a simScore. Set the highest simScore to matchA, matchB, or matchC.
 * Repeat this with genomeA, genomeB, and genomeC.
 * Write if/ else if statements to determine which genome has the best match.
 * Output statement should be which genome has the best match to the bacteria.
 **/

double simScore(string seqA, string seqB){ //function to get simScore. Takes two string parameters.
    double hamming=0; //defines hamming as a double and initializes it to zero.
    if (seqA.length() != seqB.length()){ //Edge case: if the sequence lengths are unequal
        return 0; //return 0
    }
    else if (seqA.length () == 0 || seqB.length () == 0){ //Edge case 2: if either sequence length is zero
        return 0; //return 0
    }
    else if (seqA.length () == seqB.length()){ //if the sequence lengths are equal
        for (int i=0; i<=seqA.length(); i++){ //steps through every character in the function.
            if (seqA [i] != seqB [i]){ //if the characters are the same at i
                hamming++; //add one to hamming
            } 
        }
        double score = (seqA.length() - hamming)/ ((double)seqA.length()); //algorithm for the score
        return score;
    }
}

void analyzer(string genomeA, string genomeB, string genomeC, string bacteria){ //function to analyze which genome has the best match to the bacteria.
    if (genomeA == "" || genomeB == "" || genomeC == "" || bacteria == "") //edge case: if genomeA, genomeB, genomeC, or bacteria is an empty string
    {
        cout << "Genome and sequence cannot be empty. " << endl; //Output "Genome and sequence cannot be empty."
        return; 
    }
    else if (genomeA.length() != genomeB.length() || genomeA.length() != genomeC.length() || genomeB.length() != genomeC.length()) //edge case: if the genome lengths are unequal
    {
        cout << "Genome length does not match. "<<endl; //Output "Genome length does not match."
        return;
    }
    else if (bacteria.length() > genomeA.length() || bacteria.length() > genomeB.length() || bacteria.length() > genomeC.length()) //edge casse: if the bacteria length is longer than the genome lengths
    {
        cout << "Sequence length must be smaller than genome length. " << endl; //Output "Sequence length must be smaller than genome length."
        return;
    }
        double matchA, matchB, matchC; //defines matchA, matchB, and matchC as a double
        if(genomeA.length()==bacteria.length()){ //if the genome lengths are equal to the becteria length.
            matchA = simScore(genomeA, bacteria); //run the simscore function with parameters genome A and bacteria to get matchA.
            matchB = simScore(genomeB, bacteria); //run the simscore function with parameters genome B and bacteria to get matchA.
            matchC = simScore(genomeC, bacteria); //run the simscore function with parameters genome C and bacteria to get matchA.
        }else
        { 
            //set matchA
            matchA = 0; //initializes matchA to 0
            for(int i = 0; i < genomeA.length() - bacteria.length(); i++) //starts a for loop which will run until genomeA.length() - bacteria.length()
            {
                string temp = genomeA.substr(i,bacteria.length()); //creates a substring
                double tempMatchA = simScore(temp, bacteria); //runs the simScore function with the parameters temp (the substring) and bacteria
                if(tempMatchA > matchA){ //if the simscore of the substring is larger than matchA
                    matchA = tempMatchA; //temp simScore becomes matchA
                }
            }
            //set matchB
            matchB = 0;
            for (int i = 0; i < genomeB.length() - bacteria.length (); i++) //starts a for loop which will run until genomeB.length() - bacteria.length()
            {
                string temp = genomeB.substr(i,bacteria.length()); //creates a substring
                double tempMatchB = simScore(temp, bacteria); //runs the simScore function with the parameters temp (the substring) and bacteria
                if (tempMatchB > matchB){ //if the simscore of the substring is larger than matchB
                    matchB = tempMatchB; //temp simScore becomes matchB
                }
            }
            //set matchC
            matchC = 0;
            for (int i = 0; i < genomeC.length() - bacteria.length (); i++) //starts a for loop which will run until genome.length() - bacteria.length()
            {
                string temp = genomeC.substr(i, bacteria.length()); //creates a substring
                double tempMatchC = simScore(temp, bacteria); //runs the simScore function with the parameters temp (the substring) and bacteria
                if (tempMatchC > matchC){ //if the simscore of the substring is larger than matchC
                    matchC = tempMatchC; //temp simScore becomes matchC
                }
            }
        }
        if ( matchA == matchB && matchA == matchC) //if all three simScores have the same value
        {
            cout <<  "Genome 1 is the best match." << endl << "Genome 2 is the best match." << endl << "Genome 3 is the best match." << endl;
        }
        else if ( matchA >= matchB && matchA >= matchC) //if matchA is greater than or equal to matchB and matchC
        {
            if (matchA == matchB) //If matchA is equal to matchB
            {
            cout << "Genome 1 is the best match." << endl << "Genome 2 is the best match." << endl;
            }
            else if (matchA == matchC) //If matchA is equal to matchC
            {
            cout << "Genome 1 is the best match." << endl << "Genome 3 is the best match." << endl;
            }
            else 
            {
            cout << "Genome 1 is the best match." << endl;
            }
        }
        else if (matchB >= matchA && matchB >= matchC) //if matchB is greater than or equal to matchA and matchC
        {
            if (matchB == matchA) //If matchA is equal to matchB
            {
            cout << "Genome 2 is the best match." << endl << "Genome 1 is the best match.";
            }
            else if (matchC == matchB)//If matchC is equal to matchB
            {
            cout << "Genome 2 is the best match." << endl << "Genome 3 is the best match." << endl;
            }
            else 
            {
                cout << "Genome 2 is the best match." << endl;
            }
        }
        else if (matchC >= matchA && matchC >= matchB) //if matchC is greater than or equal to matchA and matchB
        {
            if (matchC == matchA) //If matchA is equal to matchC
            {
            cout << "Genome 3 is the best match." << endl << "Genome 1 is the best match.";
            }
            else if (matchC == matchB) //If matchC is equal to matchB
            {
            cout << "Genome 3 is the best match." << endl << "Genome 2 is the best match." << endl;
            }
            else 
            {
                cout << "Genome 3 is the best match." << endl;
            }
        }
    }



int main (){
    //Test Cases for SimScore:
    cout << simScore("ATGT","ATGC") << endl; // Test Case 1 - Expected Value: 0.75
    cout << simScore("CGT","ATG") << endl; // Test Case 2 - Expected Value: 0
    cout << simScore("GTAC","CAGTC") << endl; // Test Case 3 - Expected Value: 0
    cout << simScore("CGTGA","GTGCA") << endl; // Test Case 4 - Expected Value: 0.2
    cout << simScore("","GTA") << endl; // Test Case 5 - Expected Value: 0
    cout << simScore("CGAT","CGTT") << endl; // Test Case 6 - Expected Value: 0.75
    //Test Cases for Analyzer:
    analyzer("AATGTTTCAC","GACCGACTAA","AAGGTGCTCC","TACTA"); //Test Case 1 - Expected Output: "Genome 2 is the best match."
    cout << endl;
    analyzer("AACT","AACT","AATG","AACT"); //Test Case 2 - Expected Output: "Genome 1 is the best match. Genome 2 is the best match."
    cout << endl;
    analyzer("ACATC","ACTTA","TACAT","AACT"); //Test Case 3 - Expected Output: "Genome 1 is the best match. Genome 2 is the best match. Genome 3 is the best match"
    cout << endl;
    analyzer("","CATTA","TAATC","ACTA"); //Test Case 4 - Expected Output: "Genome and sequence cannot be empty"
    cout << endl;
    analyzer("TAATC","CATTAA","TAATC","ACTA"); //Test Case 5 -Expected Output: "Genome length does not match."
    cout << endl;
    analyzer("TAATC","CATTA","TAATC","ACTATTT"); //Test Case 6 - Expected Output: "Sequence length must be smaller than genome length."
}