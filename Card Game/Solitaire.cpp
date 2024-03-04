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
	vector<Card> temp = this->cardDeck;//this->shuffledDeck;					//Only displays, does not change values.
	int size = temp.size();											//No. of cards in shuffledDeck.
	int asciiCardSize = this->cardDeck[0].returnAsciiCard().size();	//No. of lines in ascii card (14)
	vector<string> asciiStrings;
	string placeHolder;

	int maxRows = size / 13;													//Max number of rows that have exactly 13 cards.
	int columns = 13;
	int previous = 0;
	int next = 13;

	// Removes all skip lines for every ascii card except from last.
	for (int i = 0; i < size; i++) {
		if (i == 12 || i == 25 || i == 38 || i == 51) {
			continue;
		}
		else {
			temp[i].eraseLine();
		}
	}

	//Since I am displaying the cards in the format: 4 rows & 13 columns, check if can be split into portions of 13.
	//This will display all of the rows that have 13 cards in it.
	for (int i = 0; i < maxRows; i++) {												//for the no. of rows up to maxrows.
		next = columns * (i + 1);													//moves to the next 13 cards
		//cout << "previous/next: " << previous << "/" << next << '\n';				//Debugger
		for (int j = 0; j < asciiCardSize; j++) {
			for (int k = previous; k < next; k++) {
				placeHolder = placeHolder + temp[k].returnAsciiLine(j);				//concatenates the all of the lines at line j for all of the cards k
			}
			//Appends to string list that contains all of the lines together.
			asciiStrings.push_back(placeHolder);
			//Resets the variable.
			placeHolder = "";														
		}
		previous = next;															//starting index becomes previous next.
	}

	if (size < 52) {																//If total cards != 52, must be rearranged.
		for (int i = 0; i < asciiCardSize; i++) {									
			for (int j = next; j < size; j++) {										//next = highest possible row of 13 cards size = total number of cards.
				placeHolder = placeHolder + temp[j].returnAsciiLine(i);				//concatenates the all of the lines at line j for all of the cards k
				if (j == size - 1) {												//Adds a new line (\n) at every ascii string of the last card of the deck.
					placeHolder = placeHolder + "\n";								//Concatenates "\n" to the last card's ascii strings.
				}
			}
			//Appends to string list that contains all of the lines together.
			asciiStrings.push_back(placeHolder);
			//Resets the variable.
			placeHolder = "";
		}
	}

	for (int i = 0; i < asciiStrings.size(); i++) {
		cout << asciiStrings[i];
	}
}

// Solitaire's start method:
void Solitaire::startGame() {
	typeText("Please zoom out in order to view all of the cards that will be displayed to you shortly.", 30);
	Sleep(3000);
	system("CLS");
	displayCards();
	/*Should have a function that will display all cards:
	lets do 4 rows, 13 columns
	*/
}
