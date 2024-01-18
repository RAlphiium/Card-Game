#include "Card.h"
#include <iostream>
#include <string>
using namespace std;

Card::Card(string suit, string symbol, int value) {
    this->suit = suit;
    this->symbol = symbol;
    this->value = value;
    this->orientation = false;
    this->asciiCard = createAscii();
}

//Removes all \n from strings in asciiCard
void Card::eraseLine() {
    for (int i = 0; i < this->asciiCard.size(); i++) {
        this->asciiCard[i].erase(this->asciiCard[i].size() - 1);
    }
}

void Card::displayCard() {
    for (int i = 0; i < this->asciiCard.size(); i++) {
        cout << this->asciiCard[i];
    }
}

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

string Card::returnSuit() {
    return this->suit;
}
string Card::returnSymbol() {
    return this->symbol;
}
int Card::returnValue() {
    return this->value;
}
bool Card::returnOrientation() {
    return this->orientation;
}
vector<string> Card::returnAsciiCard() {
    return this->asciiCard;
}
string Card::returnAsciiLine(int i) {
    return this->asciiCard[i];
}
