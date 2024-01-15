#include <string>
#include <vector>
#include "Player.h"
#include "Card.h"
using namespace std;

Player::Player() {
	this->deck = {};
}

vector<Card> Player::returnDeck() {
	return this->deck;
}