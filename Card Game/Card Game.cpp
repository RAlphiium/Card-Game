// Card Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <chrono>
#include <thread>
#include "Card.h"
#include "Blackjack.h"
using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

// This function essentially creates all the cards in Playing Cards Suit by using:
//      - A for loop that will iterate four times - This is done in order to create the 13 cards for each suit.
//          - This is done by changing the value for the String Variable: suit, to the respective value of the current iteration.
//      - Series of instantiations using the class "Card" and inputting arguments for the Card's Suit,Symbol and Value.
//          - A for loop and series of lines of code has been used to achieve this.
//      - All of these are pushed onto the vector, containing Cards, cardDeck after instantiation.
//      - After the for loop concludes, the function return cardDeck.

void typeText(const string& text, int delayMilliseconds) {
    for (char c : text) {
        cout << c << flush;
        sleep_for(milliseconds(delayMilliseconds));
    }
}
vector<Card> createDeck() {
    vector<Card> cardDeck;
    string suit;
    string symbol;
    int value;
    for (int i = 0; i < 4; i++) {
        switch (i) {        //Iterates for all suits.
        case 0:
            suit = "Clubs";     //Clubs
            break;
        case 1:
            suit = "Diamonds";     //Diamonds
            break;
        case 2:
            suit = "Hearts";     //Hearts
            break;
        case 3:
            suit = "Spades";     //Spades
            break;
        }

        //Generating Ace card
        value = 1;
        symbol = "A";
        Card card1(suit, symbol, value);
        cardDeck.push_back(card1);
        //Generating cards number 2-10
        for (int i = 0; i < 9; i++) {
            value = i + 2;
            symbol = to_string(value);
            Card card(suit, symbol, value);
            cardDeck.push_back(card);
        }
        //Generating Jack card
        value = 10;
        symbol = "J";
        Card card2(suit, symbol, value);
        cardDeck.push_back(card2);
        //Generating Queen card
        value = 10;
        symbol = "Q";
        Card card3(suit, symbol, value);
        cardDeck.push_back(card3);
        //Generating King card
        value = 10;
        symbol = "K";
        Card card4(suit, symbol, value);
        cardDeck.push_back(card4);
    }
    return cardDeck;
}
void BlackjackGame() {
    vector<Card> cardDeck = createDeck();
    Blackjack blackjack(cardDeck);
    Player player("string");

    blackjack.shuffleCards();
    blackjack.startGame(player);

}

int main()
{
    string choice;

    do {
        typeText("What game do you want to play?\n",30);
        typeText("> Blackjack\n> Solitaire\n\nType the name of the game that you want to play: ",30);
        getline(cin, choice);
        if (choice.empty()) {
            typeText("\nInvalid input, retry.", 30);
            Sleep(1500);
            system("CLS");
        }
        else if (choice != "Blackjack" && choice != "blackjack" && choice != "Solitaire" && choice != "solitaire") {
            typeText("\nInvalid input, retry.", 30);
            Sleep(1500);
            system("CLS");
        }
    } while (choice != "Blackjack" && choice != "blackjack" && choice != "Solitaire" && choice != "solitaire");

    if (choice == "Blackjack" || choice == "blackjack") {
        typeText("\nSetting up Blackjack", 30);
        for (int i = 0; i < 3; i++) {
            cout << ".";
            Sleep(1000);
        }
        system("CLS");
        BlackjackGame();
    }
    else if (choice == "Solitaire" || choice == "solitiare") {
        system("CLS");
        cout << "There is nothing here yet.";
    }
    return 0;
}
