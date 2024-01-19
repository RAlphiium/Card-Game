#pragma once
using namespace std;
#include <string>
#include <vector>

class Card {
private:
	string suit;
	string symbol;
	int value;
	bool orientation;
	vector<string> asciiCard;
public:
	Card(string suit, string symbol, int value);

	void eraseLine();									//Removes all skip lines (\n) from all strings in the asciiCard vector list.
	void displayCard();									//Displays ascii art of card.
	vector<string> createAscii();						//Creates ascii art of card, putting in the card's suit and symbol.

	string returnSuit();								//Returns suit Attribute.
	string returnSymbol();								//Returns symbol Attribute.
	int returnValue();									//Returns value Attribute.
	bool returnOrientation();							//Returns orientation Attribute.
	vector<string> returnAsciiCard();					//Returns asciiCard Attribute.
	string returnAsciiLine(int i);						//Returns an element in asciiCard specified at index: i.
};