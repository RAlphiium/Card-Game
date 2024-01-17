#pragma once
using namespace std;
#include <vector>
#include <string>
#include <stack>
#include "Card.h"

class Blackjack{
private:
	vector<Card> cardDeck;
	stack<Card> shuffledCards;
public:
	Blackjack(vector<Card> cardDeck);

	void outputCardDeck();					//This displays all of the possible cards in the Playing Card Suit Deck.
	void shuffleCards();					//This will update the shuffledDeck attribute by shuffling the cardDeck attribute, store it in a local variable and change its value.

	vector<Card> returnCardDeck();
	stack<Card> returnShuffledCards();
};

