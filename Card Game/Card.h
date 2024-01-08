#pragma once
using namespace std;
#include <string>

class Card{
private:
	string suit;
	string symbol;
	int value;
	//May add an orientation attribute later (used to tell if card is faced up/down or rotated)
public:
	Card(string suit,string symbol,int value);

	string returnSuit();
	string returnSymbol();
	int returnValue();
};

