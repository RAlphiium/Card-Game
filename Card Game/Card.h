#pragma once
using namespace std;
#include <string>

class Card{
private:
	string suit;
	int value;
public:
	Card(string suit,int value);

	string returnSuit();
	int returnValue();
};

