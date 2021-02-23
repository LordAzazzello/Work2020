#pragma once
#include "Dealer.h"
#include "Player.h"
#include "Deck.h"

enum Unit { dealer, player };
enum End { push, win, loose, blackjack };

class Game
{
public:
	Game(Player, Dealer);

	double getBet();
	void setBet(double);
//	bool getSplit();
//	void setSplit(bool);
//	std::vector<Player> getPl();
	Dealer getDeal();

	bool addCard(Unit);	// , Player);
	bool isBlackjack();
//	bool checkSplit();
	void cmprPoints();		//(Player);
	void endGame(End);
	int dialog();
	int menu();
	int checkPrint(int);
	void printAll();	//(Player);
	void cleanStats();
	void begin();
private:
	Dealer Deal;
	Player Pl;		//std::vector<Player> Pl;
	Deck Shoe[4];
	double Bet;
	bool Split;
};

