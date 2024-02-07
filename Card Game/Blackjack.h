#pragma once
using namespace std;
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include "Card.h"
#include "Deck.h"

class Blackjack {
private:
	vector<Deck> participants;
	vector<Card> cardDeck;
	stack<Card> shuffledCards;
	queue<Card> discardedCards;
	bool midgameShuffle;
public:
	Blackjack(vector<Card> cardDeck, vector<Deck> participants);

	void typeText(const string& text, int delayMilliseconds);	//Typing effect method.
	void shuffleCards();										//This will update the shuffledDeck attribute by shuffling the cardDeck attribute, store it in a local variable and change its value.
	void shuffleCards(queue<Card> discardedCards);				// This is an overrided function that will shuffle a given deck.
	void dealCards();											//Deals 2 cards to Player and Dealer in alternating order.
	void startGame();											//Blackjack's start method.
	void hitStandPhase();										//Hit Stand phase of the game.
	void updateVisuals();										//This displays both dealer's and player's cards separately.
	void toggleMidgameShuffle();								//NOTs the midgameShuffle value when called.

	vector<Deck> returnParticipants();							//Returns participants Attribute.
	vector<Card> returnCardDeck();								//Returns cardDeck Attribute.
	stack<Card> returnShuffledCards();							//Returns shuffleDeck Attribute.
	queue<Card> returnDiscardedCards();							//Returns discardedCards Attribute.
	bool ReturnMidgameShuffle();								//Returns midgameShuffle Attribute.




	/*
	void updateVisuals(Deck& player);							//This displays both dealer's and player's cards separately.
	void displayCards();										//This displays all of the dealer's cards horizontally.
	void startGame(Deck& player);								//Blackjack's start method.
	void hitStandPhase(Deck& player);							//Hit Stand phase of the game.
	void appendCard(Card card);									//Adds a card onto dealer's deck.
	void viewDealerDeck();										//A Debugger method. Used to check the dealer's cards and their properties.
	void outputCardDeck();										//This displays all of the possible cards in the Playing Card Suit Deck.
	void shuffleCards();										//This will update the shuffledDeck attribute by shuffling the cardDeck attribute, store it in a local variable and change its value.
	void shuffleCards(queue<Card> discardedCards);
	void toggleTurnConcluded();									//NOTs the turnConcluded value when called.
	void dealCards(Deck& player);								//Deals 2 cards to Player and Dealer in alternating order.
	void toggleMidgameShuffle();								//NOTs the midgameShuffle value when called.

	int returnDealerDeckValue();								//Returns dealerDeck Attribute.
	vector<Card> returnDealerDeck();
	vector<Card> returnCardDeck();								//Returns cardDeck Attribute.
	stack<Card> returnShuffledCards();							//Returns shuffledCards Attribute.
	queue<Card> returnDiscardedCards();							//Returns discardedCards Attribute.
	bool returnTurnConcluded();									//Returns turnConcluded Attribute.
	Card returnCard(int i);										//Returns Card from deck Attribute specified at index: i.
	bool returnMidgameShuffle();								//Returns midgameShuffle Attribute.
	*/
};


