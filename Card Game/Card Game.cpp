// Card Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;
#include "Card.h"
#include "Blackjack.h"

// This function essentially creates all the cards in Playing Cards Suit by using:
//      - A for loop that will iterate four times - This is done in order to create the 13 cards for each suit.
//          - This is done by changing the value for the String Variable: suit, to the respective value of the current iteration.
//      - Series of instantiations using the class "Card" and inputting arguments for the Card's Suit,Symbol and Value.
//          - A for loop and series of lines of code has been used to achieve this.
//      - All of these are pushed onto the vector, containing Cards, cardDeck after instantiation.
//      - After the for loop concludes, the function return cardDeck.
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
    Blackjack test(cardDeck);
    test.outputCardDeck();
    test.shuffleCards();
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
        BlackjackGame();
    }
    else if (choice == "Solitaire") {
        system("CLS");
        cout << "There is nothing here yet.";
    }
    return 0;
}
