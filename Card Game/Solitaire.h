#pragma once
#include <vector>
#include <string>
#include <stack>
#include "Card.h"
#include "Deck.h"

struct saves {
	vector<Card> oldShuffledDeck;								//Previous shuffledDeck
	stack<Card> oldDiscardedCards;								//Previous discardedCards
};

class Solitaire{
private:
	vector<Card> cardDeck;										//Untouched standard playing cards.
	vector<Card> shuffledDeck;									//Randomly shuffled playing cards.
	stack<Card> discardedCards;									//Stack to hold discarded cards.
	stack<saves> saveSlots;										//Stack to hold saves.
	int columns;
public:
	Solitaire(vector<Card> cardDeck);

	void typeText(const string& text, int delayMilliseconds);	//Typing effect method.
	void shuffleCards();										//This will update the shuffledDeck attribute by shuffling the cardDeck attribute, store it in a local variable and change its value.
	vector<int> bubbleSort(vector<int> list);
	vector<int> checkCards(string select);								//This function will be used to check if the selected cards meet the conditions: selected 2 consecutive cards & total cards = 10,20 or 30.
	void displayCards();										//Displays all of the cards; format: 4 rows, 13 columns.
	void selectCards();
	void startGame();											//Solitaire's start method.
	void discardCards(vector<int> indexs);

	vector<Card> returnCardDeck();								//Returns cardDeck attribute.
	vector<Card> returnShuffledDeck();							//Returns shuffledDeck attribute.
	stack<Card> returnDiscardedCards();							//Returns discardedCards attribute.
	int returnColumns();										//Returns columns attribute.
};

