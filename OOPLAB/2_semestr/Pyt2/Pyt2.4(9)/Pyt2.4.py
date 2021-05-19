#Напишите скрипт, который позволяет ввести с клавиатуры имя текстового файла, найти в нем с помощью регулярных выражений все
#подстроки определенного вида, в соответствии с вариантом 
# Вариант 9: найдите все донецкие почтовые индексы – подстроки вида «83000, Донецк» (первые 2 символа строго закреплены: «83»)
import re

# начинается с 83, остальные 3 цифры не важны, дальше должна быть запятая и название города, до пробела

pattern = re.compile("83\d{3}, \D+ ")
content = ''
matches = []
path = input('Введите название вашего файла')
try:
    file = open('D:\\Games\\' + path, 'r', encoding='UTF-8')
    content = file.read().replace('\n', ' ')
    file.close()
except FileNotFoundError as e:
    print('File does not exist. ', e.args)

print(content)

result = re.findall(pattern, content)
print(result)