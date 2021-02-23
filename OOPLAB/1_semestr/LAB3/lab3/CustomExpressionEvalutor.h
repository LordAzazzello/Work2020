#pragma once
#include "ExpressionEvalutor.h"
class CustomExpressionEvalutor:public ExpressionEvalutor
{
public:
	double calculate();
	CustomExpressionEvalutor();
	CustomExpressionEvalutor(size_t n);
};

