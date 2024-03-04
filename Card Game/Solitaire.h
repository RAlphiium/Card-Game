#pragma once
#include <vector>
#include <string>
#include <queue>
#include "Card.h"
#include "Deck.h"

class Solitaire{
private:
	vector<Card> cardDeck;
	vector<Card> shuffledDeck;
	queue<Card> discardedCards;
public:
	Solitaire(vector<Card> cardDeck);

	void typeText(const string& text, int delayMilliseconds);	//Typing effect method.
	void shuffleCards();										//This will update the shuffledDeck attribute by shuffling the cardDeck attribute, store it in a local variable and change its value.
	void displayCards();										//Displays all of the cards; format: 4 rows, 13 columns.
	void startGame();											//Solitaire's start method.
};

