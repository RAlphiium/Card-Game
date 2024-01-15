#pragma once
#include <string>
#include <vector>
#include "Card.h"

class Player {
private:
	vector<Card> deck;
public:
	Player();

	vector<Card> returnDeck();
};
