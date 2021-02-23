#include <iostream>
#include "Game.h"
using namespace std;

#define DEALER_LIM 17

Game::Game(Player p, Dealer d)
{
	Pl = p;	// Pl.push_back(p);
	Deal = d;

	for (int i = 0; i < 4; i++)
	{
		Shoe[i] = Deck();
	}
}

double Game::getBet()
{
	return Bet;
}

void Game::setBet(double bet)
{
	Bet = bet;
}

/*
bool Game::getSplit()
{
	return Split;
}


void Game::setSplit(bool split)
{
	Split = split;
}

std::vector<Player> Game::getPl()
{
	return Pl;
}
*/
Dealer Game::getDeal()
{
	return Deal;
}

void Game::begin()
{
	addCard(dealer);	// , Deal);
	addCard(dealer);	// , Deal);
	addCard(player);	// , Pl[0]);
	addCard(player);	// , Pl[0]);

//	if (checkSplit())
//	{
//		printAll(Pl[0]);
//		int printed = dialog();
//		if (printed == 3)
//		{
//			Player p;
//			Pl.push_back(p);
//			Pl[1].addCard(Pl[0].getSplitCard());
//		}
//		else	
//			setSplit(false);
//	}
}

/*
bool Game::checkSplit()
{
	if (Pl[0].checkSplit())
	{
		setSplit(true);
		return true;
	}
	else
		return false;
}
*/

bool Game::addCard(Unit unit)	//, Player pl)
{
	bool res;
	Card checked = Shoe[rand() % 4].getCard();

	switch (unit)
	{
	case dealer:
		res = Deal.addCard(checked);
		break;
	case player:
		res = Pl.addCard(checked);
		break;
	};

	return res;
}

void Game::printAll()	// (Player pl)
{
	cout << '\n';
	cout << "Колоды:	";

	for (Deck d : Shoe)
	{
		cout << "[" << d.getLength() << "]";
	};

	cout << '\n';
	cout << "Дилер:	";
	Deal.printCards();

	cout << '\n';
	cout << "Игрок:	";
	Pl.printCards();
}

int Game::dialog()
{
	cout << '\n' << '\n';
	cout << "1. Хватит" << "\n" << "2. Еще" << "\n";

	if (false)	//(getSplit())
	{
		cout << "3. Сплит" << "\n";
		return checkPrint(3);
	}
	else
		return checkPrint(2);
}

int Game::menu()
{
	cout << '\n' << '\n';
	cout << "1. Начать заново" << '\n';
	cout << "2. Закрыть" << '\n';

	return checkPrint(2);
}

bool Game::isBlackjack()
{
	if (Pl.getPoints() == 21)
	{
		printAll();
		cout << "\n" << "Это блекджек!" << "\n";
		if (Deal.firstCard() == 1)
		{
			int answr;
			cout << "1. Забрать выигрыш 1:1" << "\n";
			cout << "2. Открыть вторую карту дилера" << "\n";
			
			answr = checkPrint(2);
			if (answr == 1)
				endGame(win);
			else
			{
				Deal.setHole(false);
				if (Deal.getPoints() == 21)
					endGame(push);
				else
					endGame(blackjack);
			}
		}
		else
			endGame(blackjack);

		return true;
	}
	else
		return false;
}

void Game::endGame(End end)
{
/*	auto i = Pl.begin() + 1;
	while (i <= Pl.end())
	{
		Pl.erase(i);
		i++;
	}
	Pl[0].cleanCards();
*/
	Pl.cleanCards();
	Deal.cleanCards();

	cout << "\n" << "\n";

	switch (end)
	{
	case push:
		cout << "Поздравляем! Это ничья!" << "\n";
		break;
	case win:
		Pl.setProfit(Pl.getProfit() + Bet);
		cout << "Поздравляем! Вы выиграли! Ваш выигрыш: " << Bet << "." << "\n";
		break;
	case loose:
		Deal.setProfit(Deal.getProfit() + Bet);
		cout << "Поздравляем! Вы проиграли! Ваш проигрыш: " << Bet << "." << "\n";
		break;
	case blackjack:
		Pl.setProfit(Pl.getProfit() + Bet*1.5);
		cout << "Поздравляем! Вы выиграли! Ваш выигрыш: " << Bet*1.5 << "." << "\n";
		break;
	};

	cout << "\n" << "Общий счет: " << "\n";
	cout << "Игрок: " << Pl.getProfit() << ". Дилер: " << Deal.getProfit() << ".";
}

void Game::cmprPoints()	//(Player p)
{
	if (Pl.getPoints() == Deal.getPoints())
		endGame(push);
	if (Pl.getPoints() > Deal.getPoints())
		endGame(win);
	else
		endGame(loose);
}

void Game::cleanStats()
{
	Pl.setProfit(0);
	Deal.setProfit(0);
}

int Game::checkPrint(int var)
{
	int printed;

	for (;;)
	{
		cin >> printed;
		if (printed >= 1 && printed <= var)
		{
			break;
		}
		else
		{
			cout << "Попробуйте еще раз" << "\n";
		}
	}

	return printed;
}