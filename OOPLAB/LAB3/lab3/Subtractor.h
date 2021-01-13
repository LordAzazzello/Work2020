#pragma once
#include "ExpressionEvalutor.h"
class IShuffle
{
public:
	virtual void shuffle() =0;
	virtual void shuffle(size_t i, size_t j) =0;
};

class Subtractor : public IShuffle, public ExpressionEvalutor
{
public:
	double calculate();
	Subtractor();
	Subtractor(size_t n);
	~Subtractor() { std::cout << "destr Sub";delete[] operand; };
	void shuffle();
	void shuffle(size_t i, size_t j);
};

