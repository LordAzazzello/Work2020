/*Функция strchr.
Формат char* strchr(char* s, int c).
Функция находит в строке s первое вхождение символа с и возвращает подстроку,
начинающуюся с этого символа.*/

#include<iostream>
#include<cstring>
#include <cstdio>
#include <stdio.h>

using namespace std;
char* mas;
char* rest_of_string = 0; //Часть строки, которую необходимо вернуть

char* RC (char* s, int c)
{
	size_t len = 0;//Начальный индккс
	
	while (s[len] != '\0')
	{
		if (s[len] == c) rest_of_string = s + len;//Если не встречен с функция идёт
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