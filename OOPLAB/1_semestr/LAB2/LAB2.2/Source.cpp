/*Написать класс Fraction для представления обыкновенных дробей (как отношения
двух целых чисел x/y). Перегрузить операторы +, -, *, / для дробей. Реализовать метод
void reduce() для сокращения дроби, а также статические методы:
 int gcd(int n, int m)
функция для нахождения наибольшего общего делителя чисел n и m;
 void printAsFraction(double decimal_fraction)
 void printAsFraction(char* decimal_fraction)
перегруженные методы вывода десятичной дроби в виде обыкновенной
(например, при значении decimal_fraction = 0.43 на экране должно
вывестись 43/100, при 0.25 – 1/4 и т.д.).
Также реализовать в виде статического члена класса счетчик всех созданных на
данный момент в программе экземпляров дробей.
Продемонстрировать работу созданного класса. Создать несколько объектов дробей.
Произвести операции сложения, вычитания, умножения и деления дробей. Вывести
на экран результаты. Показать также результаты работы статических методов класса.*/
#include "Fraction.h"
using namespace std;

int Fraction::FractionCount = 0;
int main()
{
	cout << "Fraction Num = " << Fraction::GetFractionCount() << endl << endl;

	Fraction F1(5, 10);
	Fraction F2(double(1.5));
	cout << "F1 = " << F1 << endl;
	cout << "F2 = " << F2 << endl << endl;

	cout << "F1 + F2 = " << F1 + F2 << endl;//вызов перегруженных операторов
	cout << "F1 - F2 = " << F1 - F2 << endl;
	cout << "F1 * F2 = " << F1 * F2 << endl;
	cout << "F1 / F2 = " << F1 / F2 << endl << endl;

	cout << "gcd 8/12 = " << Fraction::gcd(7, 14) << endl;
	cout << "gcd 10/2 = " << Fraction::gcd(150, 45) << endl << endl;

	cout << "PrintAsFraction 0.3 = ";
	Fraction::PrintAsFraction(0.3);
	cout << endl;
	cout << "PrintAsFraction 5.2 = ";
	Fraction::PrintAsFraction(5.2);
	cout << endl << endl;

	cout << "Fraction Num = " << Fraction::GetFractionCount() << endl;

	return 0;
}