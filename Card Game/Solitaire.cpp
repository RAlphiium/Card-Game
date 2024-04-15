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
	srand((unsigned)time(NULL));
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

//This function will be used to sort the list in ascending order.
vector<int> Solitaire::bubbleSort(vector<int> list) {
	vector<int> localList = list;
	int size = localList.size();
	bool change = false;
	int temp;

	do {
		change = false;								//If a switch occurs within an iteration of a while loop, change will be set to true - indicating that the bubble sort requires another iteration.
		for (int i = 0; i < size - 1; i++) {
			if (localList[i] > localList[i + 1]) {
				change = true;
				temp = localList[i + 1];
				localList[i + 1] = localList[i];
				localList[i] = temp;
			}
		}
	} while (change == true);						//Loops until a change does not occur for a while while iteration

	return localList;								//returns sorted vector.
}

//Displays all of the cards; format: 4 rows, 13 columns.
void Solitaire::displayCards() {
	vector<Card> temp = this->shuffledDeck;					//Only displays, does not change values.
	int size = temp.size();														//No. of cards in shuffledDeck.
	int asciiCardSize = this->cardDeck[0].returnAsciiCard().size();				//No. of lines in ascii card (14)
	vector<string> asciiStrings;
	string placeHolder;

	int checker = 1;
	int columns = this->columns;
	int maxRows = size / columns;												//Max number of rows that have exactly 13 cards.
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

	//Will display all rows of max columns.
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

	//if this->shuffledDeck.size() < 13, will not display cards.
	if ((maxRows*columns) != 52 || size < 13) {													//If total cards != 52 or incomplete rows (case where 52 is not divisible by columns value), must be rearranged.
		if (size < 13) {
			next = 0;
		}
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

	if (this->discardedCards.size() > 0) {											//Checks if there are any cards in the discarded stack.
		string borderLine = " ";													//If there are cards in the discarded stack, creates a border between non-discarded cards and discarded cards. Length of border is determined by no. columns.
		for (int i = 0; i < this->columns-1; i++) {
			borderLine = borderLine + "=====================" + "==";				
		}
		borderLine = borderLine + "=====================";

		cout << '\n' << borderLine << '\n' << " Discarded Stack: (" << this->discardedCards.size() << ")\n";
		this->discardedCards.top().displayCard();
		cout << '\n';
	}
}
//This function will be used to check if the selected cards meet the conditions: selected 2 consecutive cards & total cards = 10,20 or 30.
vector<int> Solitaire::checkCards(string previousSelect) {
	string select = previousSelect;
	string number;
	vector<int> cardIndexs = {};
	vector<int> temp = {};																		//Vector list to copy CardIndexs content to sort.
	bool invalid = false;
	int total = 0;
	//First, separate the numbers from the commas and/or strings.
	//Second, convert the numbers into integers, subtract 1 from each number inputted to find index number, and store in the vector list.
	//third, sort the numbers in ascending order.
	//check if the list contains at least 2 numbers
	//check if the total is equal to 10,20 or 30.

	//This will collect all strings numbers, convert into integers and subtract 1 from the collected integers to find index numbers.
	do {
		if (select[0] == ' ' || select[0] == ',') {
			select.erase(select.begin());														//Removes the character from the string.
			if (stoi(number) - 1 < 0 || stoi(number) - 1 > this->shuffledDeck.size()-1) {
				invalid = true;
			}
			else {
				cardIndexs.push_back(stoi(number) - 1);											//String number is converted into integer number and is pushed onto the vector list.
				number = "";																	//variable is reset for the next number.
			}
		}
		else {
			number = number + select[0];														//Concatenates current character onto the string variable.
			select.erase(select.begin());														//Removes the character from the select string variable.
			if (select.size() == 0) {															//There isn't a moment for the last index to be pushed onto the vector; this is a insurance.
				if (stoi(number) - 1 < 0 || stoi(number) - 1 > this->shuffledDeck.size()-1) {	//Checks if the number is an appropiate index (accepts value if it is greater than 0 and lesser than or equal to max cards)
					invalid = true;
				}
				else {
					cardIndexs.push_back(stoi(number) - 1);
				}
			}
		}
	} while (select.size() != 0);																//Will repeat until there are no more characters in this string variable.

	//NEXT: sort the numbers in ascending order and check if there are any duplicate indexs.
	if (invalid != true) {
		if (cardIndexs.size() < 2) {															//Checks if at least 2 cards have been selected.
			invalid = true;
		}
		temp = bubbleSort(cardIndexs);															//Takes the vector cardIndexs and bubble sorts the values in ascending order.
		for (int i = 0; i < temp.size() - 1; i++) {												//Checks if the selected cards are adjacent to each other.
			if (abs(temp[i] - temp[i + 1]) != 1) {												//Works by subtracting the indexs from one another in their sorted arrangement. If they are sorted, the result should always be equal to 1.
				cout << "not consecutive" << "\n";
				invalid = true;
			}
		}
		for (int j = 0; j < temp.size() - 1; j++) {												//Checks if any duplicate indexs have been inputted.
			if (temp[j] == temp[j + 1]) {														//Since the list is sorted, any potential duplicates should be adjacent to one another.
				cout << "duplicate found" << "\n";
				invalid = true;
			}
		}
		for (int k = 0; k < cardIndexs.size(); k++) {											//Finds the total of all selected cards.
			total = total + this->shuffledDeck[cardIndexs[k]].returnValue();
		}	
		if (total != 10 && total != 20 && total != 30) {										//Checks if total is equal to 10,20 or 30.
			cout << "invalid total" << "\n";
			invalid = true;
		}
	}

	//debugger
	//cout << "Indexs selected: ";
	//for (int i = 0; i < cardIndexs.size(); i++) {
	//	cout << cardIndexs[i] << " ";
	//}
	//cout << '\n';
	//cout << "Numbers selected: ";
	//for (int i = 0; i < cardIndexs.size(); i++) {
	//	cout << this->shuffledDeck[cardIndexs[i]].returnSymbol() << " ";
	//}
	//cout << "\ntotal = " << total << '\n';


	if (invalid == true) {
		typeText("An invalid input has been entered. Try again.", 30);
		Sleep(3000);
		system("CLS");
		displayCards();
	}
	else {
		return cardIndexs;
	}
	return { 0 };
}

void Solitaire::selectCards() {
	string select;
	int min, max;
	vector<int> indexs;
	
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
		typeText("Type:\n\n > 'Refresh' to provide the time to resize the terminal and to reload the visuals.\n > 'Rules' to display a textual guide for Solitaire: Decade.\n",15);
		typeText(" > '1-" + to_string(this->shuffledDeck.size()) + "' to select a card and place ',' or ' ' in between your cards' ordinal number to select more.\n\nType here: ", 15);
		getline(cin, select);

		if (select == "refresh" || select == "Refresh") {								//Typing these accepted values will redisplay the card visuals to the player again.
			typeText("Refreshing", 30);
			for (int i = 0; i < 3; i++) {
				cout << ".";
				Sleep(1000);
			}
			system("CLS");
			displayCards();
		}
		else if (select == "rules" || select == "Rules") {
			typeText("\nSolitaire: Decade is a type of Solitaire game that uses a single set of standard Playing Cards.\nThe single set of standard Playing Cards are randomly shuffled and distributed in a sequence which places the cards from left to right and top to bottom.\nThese cards will be faced up when placed down.\nYou, as the Player, must discard all 52 cards to win.", 30);
			typeText("\n\nPress enter to continue.", 30);
			getline(cin, select);
			cout << select.size();
			if (select.size() == 0) {
				system("CLS");
				displayCards();
				continue;
			}
		}
		else if (select == "") {
			system("CLS");
			displayCards();
			continue;
		}
		else {
			indexs = checkCards(select);																		//Summary: Stores inputted values into indexs if valid. If invalid, will only store {0}
			if (indexs[0] == 0 && indexs.size() == 1) {															//Necessary checker if checkCards somehow returns only {0}. Will happen if inputted values were deemed invalid.
				indexs.erase(indexs.begin());																	//Resets the variable indexs.
				cout << "Check2";																				//Debug
				Sleep(1500);
			}
			else {
				min = *min_element(indexs.begin(), indexs.end());												//Finds the smallest index in the unsorted vector.
				max = *max_element(indexs.begin(), indexs.end());												//Finds the largest index in the unsorted vector.
				for (int i = 0; i < indexs.size(); i++) {														//Debug
					cout << indexs[i] << " ";
				}

				discardCards(indexs);																			//Appends the about-to-be-erased cards to the discarded stack: discardedCards
				this->shuffledDeck.erase(this->shuffledDeck.begin()+min, this->shuffledDeck.begin()+max+1);
				cout << "Check1";																				//Debug
				Sleep(1500);
			}
			cout << "\nShuffledDeck: " << this->shuffledDeck.size();											//Debug
			Sleep(1500);
			system("CLS");
			displayCards();

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

void Solitaire::discardCards(vector<int> indexs) {																	//Last element in the vector will be the top of the stack.
	for (int i = 0; i < indexs.size(); i++) {																		//Appends the about-to-be-erased cards to the discarded stack: discardedCards
		this->discardedCards.push(this->shuffledDeck[indexs[i]]);		
	}
}

//Returns cardDeck attribute.
vector<Card> Solitaire::returnCardDeck() {
	return this->cardDeck;
}

//Returns shuffledDeck attribute.
vector<Card> Solitaire::returnShuffledDeck() {
	return this->shuffledDeck;
}

//Returns discardedCards attribute.
stack<Card> Solitaire::returnDiscardedCards() {
	return this->discardedCards;
}

//Returns columns attribute.
int Solitaire::returnColumns() {
	return this->columns;
}