/*�������� ������ �� n=20 ������������ �����, ������������������� ������. �������
processArray() ������ ��������� ������ ���������� ������� �� -15.0 �� 15.0,
���������� � ������� ������� �������� average ��������� ������� � ������������
�������� ����� ������, ������ ������� �������� ����� true (T), ����
��������������� ������� �������� ������� ������ �������� �������� � false (F) �
��������������� ������. ������� �� ����� �������������� �������.*/

#include <iostream> // ����������� ������� �����/������
#include <cmath>
#include <stdio.h>
#include <ctime>
#include <cstdio>

using namespace std; // ����� �� ���������� std::cin

void processArray(int, int);

void processArraiTOR(int, int, int);

const int n = 15;//������ 2 ������� ��� ������
int* mas = new int[15];
	
    int i;
    int c = 0;

    void processArray(int* mas, int i)//�������
    {
        int a; //��� ��������� (�������� a)
        int b; //��� ��������� (�������� b)
        int r; //��� ���������� ��������
        printf ("a=");//���� ������
        cin>> a;
        
            while (a>=0)
            {
                printf("� ������ ���� �������������, ������� ������ �\n");
                
                printf ("�=");
                cin >> a;

            }
            
            
        
        printf ("b=");
        cin >> b;
       
        srand(time(0));
        
        for (int i = 0; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                r = rand() % b + a; //��������� �������� �� -� �� b 
                mas[i] = mas[i]*r;
               
                r = 0;
            }
        }

    }


    void processArraiTOR(int* mas, int i, int c)//������� ��� �������� �������������
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
    setlocale(LC_ALL, "Russian");//������� ���� � �������
    for (i = 0; i < n; ++i)
    {
    mas[i] = 1;
    };//������ ������

    int d[15] = { 0 };

    
    

    processArray(mas, i);
    
    printf ("[����]\n");
	for (i = 0; i < n; ++i)
	{
		cout << mas[i] << " ";
	}
    cout << endl;
     processArraiTOR(mas, i, c);
     cout << "[�����]" << endl;
     for (i = 0; i < n; ++i)
     {
         if (mas[i] < 0)//����� ������� �������������
         {
             d[i]=mas[i];
             c++; //������� �������������
         }

         
         cout << d[i] << " ";
     }
     cout << endl;
     cout <<"���-�� �����.="<<c;//����� ���-�� �������������
    return 0;
}