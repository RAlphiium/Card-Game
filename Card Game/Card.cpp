#include "Card.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor for Card.
Card::Card(string suit, string symbol, int value) {
    this->suit = suit;
    this->symbol = symbol;
    this->value = value;
    this->orientation = false;
    this->asciiCard = createAscii();
}

//Removes all skip lines (\n) from all strings in the asciiCard vector list.
void Card::eraseLine() {
    for (int i = 0; i < this->asciiCard.size(); i++) {
        this->asciiCard[i].erase(this->asciiCard[i].size() - 1);
    }
}

//Displays ascii art of card.
void Card::displayCard() {
    for (int i = 0; i < this->asciiCard.size(); i++) {
        cout << this->asciiCard[i];
    }
}

//Creates ascii art of card, putting in the card's suit and symbol.
vector<string> Card::createAscii() {
    vector<string> temp = {};
    string suitSymbol;
    suitSymbol = char(this->suit.at(0));

    if (symbol == "10") {
        temp.push_back(" _____________________ \n");
        temp.push_back(" |                   | \n");
        temp.push_back(" | " + this->symbol + "                | \n");
        temp.push_back(" |                   | \n");
        temp.push_back(" |                   | \n");
        temp.push_back(" |                   | \n");
        temp.push_back(" |                   | \n");
        temp.push_back(" |         " + suitSymbol + "         | \n");
        temp.push_back(" |                   | \n");
        temp.push_back(" |                   | \n");
        temp.push_back(" |                   | \n");
        temp.push_back(" |                   | \n");
        temp.push_back(" |                " + this->symbol + " | \n");
        temp.push_back(" |___________________| \n");
    }
    else {
        temp.push_back(" _____________________ \n");
        temp.push_back(" |                   | \n");
        temp.push_back(" | " + this->symbol + "                 | \n");
        temp.push_back(" |                   | \n");
        temp.push_back(" |                   | \n");
        temp.push_back(" |                   | \n");
        temp.push_back(" |                   | \n");
        temp.push_back(" |         " + suitSymbol + "         | \n");
        temp.push_back(" |                   | \n");
        temp.push_back(" |                   | \n");
        temp.push_back(" |                   | \n");
        temp.push_back(" |                   | \n");
        temp.push_back(" |                 " + this->symbol + " | \n");
        temp.push_back(" |___________________| \n");
    }

    return temp;
}

//Returns suit Attribute.
string Card::returnSuit() {
    return this->suit;
}

//Returns symbol Attribute.
string Card::returnSymbol() {
    return this->symbol;
}

//Returns value Attribute.
int Card::returnValue() {
    return this->value;
}

//Returns value Attribute.
bool Card::returnOrientation() {
    return this->orientation;
}

//Returns asciiCard Attribute.
vector<string> Card::returnAsciiCard() {
    return this->asciiCard;
}

//Returns an element in asciiCard specified at index: i.
string Card::returnAsciiLine(int i) {
    return this->asciiCard[i];
}
