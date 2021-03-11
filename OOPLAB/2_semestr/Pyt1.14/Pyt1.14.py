#14
#Напишите декоратор non_empty, который дополнительно проверяет списковый результат любой функции: если в нем содержатся пустые
#строки или значение None, то они удаляются.
def non_empty(fn):
    def wrapped():
        return list(filter(None, fn()))
    return wrapped

@non_empty
def get_pages():
    return ['', 'chapter', 'copter', '', 'crysis', '']

print(get_pages())