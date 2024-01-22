#pragma once
using namespace std;
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include "Card.h"
#include "Player.h"

class Blackjack{
private:
	vector<Card> cardDeck;
	stack<Card> shuffledCards;
	queue<Card> discardedCards;
	vector<Card> dealerDeck;
	bool turnConcluded;
public:
	Blackjack(vector<Card> cardDeck);

	void typeText(const string& text, int delayMilliseconds);	//Typing effect method.
	void updateVisuals(Player& player);							//This displays both dealer's and player's cards separately.
	void displayCards();										//This displays all of the dealer's cards horizontally.
	void startGame(Player& player);								//Blackjack's start method.
	void hitStandPhase(Player& player);							//Hit Stand phase of the game.
	void appendCard(Card card);									//Adds a card onto dealer's deck.
	void viewDealerDeck();										//A Debugger method. Used to check the dealer's cards and their properties.
	void outputCardDeck();										//This displays all of the possible cards in the Playing Card Suit Deck.
	void shuffleCards();										//This will update the shuffledDeck attribute by shuffling the cardDeck attribute, store it in a local variable and change its value.
	void toggleTurnConcluded();									//NOTs the turnConcluded value when called.
	void dealCards(Player& player);								//Deals 2 cards to Player and Dealer in alternating order.

	int returnDealerDeckValue();								//Returns dealerDeck Attribute.
	vector<Card> returnDealerDeck();							
	vector<Card> returnCardDeck();								//Returns cardDeck Attribute.
	stack<Card> returnShuffledCards();							//Returns shuffledCards Attribute.
	queue<Card> returnDiscardedCards();							//Returns discardedCards Attribute.
	bool returnTurnConcluded();									//Returns turnConcluded Attribute.
	Card returnCard(int i);										//Returns Card from deck Attribute specified at index: i.
};

