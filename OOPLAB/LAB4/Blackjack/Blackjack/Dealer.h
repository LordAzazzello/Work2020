#pragma once
#include <vector>
#include "Card.h"
#include "Player.h"
class Dealer: public Player
{
public:
	bool addCard(Card c);
	int firstCard();
	void printCards();
	void setHole(bool);

	Dealer();
private:
	std::vector<Card> Cards;
	int Points = 0;
	double Profit = 0;
	int Limit = 17;
	bool atSplit;
};

