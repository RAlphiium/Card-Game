#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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

// Issue: This is not truly random. Will change later.
// This will store the shuffled card deck in a local variable, which will be used to update the shuffledDeck attribute.
void Blackjack::shuffleCardDeck() {
	vector<Card> temp = this->cardDeck;				//Storing cardDeck into a local variable so cardDeck remains untouched.
	random_shuffle(temp.begin(), temp.end());		//Shuffles local variable deck.

	//for (int i = 0; i < temp.size(); i++) {		//Used to check the values and order of the shuffle code.
	//	cout << "Suit/Symbol/Value = " << temp[i].returnSuit() << "/" << temp[i].returnSymbol() << "/" << temp[i].returnValue() << '\n';
	//}

	for (int i = 0; i < temp.size(); i++) {
		this->shuffledDeck.push(temp[i]);
	}

	for (int i = 0; i < temp.size(); i++) {
		cout << "Suit/Symbol/Value = " << this->shuffledDeck.top().returnSuit() << "/" << this->shuffledDeck.top().returnSymbol() << "/" << this->shuffledDeck.top().returnValue() << '\n';
		this->shuffledDeck.pop();
	}
}

vector<Card> Blackjack::returnCardDeck() {
	return this->cardDeck;
}
stack<Card> Blackjack::returnShuffledDeck() {
	return this->shuffledDeck;
}