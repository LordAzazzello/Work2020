// lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <fstream>
#include "ExpressionEvalutor.h"
#include "CustomExpressionEvalutor.h"
#include "Subtractor.h"
#include "Multiplier.h"
using namespace std;


int main()
{
    ExpressionEvalutor* ev[3];

    ev[0] = new Subtractor(4);
    double s_operands[] = {5.6,-2.1,3.2,1.5};
    ev[0]->setOperands(s_operands, 4);

    ev[1] = new Multiplier(3);
    double m_operands[] = {1.5,-8,2.5};
    ev[1]->setOperands(m_operands, 3);

 
    ev[2] = new CustomExpressionEvalutor(6);
    double e_operands[] = {5,16,-3,10,12,2};
    ev[2]->setOperand(0, 5);
    ev[2]->setOperand(1, 16);
    ev[2]->setOperand(2, -3);
    ev[2]->setOperand(3, 10);
    ev[2]->setOperand(4, 12);
    ev[2]->setOperand(5, 2);
    
    for (size_t i = 0;i < 3;i++) {
        ev[i]->calculate();
    }

    for (size_t i = 0;i < 3;i++) {
        if (dynamic_cast<IShuffle*>(ev[i]) != NULL) {
            cout << "Is instance of IShuffle" << endl;
            static_cast<Subtractor*>(ev[0])->shuffle();
        }
    }

    
}
