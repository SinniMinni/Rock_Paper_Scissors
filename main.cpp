//
//  main.cpp
//  Rock_Paper_Scissors
//
//  Created by Sanjeev Shankar 


/**
Paper Scissors Rock
 Paper-Scissors-Rock is a game for two players. Each player simultaneously opens his/her hand to display a symbol:
 - Fist equals rock
 - Open hand equals paper
 - Showing the index and middle finger equals scissors
 The winner is determined by the following schema:
 - Paper beats (wraps) rock
 - Rock beats (blunts) scissors
 - Scissors beats (cuts) paper
 Write a Program that plays PaperScissorsRock between the computer and a real player. You should be able to play the game n times
 before the programexits.
 
 */


#include <iostream>
#include <string>

using namespace std;

/**
 
 Let Different Hand Actions be represented by Integers
 
 0 -> Fist / Rock
 1 -> Open Hands / Paper
 2 -> Showing Index and Middle Finger / Scissors
 
 */

//Macros for Symbols/Actions
#define ROCK     0
#define PAPER    1
#define SCISSORS 2

//Macros To Identify Players
#define PLAYER   0
#define COMP     1
#define NO_ONE   2

//Implement a Winning Matrix : Row is PLAYER's Choice and Column is COMP Choice
int WINNER[3][3] = {
    {NO_ONE, COMP, PLAYER},
    {PLAYER, NO_ONE, COMP},
    {COMP, PLAYER, NO_ONE}};

/**
 Get The name of Choice in String Pattern
 */
string expandChoice(int in)
{
    string choice_name;
    if (in == ROCK)
        choice_name = "Rock";
    else if (in == PAPER)
        choice_name = "Paper";
    else if (in == SCISSORS)
        choice_name = "Scissors";
    
    return choice_name;
}
/**
 Function to Get Players Choice
 If Player Enters -1 Then Game Quits
 */
int getPlayersChoice()
{
    int choice = -1;
    string line;

    cout << "------------------------------------" << endl;
    cout << "Enter : 0 for Rock: 1 for Paper: 2 for Scissors" <<endl;
    cout << "Enter Any Other key to Exit Game !!!" << endl;
    cout << "------------------------------------" << endl;
    
    //In Case Non Integer Key is Pressed
    if(!(cin >> choice))
    {
        cin.clear();
        cout << "Exiting!!!  ";
        choice = -1;
    }
    
    if (choice != ROCK &&
        choice != PAPER &&
        choice != SCISSORS)
    {
        choice = -1;
    }

    return choice;
}

/**
 Function to Get Computers Choice
 */
int getCompChoice()
{
    srand((unsigned)time(0));
    int choice = rand() % 3;
    return choice;
}

int main(int argc, const char * argv[]) {
    
    int player_choice = 0, comp_choice = 0;
    cout << "------------------------------------" << endl;
    cout << " Rock Paper Scissors! " << endl;
    cout << "------------------------------------" << endl;
    
    while(true)
    {
        player_choice = getPlayersChoice();
        if(player_choice == -1)
            break;
        
        comp_choice = getCompChoice();
        
        cout << "------------------------------------" << endl;
        cout << "Your Choice: " << expandChoice(player_choice) << endl;
        cout << "Computers Choice: " << expandChoice(comp_choice) << endl;
        cout << "------------------------------------" << endl;
        cout << "------------------------------------" << endl;

        if(WINNER[player_choice][comp_choice] == PLAYER)
            cout << "You Win!" << endl;
        else if(WINNER[player_choice][comp_choice] == COMP)
            cout << "Computer Wins!" << endl;
        else
            cout << "!!! TIE !!!" << endl;
    }//while loop 


    cout << "BYE :) " << endl;

    return 0;
}//main
