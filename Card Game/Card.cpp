#include "Card.h"
#include <string>
using namespace std;

Card::Card(string suit, int value) {
	this->suit = suit;
	this->value = value;
}

string Card::returnSuit() {
	return this->suit;
}
int Card::returnValue() {
	return this->value;
}