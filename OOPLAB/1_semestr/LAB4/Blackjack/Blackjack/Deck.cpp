#include <stdlib.h>
#include "Deck.h"

#define DECK_NUM 52
#define SUIT_NUM 13


Card Deck::getCard()
{
	int check = (rand() % DECK_NUM);
	Card checked = Cards.at(check);

	Cards.erase(Cards.begin() + check);

	return checked;
}

int Deck::getLength()
{
	return Cards.size();
}

Deck::Deck()
{
	for (int j = 0; j < DECK_NUM; j++)
	{
		int num = (j % SUIT_NUM) + 1;
		CardSuit su = CardSuit(j / SUIT_NUM);
		Cards.push_back(Card(num, su));
	}
}

std::string const Deck::printDeck()
{
	std::string str = "";
	for (Card card : Cards)
	{
		str = str + static_cast<char>(card.getPoints()) + " ";
	}
	return str;
}