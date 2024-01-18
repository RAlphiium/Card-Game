#pragma once
using namespace std;
#include <vector>
#include <string>
#include <stack>
#include "Card.h"
#include "Player.h"

class Blackjack{
private:
	vector<Card> cardDeck;
	stack<Card> shuffledCards;
	vector<Card> dealerDeck;
public:
	Blackjack(vector<Card> cardDeck);

	void typeText(const string& text, int delayMilliseconds);
	void displayCards();
	void startGame(Player &player);
	void appendCard(Card card);
	void viewDealerDeck();
	void outputCardDeck();					//This displays all of the possible cards in the Playing Card Suit Deck.
	void shuffleCards();					//This will update the shuffledDeck attribute by shuffling the cardDeck attribute, store it in a local variable and change its value.

	vector<Card> returnCardDeck();
	stack<Card> returnShuffledCards();
};

