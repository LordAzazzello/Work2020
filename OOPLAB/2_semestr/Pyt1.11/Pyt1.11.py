#11
#Напишите генератор frange как аналог range() с дробным шагом. 
def frange(start, stop, step):
    while start < stop - step:
         yield round(start, 1)
         start += step

[print(i, end = "\n") for i in frange(1, 5, 0.1)]