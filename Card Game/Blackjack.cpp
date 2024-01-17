#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
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

// This will store the shuffled card deck in a local variable, which will be used to update the shuffledDeck attribute.
void Blackjack::shuffleCards() {
	vector<Card> temp = this->cardDeck;
	srand((unsigned)time(NULL));
	int size = temp.size();
	int randomNumber;

	for (int i = 0; i < size; i++) {			// Shuffles the cards using Fisher Yates' algorithm.
		randomNumber = rand() % (size-i);		/* Main feature of Fisher Yates' algorithm. Essentially shifts the "new ending index" towards the starting index so the swapped elements
												at the ending of the list is fixed/untouched*/
		swap(temp[randomNumber], temp[size - (i + 1)]);
	}
	for (int i = 0; i < size; i++) {
		this->shuffledCards.push(temp[i]);
	}
	//for (int i = 0; i < temp.size(); i++) {		// Shows the arrangement of the elements in shuffledCards.
	//	cout << "Suit/Symbol/Value = " << this->shuffledCards.top().returnSuit() << "/" << this->shuffledCards.top().returnSymbol() << "/" << this->shuffledCards.top().returnValue() << '\n';
	//	this->shuffledCards.pop();
	//}
	cout << "The cards have been shuffled.\n";
}

vector<Card> Blackjack::returnCardDeck() {
	return this->cardDeck;
}
stack<Card> Blackjack::returnShuffledCards() {
	return this->shuffledCards;
}