#2
#Напишите скрипт, позволяющий искать в заданной директории и в ее подпапках файлы-дубликаты на основе сравнения контрольных сумм
#(MD5). Файлы могут иметь одинаковое содержимое, но отличаться именами. Скрипт должен вывести группы имен обнаруженных файлов - дубликатов. 

import os
import hashlib

path = r'D:\Games\test2'
files = os.listdir(path)
files_number = []
for file in files:
    with open(path + '\\' + file, 'rb') as f:
        content = f.read()
        files_number.append(hashlib.md5(content).hexdigest())

for i in range(len(files) - 1):
    for j in range(i + 1, len(files)):
        if files_number[i] == files_number[j]:
            print(files[i], ' дублирует ', files[j])