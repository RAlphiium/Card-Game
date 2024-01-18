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

	void eraseLine();
	void displayCard();
	vector<string> createAscii();

	string returnSuit();
	string returnSymbol();
	int returnValue();
	bool returnOrientation();
	vector<string> returnAsciiCard();
	string returnAsciiLine(int i);
};