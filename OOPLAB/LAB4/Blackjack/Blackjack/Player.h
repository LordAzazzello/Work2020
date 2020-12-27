#pragma once
#include <vector>
#include "Card.h"

class Player
{
public:
	Player();

	double getProfit();
	void setProfit(double);
	int getPoints();
	bool addCard(Card);
//	bool checkSplit();
	void printCards();
	void cleanCards();
//	Card getSplitCard();
private:
	std::vector<Card> Cards;
	int Points = 0;
	double Profit = 0;
};

