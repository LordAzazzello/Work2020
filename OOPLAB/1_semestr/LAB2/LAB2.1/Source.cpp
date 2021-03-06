/*Написать классы Vector и Matrix для хранения и обработки одномерных и
двумерных массивов, соответственно. Реализовать задание 2 лабораторной работы №1
с помощью созданных классов. Все функции оформить в виде методов классов.
В коде отразить следующее:
 Выделение и освобождение динамической памяти производить в конструкторах и
деструкторах классов, соответственно.
 В классе Vector перегрузить оператор индексации []. В классе Matrix добавить
методы T at(int i, int j) const и setAt(int i, int j, T val), которые
позволяют получить и установить значение элемента массива с индексом [i][j], T –
это тип элементов массива по варианту (int или double).
 Перегрузить операторы инкремента и декремента (как префиксного, так и
постфиксного). Смысл инкремента / декремента всего массива заключается в
инкременте / декременте каждого элемента массива*/
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include "Vector.h"
#include "Matrix.h"

using namespace std; // чтобы не записывать std::cin

void arrIN(Vector& arr)
{
	for (int i = 0; i < 25; i++)
	{
		arr[i] = i * sin((3.14 * i) / 25);
		cout << setw(10) << arr[i];
	}
}

void krey2d(Matrix& arr2d, Vector& arr)
{

	for (int i = 0; i < arr2d.GetRows(); i++)//использую метод класса 
	{
		for (int j = 0; j < arr2d.GetCols(); j++)
		{
			arr2d[i][j] = arr[i * arr2d.GetCols() + j];
			cout << setw(10) << arr2d[i][j];
		}
		cout << endl;
	}
}

void summ(Matrix& arr2d)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << setw(10);
			arr2d[i][0] = arr2d[i][j + 1] + arr2d[i][j + 2] + arr2d[i][j + 3] + arr2d[i][j + 4];
			cout << arr2d[i][j];
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");//Русский язык в консоли

	int rows = 5;//Строки
	int cols = 5;//Столбцы
	Vector arr(25);//Создаем массив
	Matrix arr2d(rows, cols);//Создаем 2Д массив

	arrIN(arr);
	cout << endl;
	cout << "Массив создан" << endl;

	krey2d(arr2d, arr);
	cout << endl;
	cout << "Массив, с 1 строкой - суммой всех элементов строки" << endl;

	summ(arr2d);

	return 0;
}