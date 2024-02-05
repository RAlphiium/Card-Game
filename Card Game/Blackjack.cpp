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

//Constructor for Blackjack/
Blackjack::Blackjack(vector<Card> cardDeck) {
	this->cardDeck = cardDeck;
	this->dealerDeck = {};
	this->turnConcluded = false;
	this->midgameShuffle = false;
}

//Typing effect method.
void Blackjack::typeText(const string& text, int delayMilliseconds) {
	for (char c : text) {
		cout << c << flush;
		sleep_for(milliseconds(delayMilliseconds));
	}
}

//This displays both dealer's and player's cards separately.
void Blackjack::updateVisuals(Player& player) {
	displayCards();
	player.displayCards();
}

//This displays all of the dealer's cards horizontally.
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

//Blackjack's start method.
void Blackjack::startGame(Player &player) {						
	string choice;

	shuffleCards();
	do {
		if (midgameShuffle == true) {									//Case: midgame shuffle had occured in the previous game.
			typeText("Dealer: Since a midgame shuffle occured in the previous game, the cards must be shuffled again.\n", 30);
			Sleep(1500);
			typeText("Dealer: I will now deal the cards.\n", 30);
			Sleep(1500);
			for (int i = 0; i < player.returnDeck().size(); i++) {		//Discard all cards.
				this->discardedCards.push(player.returnDeck()[i]);
			}
			player.clearDeck();

			for (int i = 0; i < returnDealerDeck().size(); i++) {		//Discard all cards.
				this->discardedCards.push(returnDealerDeck()[i]);
			}
			this->dealerDeck.clear();

			for (int i = 0; i < this->shuffledCards.size(); i++) {		//Discard all cards.
				this->discardedCards.push(shuffledCards.top());
				this->shuffledCards.pop();
			}
			shuffleCards(this->discardedCards);							//Resets
			toggleMidgameShuffle();
			dealCards(player);
		}
		else if (this->shuffledCards.size() < 4) {						//Case: there are not enough cards to deal.
			typeText("Dealer: There are not enough cards to start the next game. All cards will be discarded and shuffled.\n", 30);
			Sleep(1500);
			typeText("Dealer: I will now deal the cards.\n", 30);
			Sleep(1500);
			for (int i = 0; i < player.returnDeck().size(); i++) {		//Discard all cards.
				this->discardedCards.push(player.returnDeck()[i]);
			}
			player.clearDeck();

			for (int i = 0; i < returnDealerDeck().size(); i++) {		//Discard all cards.
				this->discardedCards.push(returnDealerDeck()[i]);
			}
			this->dealerDeck.clear();

			for (int i = 0; i < this->shuffledCards.size(); i++) {		//Discard all cards.
				this->discardedCards.push(shuffledCards.top());
				this->shuffledCards.pop();
			}
			shuffleCards(this->discardedCards);							//Resets
			dealCards(player);
		}
		else if (player.returnDeck().size() == 0 && returnDealerDeck().size() == 0) {	//Case: First game.
			typeText("Dealer: I will now deal the cards.\n", 30);
			Sleep(1500);
			//Appends a card to the player then the dealer. Iterates 2 times so that both have 2 cards each.
			dealCards(player);
		}
		else if (player.returnDeck().size() != 0 && returnDealerDeck().size() != 0) {	//Case: After completing a game and moving onto a new game.
			typeText("Dealer: I will now deal new cards.\n", 30);
			Sleep(1500);
			for (int i = 0; i < player.returnDeck().size(); i++) {
				this->discardedCards.push(player.returnDeck()[i]);
			}
			player.clearDeck();

			for (int i = 0; i < returnDealerDeck().size(); i++) {
				this->discardedCards.push(returnDealerDeck()[i]);
			}
			this->dealerDeck.clear();

			dealCards(player);
		}

		system("CLS");
		hitStandPhase(player);

		do {
			if (returnDealerDeckValue() > 21 && player.returnDeckValue() <= 21) {
				typeText("Dealer: Looks like I lost.\nWant to play again? ", 30);
				getline(cin, choice);
			}
			else if ((returnDealerDeckValue() <= 21 && returnDealerDeckValue() >= player.returnDeckValue()) || player.returnDeckValue() > 21) {
				typeText("Dealer: Looks like I won.\nDealer: Want to play again? ", 30);
				getline(cin, choice);
			}
			if (choice.empty() || choice != "Yes" && choice != "yes" && choice != "No" && choice != "no") {
				typeText("Dealer: Sorry, I did not quite get that.\n", 30);
				Sleep(1500);
				system("CLS");
				choice = "";
			}
		}while (choice.empty() || choice != "Yes" && choice != "yes" && choice != "No" && choice != "no");
	} while (choice == "Yes" || choice == "yes");

	//Check dev blog for next focus

	typeText("Dealer: Uh", 30);
	for (int i = 0; i < 3; i++) {
		cout << ".";
		Sleep(1000);
	}
	typeText("\nDealer: This is all so far.", 30);

}

