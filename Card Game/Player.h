#pragma once
#include <string>
#include <vector>
#include "Card.h"

class Player {
private:
	vector<Card> deck;
	bool turnConcluded;
public:
	Player(string string);

	void typeText(const string& text, int delayMilliseconds);
	void displayCards();
	void appendCard(Card card);
	void viewDeck();
	void toggleTurnConcluded();

	int returnDeckValue();
	vector<Card> returnDeck();
	bool returnTurnConcluded();
	Card returnCard(int i);
};
