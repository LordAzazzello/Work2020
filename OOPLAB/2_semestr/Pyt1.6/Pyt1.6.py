#6
#Напишите программу, позволяющую ввести с клавиатуры текст предложения и вывести на консоль все символы, которые входят в этот
#текст ровно по одному разу.
def chec(x):
    print(" ".join(i for i in x if x.count(i)==1))

chec(input("Введи предложение: "))