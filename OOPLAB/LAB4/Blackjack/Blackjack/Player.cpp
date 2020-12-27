#include <iostream>
#include <vector>
#include "Player.h"

Player::Player()
{
}


int Player::getPoints()
{
	return Points;
}

/*
Card Player::getSplitCard()
{
	Card c = Cards[Cards.size() - 1];
	Cards.erase(Cards.end() - 1);
	return c;
}
*/

 bool Player::addCard(Card c)
{
	Cards.push_back(c);
	int currPoints = c.getPoints();

	if (currPoints == 1 && Points + c.getPoints() <= 21)
		Points += 11;
	else
		Points += c.getPoints();

	for (Card card: Cards)
	{
		if (card.getPoints() == 1 && Points > 21)
			Points -= 10;
	}

	try
	{
		if (Points > 21)
			throw Points;
	}

	catch (int)
	{
		return false;
	}
	return true;
}

void Player::printCards()
{
	for (Card c : Cards)
	{
		printCard(c);
	};
}

void Player::cleanCards()
{
	Cards.clear();
	Points = 0;
}

void Player::setProfit(double dbl)
{
	Profit = dbl;
}

double Player::getProfit()
{
	return Profit;
}

/*
bool Player::checkSplit()
{
	if (Cards[0].getPoints() == Cards[1].getPoints())
		return true;
	else
		return false;
}
*/