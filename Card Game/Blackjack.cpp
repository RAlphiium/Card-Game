#include <iostream>
#include <vector>
#include <string>
#include "Blackjack.h"
#include "Card.h"
using namespace std;

Blackjack::Blackjack(vector<Card> cardDeck) {
	this->cardDeck = cardDeck;
}

// This displays all of the possible cards in the Playing Card Suit Deck.
// Honestly, the purpose of this class method is to check if it contains all of the right elements, and if all of the elements contain the right properties.
void Blackjack::outputCardDeck() {
	for (int i = 0; i < cardDeck.size(); i++) {
		cout << "Suit/Symbol/Value = " << cardDeck[i].returnSuit() << "/" << cardDeck[i].returnSymbol() << "/" << cardDeck[i].returnValue() << '\n';
	}
	cout << "Playing Card Suits Deck Size = " << cardDeck.size() << '\n';
}

vector<Card> Blackjack::returnCardDeck() {
	return this->cardDeck;
}
vector<Card> Blackjack::returnShuffledDeck() {
	return this->shuffledDeck;
}