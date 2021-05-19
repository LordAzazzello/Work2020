#2
#Написать скрипт, который выводит на экран «True», если элементы программно задаваемого списка представляют собой возрастающую
#последовательность, иначе – «False».
#def chek_list (list):
    #print(False not in (list[i] < list[i+1] for i in range(len(list)-1)))
#print("Проверка списка")
#chek_list([12, 55, 62, 77, 88])

list = [i for i in input('Введите последовательность чисел: ').split(' ')]
print(True) if [i for i in range(len(list) - 1) if list[i] <= list[i + 1]] else print(False)