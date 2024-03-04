#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <Windows.h>
#include "Solitaire.h"
#include <queue>
#include "Deck.h"
#include "Card.h"
using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

Solitaire::Solitaire(vector<Card> cardDeck) {
	this->cardDeck = cardDeck;
}

void Solitaire::typeText(const string& text, int delayMilliseconds) {
	for (char c : text) {
		cout << c << flush;
		sleep_for(milliseconds(delayMilliseconds));
	}
}

// This will store the shuffled card deck in a local variable, which will be used to update the shuffledDeck attribute.
void Solitaire::shuffleCards() {	
	vector<Card> temp = this->cardDeck;
	int size = temp.size();
	int randomNumber;

	for (int i = 0; i < size; i++) {								// shuffles the cards using fisher yates' algorithm.
		randomNumber = rand() % (size - i);							/* main feature of fisher yates' algorithm. essentially shifts the "new ending index" towards the starting index so the swapped elements
																	at the ending of the list is fixed/untouched*/
		swap(temp[randomNumber], temp[size - (i + 1)]);
	}
	for (int j = 0; j < size; j++) {
		this->shuffledDeck.push_back(temp[j]);
	}
	typeText("Dealer: The cards have been shuffled.\n", 30);
	Sleep(1500);
}

//Displays all of the cards; format: 4 rows, 13 columns.
void Solitaire::displayCards() {
	vector<Card> temp = this->cardDeck;//this->shuffledDeck;							//Only displays, does not change values.
	int size = temp.size();											//No. of cards in shuffledDeck.
	int asciiCardSize = this->cardDeck[0].returnAsciiCard().size();	//No. of lines in ascii card.
	vector<string> asciiStrings;
	string placeHolder;
	int maxRows;													//Max number of rows that have exactly 13 cards.

	// Removes all skip lines for every ascii card except from last.
	for (int i = 0; i < size; i++) {
		if (i == 12 || i == 25 || i == 38 || i == 51) {
			continue;
		}
		if (size != 52) {
			if (i == size - 1) {
				continue;
			}
		}
		else {
			temp[i].eraseLine();
		}
	}

	//Since I am displaying the cards in the format: 4 rows & 13 columns, check if can be split into portions of 13.
	//This will display all of the rows that have 13 cards in it.
	maxRows = size / 13;
	//for the no. of rows up to maxrows.


	for (int i = 0; i < maxRows; i++) {
		for (int j = 0; j < asciiCardSize; j++) {
			for (int k = 0; k < 13; k++) {
				placeHolder = placeHolder + temp[k].returnAsciiLine(j);
			}
			//Appends to string list that contains all of the lines together.
			asciiStrings.push_back(placeHolder);
			//Resets the variable.
			placeHolder = "";
		}
	}


	//for (int i = 0; i < maxRows; i++) {
	//	for (int j = 0; j < asciiCardSize; j++) {
	//		for (int k = 0; k < 13; k++) {
	//			placeHolder = placeHolder + temp[k].returnAsciiLine(j);
	//		}
	//		//Appends to string list that contains all of the lines together.
	//		asciiStrings.push_back(placeHolder);
	//		//Resets the variable.
	//		placeHolder = "";
	//	}
	//}
	//
	////Will display the row that does not have 13 cards.
	//for (int i = (size - ((maxRows * 13) + 1)); i < size; i++) {
	//	for (int j = 0; j < asciiCardSize; j++) {
	//		for (int k = 0; k < (size - (maxRows * 13)); k++) {
	//			placeHolder = placeHolder + temp[k].returnAsciiLine(j);
	//		}
	//		//Appends to string list that contains all of the lines together.
	//		asciiStrings.push_back(placeHolder);
	//		//Resets the variable.
	//		placeHolder = "";
	//	}
	//}
	for (int i = 0; i < asciiStrings.size(); i++) {
		cout << asciiStrings[i];
	}
}

// Solitaire's start method:
void Solitaire::startGame() {
	displayCards();
	/*Should have a function that will display all cards:
	lets do 4 rows, 13 columns
	*/
}
