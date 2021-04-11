#4
#Напишите скрипт, который разделяет введенный с клавиатуры текст на слова и выводит сначала те слова, длина которых превосходит 7
#символов, затем слова размером от 4 до 7 символов, затем – все остальные.
#def word(words):
 #  words.sort(key=len, reverse=True)
  # print(" ".join(words))
#word(input("Введи данные: ").split())

#Text=input('Введите текст: ').replace(',', ' ').split(' ')
#print('Длина > 7: {0}\n'.format([i for i in Text if len(i)>7]))
#print('Длина 4 - 7: {0}\n'.format([i for i in Text if len(i)>=4 and len(i)<=7]))
#print('Длина < 4: {0}\n'.format([i for i in Text if len(i)<4]))

Text=input('Введите текст: ').replace(',', ' ').split(' ')
print('Длина > 7: {0}\n'.format([i for i in Text if len(i)>7]))
print('Длина 4 - 7: {0}\n'.format([i for i in Text if len(i)>=4 and len(i)<=7]))
print('Длина < 4: {0}\n'.format([i for i in Text if len(i)<4]))