// Card Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;
#include "Card.h"
#include "Blackjack.h"

//Create a class called blackjack that will run blackjack
//Would need to create a void function that will take a vector as a parameter, take the length of the vector and output (cout) all items to display).

void BlackjackGame() {
    vector<Card> cardDeck = createDeck();
    Blackjack test(cardDeck);
    cout << "I put the new Forgis on the Jeep.";
}
vector<Card> createDeck() {
    vector<Card> cardDeck;
    string suit;
    int value;
    for (int i = 0; i < 4; i++) {
        switch (i) {        //Iterates for all suits.
        case 0: 
            suit = "C";     //Clubs
            break;
        case 1:
            suit = "D";     //Diamonds
            break;
        case 2:
            suit = "H";     //Hearts
            break;
        case 3:
            suit = "S";     //Spades
            break;
        }


        for (int i = 0; i < 9; i++) {
            value = i + 2;
            Card card(suit, string(value), value);
        }
    }
}

int main()
{
    string choice;

    do {
        if (choice.length() == 0) {
            system("CLS");
        }
        else if (choice != "Blackjack" && choice != "Solitaire") {
            cout << "Invalid input, retry.";
            Sleep(1500);
            system("CLS");
        }
        cout << "What game do you want to play?\n";
        cout << "> Blackjack\n> Solitaire\n\nType the name of the game that you want to play: ";
        getline(cin, choice);
    } while (choice != "Blackjack" && choice != "Solitaire");

    if (choice == "Blackjack") {
        system("CLS");
        BlackjackGame();
    }
    else if (choice == "Solitaire") {
        system("CLS");
        cout << "There is nothing here yet.";
    }
    return 0;
}
