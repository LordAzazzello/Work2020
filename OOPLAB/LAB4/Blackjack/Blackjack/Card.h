#pragma once
enum CardSuit { clubs, diamonds, hearts, spades };

class Card
{
public:
	friend void printCard(Card &);
	
	int getPoints();
	void setHole(bool);

	Card(int n, CardSuit s);
private:
	CardSuit Suit;
	int Rank;
	int Points;
	bool Hole = false;
};

