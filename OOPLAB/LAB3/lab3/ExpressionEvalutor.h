#pragma once
#include <iostream>
#include <fstream>
class ILogable
{
public:
	virtual void logToScreen()=0;
	virtual void logToFile(const std::string& filename)=0;
};


class ExpressionEvalutor : public ILogable
{
public:
	double* operand;
	size_t num_op = 0;
	void logToScreen() override;
	void logToFile(const std::string& filename) override;
	void setOperand(size_t pos, double value);
	void setOperands(double ops[], size_t n);
	ExpressionEvalutor();
	ExpressionEvalutor(int);
	virtual double calculate()=0;
};





