from Task1 import *
from Task3 import *
from Task5 import *
from Task6 import *
import csv
import pandas as pd
from pandas import read_csv
from sympy import *
import sqlalchemy
from sqlalchemy.orm import sessionmaker


#Напишите скрипт, читающий во всех mp3-файлах указанной директории ID3v1-теги и выводящий информацию о каждом файле в
#виде: [имя исполнителя] - [название трека] - [название альбома]. Если пользователь при вызове скрипта задает ключ -d, то выведите
#для каждого файла также 16-ричный дамп тега. Скрипт должен также автоматически проставить номера треков и жанр (номер
#жанра задается в параметре командной строки), если они не проставлены. Используйте модуль struct. ID3v1-заголовки располагаются в последних 128 байтах mp3-файла. 

def task1():

    Task1().decoding()

task1()

#Выполните задание средствами SQLAlchemy, включая создание и редактирование таблиц, а также выполнение таких запросов, как:
#- вывод фамилий всех авторов, родившихся в диапазоне между X и Y годами (задайте программно числа X и Y);
#- вывод всех книг, написанных авторами из России;
#- вывод всех книг с количеством страниц более N;
#- вывод всех авторов с числом книг более N.

def task3():

    engine = sqlalchemy.create_engine('sqlite:///Library.db', echo=False)
    Session = sessionmaker(bind=engine)
    sessia = Session()

    print_range(sessia)
    print_russians(sessia)
    print_pages(sessia)
    print_authors(sessia)

    sessia.close()

task3()

#Напишите приложение для загрузки файлов из интернета. В главном окне должно быть три текстовых поля, в которые можно вводить
#URL файла на закачку; под каждым из текстовых полей должны быть индикаторы загрузки и рядом поля с процентом загрузки
#каждого файла. Необходимо организовать возможность качать от одного до трех файлов параллельно (использовать потоки
#обязательно, файлы загружать фрагментами по 4 Кб). Загрузка должна инициироваться нажатием кнопки «Start downloading!». По
#окончанию загрузки последнего файла должно появиться окно со столбчатой диаграммой со значениями времени загрузки каждого 27 файла в формате «2s 322ms» 
#и размерами файлов (используйте библиотеку matplotlib).


def task5():

    app = QtCore.QCoreApplication.instance()
    if app is None:
        app = QtWidgets.QApplication(sys.argv)
    window = Task5()
    window.show()

    app.exec_()

task5()

#С помощью модуля numPy реализуйте следующие операции: 
#1) умножение произвольных матриц А (размерности 3х5) и В (5х2); 
#2) умножение матрицы (5х3) на трехмерный вектор; 
#3) решение произвольной системы линейных уравнений; 
#4) расчет определителя матрицы; 
#5) получение обратной и транспонированной матриц.
#Также продемонстрируйте на примере матрицы 5х5 тот факт, что определитель равен произведению собственных значений матрицы.

def task6():

    matrix_multiplication()
    vector_multiplication()
    linear_equation()
    det_matrix()
    inverse_matrix()
    transposed_matrix()

task6()

#Выберите произвольную дифференцируемую и интегрируемую функцию одной переменной. С помощью модуля symPy найдите и 
#отобразите ее производную и интеграл в аналитическом и графическом виде. Напишите код для решения произвольного
#нелинейного уравнения и системы нелинейных уравнений.

def solution(*equations):
    if len(equations) == 1:
        return solve(equations[0])
    return solve_poly_system(equations)

def task7():
    z = Symbol('z')
    fun = z + 2
    print('Заданная функция: ', str(fun))
    print('Производная функции: ', end='')
    derivative = diff(fun)
    pprint(derivative)
    plot(derivative)
    print('\nИнтеграл функции: ', end='')
    integral = integrate(fun)
    pprint(integral)
    plot(integral)

    x, y = symbols('x y')
    eq1 = Equality(0, x - 2*y)
    eq2 = Equality(0, y-3)
    eq3 = Equality(12, 2*x)
    print('\nСистема уравнений:')
    pprint(eq1)
    pprint(eq2)
    print('\nОтвет: ', end='')
    pprint(solution(eq1, eq2))
    print('\nУравнение:')
    pprint(eq3)
    print('\nОтвет: ', end='')
    pprint(solution(eq3))

task7()


#С помощью модуля pandas отобразите: 
#1) 10 самых маленьких и самых больших стран мира по территории; 
#2) 10 самых маленьких и самых больших стран мира по населению; 
#3) все франкоязычные страны мира;
#4) только островные государства; 
#5) все страны, находящиеся в южном полушарии. 
#Сгруппируйте страны по первой букве; по населению; по территории.
#Программно сохраните в таблицу Excel все страны с выборочной информацией: название, столица, население, территория, валюта, широта, долгота.

file_countries = 'countries.csv'

def save_table(table):
        titles = pd.Series([i.split(',')[0] for i in table.name])
        titles.name = 'name'
        lat, lng = zip(*[i.split(',')
                         if isinstance(i, str)
                         else ['nan', 'nan']
                         for i in table.latlng])
        lat, lng = map(pd.Series, (lat, lng))
        lat.name = 'latitude'
        lng.name = 'longitude'
        output_data = pd.concat([titles, table[['capital', 'ccn3', 'area', 'currencies']], lat, lng], axis=1)
        with pd.ExcelWriter('newdata.xls') as file:
            output_data.to_excel(file)

def task8():
    table = read_csv(file_countries, ',')
    print('\n1) 10 самых самых больших стран мира по территории:\n')
    print(table.nlargest(10, columns='area')[['name']])
    print('\n1) 10 самых маленьких стран мира по территории:\n')
    print(table.nsmallest(10, ['area'])[['name']])
    print('\n2) 10 самых больших стран мира по населению:\n')
    print(table.nlargest(10, ['ccn3'])[['name']])
    print('\n2) 10 самых маленьких стран мира по населению:\n')
    print(table.nsmallest(10, ['ccn3'])[['name']])
    print('\n3) все франкоязычные страны мира:\n')
    print(table[table.languages == 'French'][['name']])
    print('\n4) только островные государства:\n')
    print(table[table.borders.isnull()][['name']])
    print('\n5) все страны, находящиеся в южном полушарии:\n')
    print(table.where(pd.Series([float(str(i).split(',')[0]) < 0 for i in table.latlng])).name.dropna())

    print('\nГруппировка стран по первой букве:\n')
    for i, group in table.groupby([i[0] for i in table.name]):
       print(str(i) + ' : ')
       for j, name in enumerate(group.name, 1):
           print(name.split(',')[0])
    print('\nГруппировка стран по населению:\n')
    for i, group in table.groupby(table.ccn3):
       print(str(i) + ' : ', end='')
       for j, name in enumerate(group.name, 1):
           print(name.split(',')[0])
    print('\nГруппировка стран по территории:\n')
    for i, group in table.groupby(table.area):
       print(str(i) + ' : ', end='')
       for j, name in enumerate(group.name, 1):
           print(name.split(',')[0])

    save_table(table=table)
    

task8()
