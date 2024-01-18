#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "Player.h"
#include "Card.h"
using namespace std::this_thread;
using namespace std::chrono;
using namespace std;


Player::Player(string string) {
	this->deck = {};
}

void Player::typeText(const string& text, int delayMilliseconds) {
	for (char c : text) {
		cout << c << flush;
		sleep_for(milliseconds(delayMilliseconds));
	}
}

void Player::displayCards() {
	vector<Card> temp = this->deck;								//In order to not change the actual card data.
	int asciiCardSize = this->deck[0].returnAsciiCard().size();	//No. of lines in ascii card.
	int listSize = this->deck.size();							//No. of cards in player's deck.
	vector<string> asciiStrings;
	string placeHolder;

	// Removes all skip lines for every ascii card except from last.
	for (int i = 0; i < (listSize - 1); i++) {
		temp[i].eraseLine();
	}

	// Concatenates the same string lines together.
	for (int i = 0; i < asciiCardSize; i++) {
		for (int j = 0; j < listSize; j++) {
			placeHolder = placeHolder + temp[j].returnAsciiLine(i);
		}
		//Appends to string list that contains all of the lines together.
		asciiStrings.push_back(placeHolder);
		//Resets the variable.
		placeHolder = "";
	}

	typeText("Player's cards: \n",30);
	for (int i = 0; i < asciiStrings.size(); i++) {
		cout << asciiStrings[i];
	}
	cout << '\n';
}

void Player::appendCard(Card card) {
	this->deck.push_back(card);
}
void Player::viewDeck() {							//Used to debug.
	cout << "Player's hand: \n";
	for (int i = 0; i < this->deck.size(); i++) {
		cout << "Suit/Symbol/Value = " << this->deck[i].returnSuit() << "/" << this->deck[i].returnSymbol() << "/" << this->deck[i].returnValue() << '\n';
	}
}

vector<Card> Player::returnDeck() {
	return this->deck;
}