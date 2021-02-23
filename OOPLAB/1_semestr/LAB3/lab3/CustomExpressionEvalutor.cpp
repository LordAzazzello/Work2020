#include "CustomExpressionEvalutor.h"
CustomExpressionEvalutor::CustomExpressionEvalutor() :ExpressionEvalutor() {
}

CustomExpressionEvalutor::CustomExpressionEvalutor(size_t n) : ExpressionEvalutor(n) {
}
double CustomExpressionEvalutor::calculate() {
	double res = 1;

	std::cout << "[" << num_op << "]" << std::endl;

	for (size_t i = 0;i < num_op;i++) {
		if (operand[i] < 0)
			std::cout << "(" << operand[i] / (i + 1) << ")";
		else
			std::cout << operand[i] / (i + 1);
		if (i < num_op - 1)
			std::cout << " + ";
		else
			std::cout << std::endl;

		res = res + operand[i]/(i+1);

	}
	std::cout << "Result: " << res << std::endl << std::endl;
	return 0;
}



