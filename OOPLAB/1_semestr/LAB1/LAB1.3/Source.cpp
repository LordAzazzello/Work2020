/*������� strchr.
������ char* strchr(char* s, int c).
������� ������� � ������ s ������ ��������� ������� � � ���������� ���������,
������������ � ����� �������.*/

#include<iostream>
#include<cstring>
#include <cstdio>
#include <stdio.h>

using namespace std;
char* mas;
char* rest_of_string = 0; //����� ������, ������� ���������� �������

char* RC (char* s, int c)
{
	size_t len = 0;//��������� ������
	
	while (s[len] != '\0')
	{
		if (s[len] == c) rest_of_string = s + len;//���� �� �������� � ������� ���
		len++;
	}
	return rest_of_string;

}


int main()
{
	setlocale(LC_ALL, "russian");
	char s[800] = "Hello cWorld!";
	printf("%s", s);
	printf("\n");
	char* standart_result = strrchr(s, 'c');
	char* myArr = RC(s, 'c');
	printf("Stand=%s", standart_result);
	printf("\n");
	printf("MyFUNK=%s", rest_of_string);

	return 0;
}