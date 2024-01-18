#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <Windows.h>
#include "Blackjack.h"
#include "Card.h"
using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

Blackjack::Blackjack(vector<Card> cardDeck) {
	this->cardDeck = cardDeck;
	this->dealerDeck = {};
}
void Blackjack::typeText(const string& text, int delayMilliseconds) {
	for (char c : text) {
		cout << c << flush;
		sleep_for(milliseconds(delayMilliseconds));
	}
}

void Blackjack::updateVisuals(Player& player) {
	displayCards();
	player.displayCards();
}

void Blackjack::displayCards() {
	vector<Card> temp = this->dealerDeck;								//In order to not change the actual card data.
	int asciiCardSize = this->dealerDeck[0].returnAsciiCard().size();	//No. of lines in ascii card.
	int listSize = this->dealerDeck.size();							//No. of cards in player's deck.
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

	typeText("Dealer's cards: \n", 30);
	for (int i = 0; i < asciiStrings.size(); i++) {
		cout << asciiStrings[i];
	}
	typeText("Dealer's deck value: " + to_string(returnDealerDeckValue()) + "\n", 30);
	cout << '\n';
}

void Blackjack::startGame(Player &player) {						
	typeText("Dealer: Now dealing us our cards.\n",30);
	string choice;
	
	for (int i = 0; i < 2; i++) {
		player.appendCard(this->shuffledCards.top());
		this->shuffledCards.pop();
		appendCard(this->shuffledCards.top());
		this->shuffledCards.pop();
	}

	do {
		updateVisuals(player);
		typeText("Dealer: It is your turn. Hit or Stand? ", 30);
		getline(cin, choice);
		
		if (choice == "Hit") {
			player.appendCard(this->shuffledCards.top());
			this->shuffledCards.pop();
			system("CLS");
			typeText("Dealer: You have received a [" + player.returnCard(player.returnDeck().size() - 1).returnSymbol() + " of " + player.returnCard(player.returnDeck().size() - 1).returnSuit() + "].\n", 30);
		}
		else if (choice == "Stand") {
			player.toggleTurnConcluded();
		}
		else if (choice.empty()) {
			typeText("Dealer: You gotta make a choice. Try again.",30);
			Sleep(1500);
			system("CLS");
		}
		else if (choice != "Hit" && choice != "Stand") {
			typeText("Dealer: Invalid choice. Try again.",30);
			Sleep(1500);
			system("CLS");
		}
	} while (player.returnTurnConcluded() == false);

	typeText("Dealer: Uh", 30);
	for (int i = 0; i < 3; i++) {
		cout << ".";
		Sleep(1000);
	}
	typeText("\nDealer: This is all so far.", 30);
}

void Blackjack::appendCard(Card card) {
	this->dealerDeck.push_back(card);
}

void Blackjack::viewDealerDeck() {							//Used to debug.
	cout << "Dealer's hand: \n";
	for (int i = 0; i < this->dealerDeck.size(); i++) {
		cout << "Suit/Symbol/Value = " << this->dealerDeck[i].returnSuit() << "/" << this->dealerDeck[i].returnSymbol() << "/" << this->dealerDeck[i].returnValue() << '\n';
	}
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

	for (int i = 0; i < size; i++) {							// Shuffles the cards using Fisher Yates' algorithm.
		randomNumber = rand() % (size-i);						/* Main feature of Fisher Yates' algorithm. Essentially shifts the "new ending index" towards the starting index so the swapped elements
																at the ending of the list is fixed/untouched*/
		swap(temp[randomNumber], temp[size - (i + 1)]);
	}
	for (int i = 0; i < size; i++) {
		this->shuffledCards.push(temp[i]);
	}
	//for (int i = 0; i < temp.size(); i++) {					// Shows the arrangement of the elements in shuffledCards.
	//	cout << "Suit/Symbol/Value = " << this->shuffledCards.top().returnSuit() << "/" << this->shuffledCards.top().returnSymbol() << "/" << this->shuffledCards.top().returnValue() << '\n';
	//	this->shuffledCards.pop();
	//}
	typeText("Dealer: The cards have been shuffled.\n",30);
}

int Blackjack::returnDealerDeckValue() {
	int value = 0;
	for (int i = 0; i < this->dealerDeck.size(); i++) {
		value = value + this->dealerDeck[i].returnValue();
	}
	return value;
}
vector<Card> Blackjack::returnCardDeck() {
	return this->cardDeck;
}
stack<Card> Blackjack::returnShuffledCards() {
	return this->shuffledCards;
}