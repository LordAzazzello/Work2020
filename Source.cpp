#include <iostream> // подключение функций ввода/вывода
#include <cmath>
#include <stdio.h>
#include <ctime>

using namespace std; // чтобы не записывать std::cin

void processArray(int, int);

void processArraiTOR(int, int, int);

const int n = 15;//Создаём 2 массива для вывода
int* mas = new int[15];
	
    int i;
    int c;

    void processArray(int* mas, int i)//Функция
    {
        int a; //для диапазона (значение a)
        int b; //для диапазона (значение b)
        int r; //для случайного значения
        cout << "a=-";//Ввод данных
        cin >> a;
        cout << "b=";
        cin >> b;
       
        srand(time(0));
        int tw = 1;
        for (int i = 0; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                r = rand() % b + (-a); //Случайное значение от -а до b 
                mas[i] = mas[i]*r;
               
                r = 0;
            }
        }

    }


    void processArraiTOR(int* mas, int i, int c)//Функция для подсчёта отрицательных и вывода 2 массива
    {

        c = 0;
        for (int i = 0; i <= n; i++)
        {
            if (mas[i] < 0)
            {
                c = c + 1;//Подсчёт отрицательных
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
   
    cout << mas;
    cout << d;

    processArray(mas, i);
    
	cout << "[Вход]" << endl;
	for (i = 0; i < n; ++i)
	{
		cout << mas[i] << " ";
	}
    cout << endl;
     processArraiTOR(mas, i, c);
     cout << "[Выход]" << endl;
     for (i = 0; i < n; ++i)
     {
         if (mas[i] < 0)
         {
             d[i]=mas[i];
         }

         
         cout << d[i] << " ";
     }
     cout << endl;
     cout <<"Кол-во отриц.="<<c;
    return 0;
}