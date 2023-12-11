using namespace std;
#include <vector>
#include <string>
#include "Blackjack.h"
#include "Card.h"

Blackjack::Blackjack(vector<Card> cardDeck) {
	this->cardDeck = cardDeck;
}

vector<Card> Blackjack::returnCardDeck() {
	return this->cardDeck;
}
vector<Card> Blackjack::returnShuffledDeck() {
	return this->shuffledDeck;
}