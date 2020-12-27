#include <iostream>
#include "Card.h"
using namespace std;

const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 1;

Card::Card(int n, CardSuit s)
{
	Suit = s; Rank = n;

	if (n >= 1 && n <= 10)
		Points = n;
	else
		Points = 10;
}

int Card::getPoints()
{
	return Points;
}

void printCard(Card & card)
{
	cout << " | ";

	if (card.Hole)
		cout << "??";
	else
	{
		if (card.Rank >= 2 && card.Rank <= 10)
			cout << card.Rank;
		else
		{
			switch (card.Rank)
			{
			case jack: cout << 'J'; break;
			case queen: cout << 'Q'; break;
			case king: cout << 'K'; break;
			case ace: cout << 'A'; break;
			}
		}
		switch (card.Suit)
		{
		case clubs: cout << static_cast<char>(5); break;
		case diamonds: cout << static_cast<char>(4); break;
		case hearts: cout << static_cast<char>(3); break;
		case spades: cout << static_cast<char>(6); break;
		}
	}

	cout << " |";
}

void Card::setHole(bool hole)
{
	Hole = hole;
}