/*Объявить массив из n=20 вещественных чисел, проинициализировать нулями. Функция
processArray() должна заполнить массив случайными числами от -15.0 до 15.0,
подсчитать и вернуть среднее значение average элементов массива и сформировать
выходной булев массив, каждый элемент которого равен true (T), если
соответствующий элемент входного массива больше среднего значения и false (F) в
противоположном случае. Вывести на экран результирующие массивы.*/

#include <iostream> // подключение функций ввода/вывода
#include <cmath>
#include <stdio.h>
#include <ctime>
#include <cstdio>

using namespace std; // чтобы не записывать std::cin

void processArray(int, int);

void processArraiTOR(int, int, int);

const int n = 15;//Создаём 2 массива для вывода
int* mas = new int[15];
	
    int i;
    int c = 0;

    void processArray(int* mas, int i)//Функция
    {
        int a; //для диапазона (значение a)
        int b; //для диапазона (значение b)
        int r; //для случайного значения
        printf ("a=");//Ввод данных
        cin>> a;
        
            while (a>=0)
            {
                printf("а должно быть отрицательным, введите другое а\n");
                
                printf ("а=");
                cin >> a;

            }
            
            
        
        printf ("b=");
        cin >> b;
       
        srand(time(0));
        
        for (int i = 0; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                r = rand() % b + a; //Случайное значение от -а до b 
                mas[i] = mas[i]*r;
               
                r = 0;
            }
        }

    }


    void processArraiTOR(int* mas, int i, int c)//Функция для подсчёта отрицательных
    {

        
        for (int i = 0; i <= n; i++)
        {
            if (mas[i] < 0)
            {
                c = c + 1;
            }
        }
    }

int main()
{
    setlocale(LC_ALL, "Russian");//Русский язык в консоли
    for (i = 0; i < n; ++i)
    {
    mas[i] = 1;
    };//Создал массив

    int d[15] = { 0 };

    
    

    processArray(mas, i);
    
    printf ("[Вход]\n");
	for (i = 0; i < n; ++i)
	{
		cout << mas[i] << " ";
	}
    cout << endl;
     processArraiTOR(mas, i, c);
     cout << "[Выход]" << endl;
     for (i = 0; i < n; ++i)
     {
         if (mas[i] < 0)//Поиск массива отрицательных
         {
             d[i]=mas[i];
             c++; //Подсчёт отрицательных
         }

         
         cout << d[i] << " ";
     }
     cout << endl;
     cout <<"Кол-во отриц.="<<c;//Вывод кол-ва отрицательных
    return 0;
}