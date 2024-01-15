#pragma once
using namespace std;
#include <string>

class Card {
private:
	string suit;
	string symbol;
	int value;
	bool orientation;
public:
	Card(string suit, string symbol, int value);

	string returnSuit();
	string returnSymbol();
	int returnValue();
	bool returnOrientation();
};