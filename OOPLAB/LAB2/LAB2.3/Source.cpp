/*Написать собственный класс, в соответствии с вариантом. Продемонстрировать в коде
инкапсуляцию данных, применение конструкторов без параметров и с параметрами
для инициализации данных. Класс должен содержать метод serialize() для
сохранения данных класса в файл и метод deserialize() для чтения данных класса
из файла по умолчанию в текущей директории, а также перегруженные методы
serialize(const std::string& filename) и deserialize(const std::string&
filename) для работы с файлом с указанным в параметре именем
Класс СТУДЕНТ.
Данные: ФИО, пол, год рождения, год поступления, номер зачетки, средний балл.
Создать массив из 3 студентов и установить их личные данные с помощью сеттеров.
Еще одного студента создать отдельно в куче и установить его данные в конструкторе с
параметрами. В главной функции проимитировать три сессии – случайным образом
сформировать по 4 новые оценки и пересчитать в отдельном методе средний балл.
Вывести результаты студентов, отсортировав их в порядке убывания среднего балла.
*/
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Student.h"
using namespace std;

void Sort(Student* photomans, int num) {
	int j = 0;
	Student* temp = new Student;
	for (int i = 0; i < num; i++) {
		j = i;
		for (int k = i; k < num; k++)
			if (photomans[j].getScore() < photomans[k].getScore())
				j = k;
		*temp = photomans[i];
		photomans[i] = photomans[j];
		photomans[j] = *temp;
	}
	delete temp;
}

void CalcNewScore(Student* students, int i, float newScore) {
	//Для вычисления среднего бала: делаю бал как общий складываю бал из всех и плюсуем
	students[i].setScore(students[i].getScore() + newScore);
}
void Session(Student* students, int num) {
	cout << "Session:" << endl;
	for (int i = 0; i < num; i++)
	{
		float newScore = (2000 + rand() % 5000) / 1000;
		cout << "New score for student " << students[i].getFullName() << " is: " << newScore << endl;
		CalcNewScore(students, i, newScore);
		cout << "Current score is: " << students[i].getScore() << endl;
	}
	cout << endl;
}

int main()
{
	srand(time(0));

	//Инициализация
	Student* students1 = new Student[3];

	students1[0].setFullName("Chan Sin-Yan");
	students1[0].setSex(true);
	students1[0].setBirthYear(2002);
	students1[0].setStartYear(2020);
	students1[0].setNumber(5553535);
	students1[0].setScore(8800);

	students1[1].setFullName("Bruno Kattels Yong");
	students1[1].setSex(true);
	students1[1].setBirthYear(2000);
	students1[1].setStartYear(2018);
	students1[1].setNumber(999666);
	students1[1].setScore(5505.2);

	students1[2].setFullName("Duno Mac Evoi First");
	students1[2].setSex(true);
	students1[2].setBirthYear(2000);
	students1[2].setStartYear(2018);
	students1[2].setNumber(1111111);
	students1[2].setScore(1111.11);

	Student students2("Dima Armag Odin", true, 1984, 2010, 1234567, 3314.1);

	Student* students = new Student[4];
	for (int i = 0; i < 3; i++)
	{
		students[i] = students1[i];
	}
	students[3] = students2;

	//Сессии
	for (int i = 0; i < 3; i++)
		Session(students, 4);

	//Сортировка
	cout << "Sorting:" << endl;
	Sort(students, 4);
	for (int i = 0; i < 4; i++) {
		cout << i << ")";
		cout << students[i].getFullName() << " ";
		cout << students[i].getScore() << endl;
	}

	//Сериализация/десериализация
	cout << "Serialize:" << endl;
	cout << "Student 1 name:" << students[1].getFullName() << endl;
	students[1].setFullName("Serizlized student");
	cout << "Set student 1 name 'Serialized'" << endl;
	students[1].Serialize();
	cout << "Serializing" << endl;
	students[1].setFullName("Bruno Kattels Yong");
	cout << "Set student 1 name: 'Bruno Kattels Yong'" << endl;
	students[1].Deserialize();
	cout << "Deserializing" << endl;
	cout << "Student 1 name: " << students[1].getFullName() << endl;
	cout << endl;

	delete[] students;
	return 0;
}