#pragma once
#include <iostream>
#include <string>
#include "Deck.h"

class IFormattable
{
public:
	virtual std::string format()
	{
		return "Interface";
	}
};

void prettyPrint(IFormattable* object)
{
	std::cout << object -> format();
}

class Adapter : public IFormattable
{
private:
	Deck *deck_;

public:
	Adapter(Deck* deck) : deck_(deck) {}
	std::string format() override {
		std::string to_print = this->deck_->printDeck();
		std::reverse(to_print.begin(), to_print.end());
		return "Adapter: (TRANSLATED) " + to_print;
	}
};