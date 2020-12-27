#include <iostream>
#include "Dealer.h"

Dealer::Dealer()
{
}

bool Dealer::addCard(Card c)
{
	if (Points >= Limit)
	{
		setHole(false);
		return false;
	}
	else
	{
		Cards.push_back(c);
		int currPoints = c.getPoints();

		if (currPoints == 1 && Points + c.getPoints() <= 21)
			Points += 11;
		else
			Points += c.getPoints();

		for (Card card : Cards)
		{
			if (card.getPoints() == 1 && Points > 21)
				Points -= 10;
		}

		if (Cards.size() == 2)
			setHole(true);
		if (Cards.size() == 3)
			setHole(false);

		return true;
	}

//	if (Points >= Limit)
//		return false;
//	else
//		return true;
}

void Dealer::printCards()
{
	for (Card c : Cards)
	{
		printCard(c);
	};
}

int Dealer::firstCard()
{
	return Cards[0].getPoints();
}

void Dealer::setHole(bool hole)
{
	Cards[1].setHole(hole);
}