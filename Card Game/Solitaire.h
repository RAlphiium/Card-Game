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
	int columns;
public:
	Solitaire(vector<Card> cardDeck);

	void typeText(const string& text, int delayMilliseconds);	//Typing effect method.
	void shuffleCards();										//This will update the shuffledDeck attribute by shuffling the cardDeck attribute, store it in a local variable and change its value.
	void checkCards(string select);								//This function will be used to check if the selected cards meet the conditions: selected 2 consecutive cards & total cards = 10,20 or 30.
	void displayCards();										//Displays all of the cards; format: 4 rows, 13 columns.
	void selectCards();
	void startGame();											//Solitaire's start method.
};

