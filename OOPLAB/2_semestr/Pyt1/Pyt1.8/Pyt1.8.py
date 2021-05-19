#8
#Напишите скрипт, генерирующий случайным образом число n в диапазоне от 1 до 10000. Скрипт должен создать массив из n целых
#чисел, также сгенерированных случайным образом, и дополнить массив нулями до размера, равного ближайшей сверху степени двойки.
#Например, если в массиве было n=100 элементов, то массив нужно дополнить 28 нулями, чтобы в итоге был массив из 28 =128 элементов
#(ближайшая степень двойки к 100 – это число 128, к 35 – это 64 и т.д.).
from random import randint
from math import ceil, log2
x = []
for n in range(1, randint(1, 10001)):
        x.append(randint(1, 10000))
        count = len(x)
dif = 2 ** ceil(log2(count)) - count
add_zero = [0 for _ in range(dif)]
result = x + add_zero
print(result)