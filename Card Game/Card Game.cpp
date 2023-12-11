// Card Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
#include "Card.h"

void Blackjack() {
    cout << "I put the new Forgis on the Jeep.";
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
        Blackjack();
    }
    else if (choice == "Solitaire") {
        system("CLS");
        cout << "There is nothing here yet.";
    }
}
