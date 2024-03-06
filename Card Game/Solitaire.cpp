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

	int checker = 1;
	int columns = this->columns;
	int maxRows = size / columns;													//Max number of rows that have exactly 13 cards.
	int previous = 0;
	int next = 13;

	// Removes all skip lines for every ascii card except from last. (only applies to if each row had 13 cards.
	for (int i = 0; i < size; i++) {
		if (i == (columns*checker)-1) {		//For every columns'ths, subtract 1 to find index value and skip the removal of skip lines in its ascii strings by using continue
			checker = checker + 1;
			continue;
		}
		else {
			temp[i].eraseLine();
		}
	}

	//// Removes all skip lines for every ascii card except from last. (only applies to if each row had 13 cards.
	//for (int i = 0; i < size; i++) {
	//	if (i == 12 || i == 25 || i == 38 || i == 51) {
	//		continue;
	//	}
	//	else {
	//		temp[i].eraseLine();
	//	}
	//}

	//Since I am displaying the cards in the format: 4 rows & 13 columns, check if can be split into portions of 13.
	//This will display all of the rows that have 13 cards in it.
	for (int i = 0; i < maxRows; i++) {												//for the no. of rows up to maxrows.
		next = columns * (i + 1);													//moves to the next 13 cards
		//cout << "previous/next: " << previous << "/" << next << '\n';				//Debugger
		for (int j = 0; j < asciiCardSize; j++) {									//considers all of the ascii lines (element 0 -> element 14)
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

	if ((maxRows*columns) != 52) {													//If total cards != 52 or incomplete rows (case where 52 is not divisible by columns value), must be rearranged.
		for (int i = 0; i < asciiCardSize; i++) {									
			for (int j = next; j < size; j++) {										//next = highest possible row of 13 cards size = total number of cards.
				placeHolder = placeHolder + temp[j].returnAsciiLine(i);				//concatenates all of the lines at line i for all of the cards j
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
//This function will be used to check if the selected cards meet the conditions: selected 2 consecutive cards & total cards = 10,20 or 30.
void Solitaire::checkCards(string previousSelect) {
	string select = previousSelect;
	string number;
	vector<int> cardIndexs = {};
	bool invalid = false;
	//First, separate the numbers from the commas and/or strings.
	//Second, convert the numbers into integers, subtract 1 from each number inputted to find index number, and store in the vector list.
	//third, sort the numbers in ascending order.
	//check if the list contains at least 2 numbers
	//check if the total is equal to 10,20 or 30.

	//This will collect all strings numbers, convert into integers and subtract 1 from the collected integers to find index numbers.
	do {
		if (select[0] == ' ' || select[0] == ',') {
			select.erase(select.begin());								//Removes the character from the string.
			if (stoi(number) - 1 < 0 || stoi(number) - 1 > this->shuffledDeck.size()-1) {
				invalid = true;
			}
			else {
				cardIndexs.push_back(stoi(number) - 1);					//String number is converted into integer number and is pushed onto the vector list.
				number = "";											//variable is reset for the next number.
			}
		}
		else {
			number = number + select[0];								//Concatenates current character onto the string variable.
			select.erase(select.begin());								//Removes the character from the select string variable.
			if (select.size() == 0) {									//There isn't a moment for the last index to be pushed onto the vector; this is a insurance.
				if (stoi(number) - 1 < 0 || stoi(number) - 1 > this->shuffledDeck.size()-1) {	//Checks if the number is an appropiate index.
					invalid = true;
				}
				else {
					cardIndexs.push_back(stoi(number) - 1);
				}
			}
		}
	} while (select.size() != 0);								//Will repeat until there are no more characters in this string variable.

	//NEXT: sort the numbers in ascending order and check if there are any duplicate indexs.

	if (invalid == true) {
		typeText("An invalid input has been entered. Try again.", 30);
		Sleep(3000);
		system("CLS");
		displayCards();
	}
	else {
		for (int i = 0; i < cardIndexs.size(); i++) {
			cout << cardIndexs[i] << '\n';
			Sleep(3000);
		}
	}
}

void Solitaire::selectCards() {
	string select;
	typeText("All 52 cards are placed in a sequence from left to right and top to bottom.\n", 30);
	
	/*Conditions for successful select:
		- At least 2 consecutive cards have been selected.
		- Total sum of selected cards must be equal to 10, 20 or 30.
	Might want to create a function that will take in whatever selections the player had made to check if the values meet these conditions.

	- How to do this:
		- create new function:
		- use a for loop in function that will separate values using commas as dividers.
		- store separated string values in a variable and convert it back to an integer using stoi() [will be done iteratively for each loop].
		- subtract 1 from the integer variable to find the intended card using its index number.
		- store in a vector

		- vector could be sorted using bubble sort (this can be used to check if the selected indexs are consecutive).
		- after stored in vector, can take indexs, find the selected cards and find the total sum to check if the total is equal to 10, 20 or 30.
	*/

	do {
		cout << "Type 'Refresh' to take the time to resize the terminal and to reload the visuals.\n";
		typeText("Type 1-" + to_string(this->shuffledDeck.size()) + " to select a card and place ',' in between your card numbers to select more: ", 30);
		getline(cin, select);

		if (select == "refresh" || select == "Refresh") {
			typeText("Refreshing", 30);
			for (int i = 0; i < 3; i++) {
				cout << ".";
				Sleep(1000);
			}
			system("CLS");
			displayCards();
		}
		else {
			checkCards(select);
		}
	} while (this->shuffledDeck.size() != 0);
}
// Solitaire's start method:
void Solitaire::startGame() {
	do {
		typeText("How many columns do you want to display for each row? ", 30);
		cin >> this->columns;
		if(this->columns <= 0){
			typeText("Invalid input.",30);
			Sleep(3000);
			system("CLS");
		}
	} while (this->columns <= 0);
	cin.ignore();

	typeText("Please zoom out in order to view all of the cards that will be displayed to you shortly.\n", 30);
	typeText("Zoom in = Ctrl + ScrollUp, Zoom out = Ctrl + ScrollDown",30);
	Sleep(3000);
	system("CLS");

	shuffleCards();
	do {
		displayCards();
		selectCards();
	} while (this->shuffledDeck.size() != 0);
}
