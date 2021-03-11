#15
#Напишите параметризированный декоратор pre_process, который осуществляет предварительную обработку (цифровую фильтрацию)
#списка по алгоритму: s[i] = s[i]–a∙s[i–1]. Параметр а можно задать в коде (по умолчанию равен 0.97).
def pre_process(a):
    def decorator(fn):
        def wrapped(list):
             return  fn([round(list[i]-a*list[i-1],2) for i in range(len(list))])
        return wrapped
    return decorator

@pre_process(0.97)
def plot_signal(list):
    [print(sample) for sample in list]

plot_signal([i for i in range(15)])