void Blackjack::hitStandPhase(Player& player) {
	string choice;

	//Loop for player.
	do {
		if (player.returnDeckValue() > 21) {
			player.toggleTurnConcluded();
			typeText("Dealer: You have busted.\n", 30);
			Sleep(1500);
			system("CLS");
		}
		else {
			updateVisuals(player);
			typeText("Dealer: It is your turn. Hit or Stand? ", 30);
			getline(cin, choice);

			if (this->shuffledCards.size() == 0) {
				typeText("Dealer: Seems like there are no more cards to hit. Let's shuffle the discarded cards.\n", 30);
				Sleep(1500);
				shuffleCards(this->discardedCards);
				toggleMidgameShuffle();
			}

			if (choice == "Hit" || choice == "hit") {
				player.appendCard(this->shuffledCards.top());
				this->shuffledCards.pop();
				system("CLS");
				typeText("Dealer: You have received a [" + player.returnCard(player.returnDeck().size() - 1).returnSymbol() + " of " + player.returnCard(player.returnDeck().size() - 1).returnSuit() + "].\n", 30);
				Sleep(1500);
			}
			else if (choice == "Stand" || choice == "stand") {
				system("CLS");
				player.toggleTurnConcluded();
			}
			else if (choice.empty()) {
				typeText("Dealer: You gotta make a choice. Try again.", 30);
				Sleep(1500);
				system("CLS");
			}
			else if (choice != "Hit" && choice != "Stand") {
				typeText("Dealer: Invalid choice. Try again.", 30);
				Sleep(1500);
				system("CLS");
			}
		}
	} while (player.returnTurnConcluded() == false);


	//Loop for dealer.
	do {
		if (returnDealerDeckValue() > 21) {
			toggleTurnConcluded();
			typeText("Dealer: Seems like I busted.\n", 30);
			Sleep(1500);
			system("CLS");
		}
		else {
			updateVisuals(player);
			typeText("Dealer: It is my turn.\n", 30);
			Sleep(1500);

			if (this->shuffledCards.size() == 0) {
				typeText("Dealer: Seems like there are no more cards to hit. Let's shuffle the discarded cards.\n", 30);
				Sleep(1500);
				shuffleCards(this->discardedCards);
				toggleMidgameShuffle();
			}

			if (returnDealerDeckValue() < player.returnDeckValue() && player.returnDeckValue() <= 21) {
				typeText("Dealer: I will hit.\n", 30);
				Sleep(1500);
				appendCard(this->shuffledCards.top());
				this->shuffledCards.pop();
				system("CLS");
				typeText("Dealer: Looks like I received a [" + returnCard(this->dealerDeck.size() - 1).returnSymbol() + " of " + returnCard(this->dealerDeck.size() - 1).returnSuit() + "].\n", 30);
				Sleep(1500);
			}
			else {
				typeText("Dealer: I will stand.\n", 30);
				Sleep(1500);
				toggleTurnConcluded();
			}
		}
	} while (this->turnConcluded == false);

	cout << "No. of cards in shuffledCards: " << this->shuffledCards.size() << '\n';
	Sleep(1500);

	player.toggleTurnConcluded();
	toggleTurnConcluded();
}

//Adds a card onto dealer's deck.
void Blackjack::appendCard(Card card) {
	this->dealerDeck.push_back(card);
}

//A Debugger method. Used to check the dealer's cards and their properties.
void Blackjack::viewDealerDeck() {	
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
	Sleep(1500);
}

// This is an overrided function that will shuffle a given deck.
void Blackjack::shuffleCards(queue<Card> discardedCards) {		// This code work by assuming that shuffledCards is empty as this will only be called when there are no more cards to hit during mid-game.
	vector<Card> temp;
	srand((unsigned)time(NULL));
	int size = discardedCards.size();
	int randomNumber;

	for (int i = 0; i < size; i++) {
		temp.push_back(discardedCards.front());					// Appends the front card of the discardedCards queue onto the temporary vector.
		discardedCards.pop();									// Removes the front card of the discardedCards queue from the queue.
	}

	for (int j = 0; j < size; j++) {
		randomNumber = rand() % (size - j);

		swap(temp[randomNumber], temp[size - (j + 1)]);
	}
	for (int k = 0; k < size; k++) {
		this->shuffledCards.push(temp[k]);
	}
}

//NOTs the turnConcluded value when called.
void Blackjack::toggleTurnConcluded() {
	this->turnConcluded = !(this->turnConcluded);
}

//Deals 2 cards to Player and Dealer in alternating order.
void Blackjack::dealCards(Player& player) {
	for (int i = 0; i < 2; i++) {
		player.appendCard(this->shuffledCards.top());
		this->shuffledCards.pop();
		appendCard(this->shuffledCards.top());
		this->shuffledCards.pop();
	}
}

//NOTs the midgameShuffle value when called.
void Blackjack::toggleMidgameShuffle() {
	this->midgameShuffle = !(this->midgameShuffle);
}

//Returns dealerDeck Attribute.
int Blackjack::returnDealerDeckValue() {
	int value = 0;
	for (int i = 0; i < this->dealerDeck.size(); i++) {
		value = value + this->dealerDeck[i].returnValue();
	}
	return value;
}

//Returns cardDeck Attribute.
vector<Card> Blackjack::returnCardDeck() {
	return this->cardDeck;
}

vector<Card> Blackjack::returnDealerDeck() {
	return this->dealerDeck;
}

//Returns shuffledCards Attribute.
stack<Card> Blackjack::returnShuffledCards() {
	return this->shuffledCards;
}

//Returns discardedCards Attribute.
queue<Card> Blackjack::returnDiscardedCards() {
	return this->discardedCards;
}

//Returns turnConcluded Attribute.
bool Blackjack::returnTurnConcluded() {
	return this->turnConcluded;
}

//Returns Card from deck Attribute specified at index: i.
Card Blackjack::returnCard(int i) {
	return this->dealerDeck[i];
}

//Returns midgameShuffle Attribute.
bool Blackjack::returnMidgameShuffle() {
	return this->midgameShuffle;
}