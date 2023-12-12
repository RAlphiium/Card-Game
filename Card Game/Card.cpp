#include "Card.h"
#include <string>
using namespace std;

Card::Card(string suit, string symbol, int value) {
	this->suit = suit;
	this->symbol = symbol;
	this->value = value;
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