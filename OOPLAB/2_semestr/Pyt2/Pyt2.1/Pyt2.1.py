#1
#Напишите скрипт, который читает текстовый файл и выводит символы в порядке убывания частоты встречаемости в тексте. Регистр символа
#не имеет значения. Программа должна учитывать только буквенные символы (символы пунктуации, цифры и служебные символы слудет игнорировать). 
def count_letters():
    file = open('D:/Games/1.txt')
    input_text = file.read()
    file.close()
    dictionary = {i.upper(): input_text.count(i) for i in input_text if i.isalpha()}
    for value in sorted(dictionary.keys(), key=dictionary.get, reverse=True):
        print(value, " - ", dictionary[value])

count_letters()