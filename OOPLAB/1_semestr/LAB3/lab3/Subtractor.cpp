#include "Subtractor.h"

Subtractor::Subtractor():ExpressionEvalutor() {
}

Subtractor::Subtractor(size_t n) : ExpressionEvalutor(n) {
}


double Subtractor::calculate() {
	double res = NULL;

	std::cout << "[" << num_op << "]" << std::endl;

	for (size_t i = 0;i < num_op;i++) {
		if (!res)
			res = operand[i];

		if (operand[i] < 0)
			std::cout << "(" << operand[i] << ")";
		else
			std::cout << operand[i];
		if (i < num_op - 1)
			std::cout << " - ";
		else
			std::cout << std::endl;
		
		if (!res)
			res = operand[i];
		else
			res = res - operand[i];
	}
	std::cout <<"Result: " << res << std::endl << std::endl;
	return 0;
}

void Subtractor::shuffle() {
	double tmp;

	std::cout << "shuffle for Subtractor:" << std::endl;
	std::cout << "[" << num_op << "]" << std::endl;

	tmp = 0 - operand[0];
	operand[0] = 0 - operand[num_op - 1];
	operand[num_op - 1] = tmp;

	for (size_t k = 0;k < num_op;k++)
		std::cout << operand[k] << " ";

	std::cout << std::endl << std::endl;
}

void Subtractor::shuffle(size_t i, size_t j) {
	double tmp;

	std::cout << "shuffle for Subtractor: i=" << i << " , j=" << j << std::endl;
	std::cout << "[" << num_op << "]" << std::endl;

	if (i > 0 and j > 0) {
		tmp = 0 - operand[i - 1];
		operand[i - 1] = 0 - operand[j - 1];
		operand[j - 1] = tmp;
	}

	for (size_t k = 0;k < num_op;k++)
		std::cout << operand[k] << " ";

	std::cout << std::endl << std::endl;

}