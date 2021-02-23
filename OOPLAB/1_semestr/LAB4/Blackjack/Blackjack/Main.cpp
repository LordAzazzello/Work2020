#include <iostream>
#include "Adapter.h"
#include "Card.h"
#include "Deck.h"
#include "Game.h"
#include "Player.h"
#include "Dealer.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	cout << '\n' << '\n';
	cout << "Адаптер!" << '\n' << '\n';

	Deck* deck = new Deck();
	Adapter *adapter = new Adapter(deck);

	cout << deck->printDeck() << '\n' << '\n';
	prettyPrint(adapter);
	

	double printed;

	Player plr;
	Dealer dlr;

		for (;;)
		{
			Game NewGame = Game(plr, dlr);

			cout << '\n' << '\n';
			cout << "Ваша ставка?" << '\n';
			cin >> printed;

			NewGame.setBet(printed);
			NewGame.begin();

			if (NewGame.isBlackjack())
				continue;

//			for (Player p : NewGame.getPl())
//			{
				for (;;)
				{
					NewGame.printAll();	// p);
					printed = NewGame.dialog();

					if (printed == 1)
					{
						bool res = true;
						while (res)
						{
							res = NewGame.addCard(dealer);	//, NewGame.getDeal());
							if (res)
								continue;
							else
							{
								NewGame.printAll();	// p);
								NewGame.cmprPoints();	// p);
								break;
							}
						}
						break;
					}
					if (printed == 2)
					{
						bool res = NewGame.addCard(player);	// , p);
						if (res)
							continue;
						else
						{
							NewGame.printAll();	// p);
							NewGame.endGame(loose);
							break;
						}
					}
					if (printed == 3)
					{
						//NewGame.toSplit();
					}
				}
//			}

		printed = NewGame.menu();
		if (printed == 1)
		{
			NewGame.cleanStats();
		}
		if (printed == 2)
			break;
	}
}
