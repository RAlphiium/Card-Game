#pragma once
using namespace std;
#include <vector>
#include <string>
#include "Card.h"

class Blackjack{
private:
	vector<Card> cardDeck;
	vector<Card> shuffledDeck;
public:
	Blackjack(vector<Card> cardDeck);

	void outputCardDeck();					//This displays all of the possible cards in the Playing Card Suit Deck.

	vector<Card> returnCardDeck();
	vector<Card> returnShuffledDeck();
};

