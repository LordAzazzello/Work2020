#pragma once
#include "ExpressionEvalutor.h"
class Multiplier : public ExpressionEvalutor
{
public:
	double calculate();
	Multiplier();
	Multiplier(size_t n);
};

