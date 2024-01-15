#include "Card.h"
#include <string>
using namespace std;

Card::Card(string suit, string symbol, int value) {
	this->suit = suit;
	this->symbol = symbol;
	this->value = value;
	this->orientation = false;
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