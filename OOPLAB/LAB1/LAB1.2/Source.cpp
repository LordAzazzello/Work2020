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

using namespace std; // чтобы не записывать std::cin

double* mas = new double[25]; //Параметры массива
int d = 5;//Элементы вниз
int r = 5;//Элементы вправо
int n;//Элемент массива
double mas2d[5][5];



void processArray(double, int);
void processSort(int*, int, int);
void process2D(double*, double**);

void processArray(double* mas, int n)//Инициализация массива
{
	for (int n = 0; n < 25; n++)
	{
		mas[n] = n * sin((3.14 * n) / 25);
		cout << setw(10) << mas[n];
	}
}

void processSort(double* mas, int d, int r)//Сортировка массива
{
	for (d = 0; d < 5; d++)
	{
		for (r = 0; r < 5; r++)
		{
			mas2d[d][r] = mas[n];
			n++;
		}
		cout << endl;
	}

}

void process2D(double*, double**)
{
	for (d = 0; d < 5; d++)
	{
		for (r = 0; r < 5; r++)
		{
			cout.width(10);
			mas2d[d][0] = mas2d[d][r + 1] + mas2d[d][r + 2] + mas2d[d][r + 3] + mas2d[d][r + 4];
			cout << mas2d[d][r];
		}
		cout << endl;
	}
}



int main()
{
	setlocale(LC_ALL, "Russian");//Русский язык в консоли
	cout << "Массив создан" << endl;
	processArray(mas, n);//Запуск функциии создания массива
	processSort(mas, d, r);//Запуск функции сортировки массива
	//process2D(mas, mas2d);//Замена 1 -ых элементов массива суммой элементов

	for (d = 0; d < 5; d++)
	{
		for (r = 0; r < 5; r++)
		{
			cout.width(10);
			mas2d[d][0] = mas2d[d][r + 1] + mas2d[d][r + 2] + mas2d[d][r + 3] + mas2d[d][r + 4];
			cout << mas2d[d][r];
		}
		cout << endl;
	}

	return 0;
}