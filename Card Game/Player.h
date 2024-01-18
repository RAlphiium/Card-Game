#pragma once
#include <string>
#include <vector>
#include "Card.h"

class Player {
private:
	vector<Card> deck;
public:
	Player(string string);

	void typeText(const string& text, int delayMilliseconds);
	void displayCards();
	void appendCard(Card card);
	void viewDeck();

	vector<Card> returnDeck();
};
