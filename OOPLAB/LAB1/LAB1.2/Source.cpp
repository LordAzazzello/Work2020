/*
Преобразование: 1D → 2D. Одномерный массив из 25 вещественных чисел необходимо
разложить по двумерной сетке 5х5 слева направо и сверху вниз, но первый элемент на
каждой строке должен содержать сумму остальных четырех.
Инициализация: заполнить массив числами x[n] = n ∙ sin(πn/25), n – индекс элемента.
Вывод на экран: на каждый элемент массива отвести 10 позиций.
*/
#include<iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <cstring>

using namespace std; // чтобы не записывать std::cin

int i;//Индекс элемента
int rows = 5;//Строки
int cols = 5;//Столбцы
float* arr = new float[25];//Выделил место под массив

void arrIN(float* arr)
{
	for (i = 0; i < 25; i++)
	{
		arr[i] = i * sin((3.14 * i) / 25);
		cout << setw(10) << arr[i];
	}
}

float** krey2d(float** arr2d, float* arr, size_t  rows,  size_t  cols)
{
	int coun = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			*(*(arr2d + i) + j) = *(arr+i*cols+j);
			cout << setw(10) << arr2d[i][j];
			//coun++;
		}
		coun++;
		cout << endl;
	}
	return arr2d;
}

void summ(float** arr2d)
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
	float** arr2d = new float* [rows];//Выделяем место под 2Д
	for (int i = 0; i < rows; i++)
	{
		arr2d[i] = new float[cols];
	}
	arrIN(arr);
	cout << endl;
	cout << "Массив создан" << endl;
	krey2d(arr2d, arr, rows, cols);
	cout << endl;
	cout << "Массив, с 1 строкой - суммой всех элементов строки" << endl;
	summ(arr2d);
	
	for (int i = 0; i < rows; i++)
	{
		delete arr2d[i];
	}
	delete[]arr;
	return 0;
}