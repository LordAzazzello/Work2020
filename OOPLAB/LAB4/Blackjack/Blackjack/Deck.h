#pragma once
#include <vector>
#include "Card.h"
class Deck
{
public:
	Deck();

	Card getCard();
	int getLength();

	std::string const printDeck();
private:
	std::vector<Card> Cards;
};

