#1.Напишите скрипт, который преобразует введенное с клавиатуры
#вещественное число в денежный формат. Например, число 12,5 должно
#быть преобразовано к виду «12 руб. 50 коп.». В случае ввода
#отрицательного числа выдайте сообщение «Некорректный формат!»
#путем обработки исключения в коде
def convert_to_money(num):
 try:
    if num>=0: print("Рублей=", int(num), "Копеек", round(num%1*100))
    else: raise Exception
 except Exception:
       print("Некорректный формат")
convert_to_money(float(input("Введите число: ")))