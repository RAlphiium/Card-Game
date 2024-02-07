#pragma once
using namespace std;
#include <string>
#include <vector>
#include "Card.h"

class Deck {
private:
	string label;
	vector<Card> deck;
	bool turnConcluded;
public:
	Deck(string label);

	void typeText(const string& text, int delayMilliseconds);		//Typing effect method.
	void displayCards();											//This displays all of the player's cards horizontally.
	void appendCard(Card card);										//Adds a card onto player's deck.
	void viewDeck();												//A Debugger method. Used to check the dealer's cards and their properties.
	void toggleTurnConcluded();										//NOTs the turnConcluded value when called.
	void clearDeck();												//Empties the deck attribute.

	int returnDeckValue();											//Returns deck's total value.
	vector<Card> returnDeck();										//Returns deck Attribute.
	bool returnTurnConcluded();										//Returns turnConcluded Attribute.
	Card returnCard(int i);											//Returns Card from deck Attribute specified at index: i.
};


