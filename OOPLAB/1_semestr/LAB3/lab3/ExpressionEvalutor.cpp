#include <iostream>
#include <fstream>
#include "ExpressionEvalutor.h"
ExpressionEvalutor::ExpressionEvalutor() {
	operand = new double[20];
	num_op = 20;

	for (int i = 0;i < 20;i++)
		operand[i] = 0;
}

ExpressionEvalutor::ExpressionEvalutor(int n) {
	operand = new double[n];
	num_op = n;

	for (int i = 0;i < n;i++)
		operand[i] = 0;
}

/*
ExpressionEvalutor::~ExpressionEvalutor() {
	std::cout << "Base destroyed\n,";
	delete[] operand;
}
*/
void ExpressionEvalutor::logToScreen() {
	//coutOldBuf = std::cout.rdbuf();
}

void ExpressionEvalutor::logToFile(const std::string& filename) {
	std::ofstream out(filename);
}

void ExpressionEvalutor::setOperand(size_t pos, double value) {
	operand[pos] = value;
}

void ExpressionEvalutor::setOperands(double ops[], size_t n) {
	for (size_t i=0;i < n;i++) {
		operand[i] = ops[i];
	}
}