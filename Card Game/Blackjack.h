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

	vector<Card> returnCardDeck();
	vector<Card> returnShuffledDeck();
};

