# Создайте графическую оболочку для скрипта, написанного в ходе
# выполнения задания № 4 лабораторной работы № 2, в виде диалогового
# окна (рис. 2). Рекомендуется использовать wxPython или PyQt.
#
# Требования к окну и скрипту:
# 18
# - всю область окна должен занимать список с результатами поиска
# строк по шаблону в файле и указанием даты и времени поиска.
# Поиск производится автоматически при каждом открытии какоголибо файла, при этом список не очищается, а пополняется новыми
# результатами. При запуске скрипта список изначально должен быть
# пустым (из файла лога данные подгружать не нужно);
# - строка меню содержит пункты «Файл» (с подпунктом «Открыть...»
# для открытия файла, в котором необходимо искать строки) и «Лог»
# (с подпунктами «Экспорт...», «Добавить в лог», «Просмотр»). Файл
# лога находится в рабочей папке скрипта и называется script18.log.
# Если файл отсутствует, скрипт при запуске должен выдать
# диалоговое окно с информацией «Файл лога не найден. Файл будет
# создан автоматически» и кнопкой «ОК». При выборе пункта меню
# «Экспорт...» содержимое списка должно сохраниться в файле,
# который укажет пользователь. При выборе пункта «Добавить в лог»
# содержимое списка приписывается в конец файла script18.log. При
# выборе пункта «Просмотр» текущее содержимое списка удаляется,
# и список заполняется данными из лога. Перед этим действием скрипт
# должен выдать диалоговое окно с вопросом «Вы действительно
# хотите открыть лог? Данные последних поисков будут потеряны!»
# и кнопками «Да» и «Нет»;
# - статусная строка должна состоять из двух полей: в первом поле (60%
# ширины окна), в зависимости от последнего произведенного
# действия, выводится либо текст «Открыт лог», либо текст
# «Обработан файл <полное_имя_файла>»; второе поле (40%
# ширины окна) служит для отображения размера последнего
# обработанного файла в байтах. Эта строка форматируется: выводятся
# пробелы между степенями тысячи (например, «2 036 231 байт»);
# - файлы нужно открывать и сохранять с помощью стандартного
# диалогового окна (рис. 3).

import re  # regex
import sys  # система
import os  # для работы с файлами
from PyQt5 import QtCore, QtGui, QtWidgets  # Для UI
from PyQt5.QtWidgets import QFileDialog, QMessageBox  # для сторонних задач
from UI_task3 import *  # наше UI
from time import gmtime, strftime  # для времени

pattern = re.compile("83\d{3}, \w+ ")
cnt = 0


class MyWin(QtWidgets.QMainWindow):
    def __init__(self, parent=None):
        QtWidgets.QWidget.__init__(self, parent)
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)

        # menu_file
        self.ui.file_open_action.triggered.connect(self.open_file)  # устанавливаем триггер на кнопку меню

        # menu_log
        self.ui.log_export_action.triggered.connect(self.log_export)
        self.ui.log_add_action.triggered.connect(self.log_add)
        self.ui.log_check_action.triggered.connect(self.log_check)

        self.check_for_file()

        # variables
        self._data = []

    def proccess(self, type_log=False):
        global cnt
        information = None
        if type_log is False:
            try:
                information = self._data[cnt]
            except Exception as e:
                print(e.args)
            self.add_item(info='Файл {0} был обработан в {1}'.format(information[0], information[1]))
            self.add_item(' ')
            for line in information[-1]:
                self.add_item(str(line))
            self.add_item(' ')
            cnt += 1
        elif type_log is True:
            for line in self._data:
                try:
                    self.add_item(info='Файл {0} был обработан в {1}'.format(line[0], line[1]))
                except Exception as e:
                    print('Error in add name and time: ', e.args)
                self.add_item(' ')
                try:
                    for item in line[2]:
                        try:
                            self.add_item(str(item))
                        except Exception as e:
                            print('Error in add second Line', e.args)
                except Exception as e:
                    print('Or Error in out of index: ', e.args)
                self.add_item(' ')

    def add_item(self, info):
        # создаём объект QListWidgetItem
        item = QtWidgets.QListWidgetItem()
        # Выделяем наш объект
        # item.setCheckState(QtCore.Qt.Checked)
        # Добавляем название в наш элемент
        item.setText('{}'.format(info))
        # Добавляем item в ListWidget
        self.ui.listWidget.addItem(item)

    # считка данных с файла, указанного пользователем
    def open_file(self):
        cnt_str = 0
        tmp = []
        filename = QFileDialog.getOpenFileName(self, 'Open file')[0]
        with open(filename, 'r') as f:
            # считка из файла
            content = f.readlines()
            for line in content:
                cnt_str += 1
                indexes = re.findall(pattern, line)
                if indexes is not None:
                    for index1 in indexes:
                        tmp.append('Строка #{0}, позиция #{1}: найдено <{2}>'.format(cnt_str,
                                                                                     line.index(index1),
                                                                                     index1[:-1]))
        # получаем время выполнения операции
        curr_time = strftime('%Y-%m-%d %H:%M:%S', gmtime())
        self._data.append((os.path.basename(filename), curr_time, tmp))
        print(self._data)
        self.proccess()

    # сохранение данных в файле, который укажет пользователь
    def log_export(self):
        filepath = QFileDialog.getSaveFileName(self, 'Save File', 'name', 'Log files (*.log)' or 'Txt files (*.txt)')[0]
        print(filepath)
        self.save_data(filepath)

    def save_data(self, path='script18.log'):
        if path == 'script18.log':
            try:
                with open(path, 'a') as f:
                    for line in self._data:
                        f.write(str(line))
                        f.write('\n')
            except Exception as e:
                print(e.args)
        else:
            try:
                with open(path, 'w') as f:
                    for line in self._data:
                        f.write(str(line))
                        f.write('\n')
            except Exception as e:
                print('Error ', e.args)

    # Дозапись данных в конец файла script18.log
    def log_add(self):  # 'a' - флаг на дозапись в файл
        self.save_data()
        QMessageBox.question(self,
                             'Data saved!',
                             'Данные сохранены в файле script18.log!',
                             QMessageBox.Ok, QMessageBox.Ok)  # QMessageBox.Yes | QMessageBox.No - для выбора

    # Вывести на экран логи, которые хранятся в файле script18.log
    def log_check(self):
        tmp = []
        names = []
        times = []
        coincidences = []
        pattern_for_name = re.compile("\w+\D+\w+\D+\.txt")
        pattern_for_time = re.compile("\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}")
        pattern_for_coincidences = re.compile("Строка #\d+, позиция #\d+: найдено <83\d{3}, \D+>")
        with open('script18.log', 'r') as f:
            tmp = f.readlines()
            for line in tmp:
                print('LINE: ', line)
                name = re.findall(pattern_for_name, line.replace('\n', ''))
                time = re.findall(pattern_for_time, line.replace('\n', ''))
                coincidence = re.findall(pattern_for_coincidences, line.replace('\n', ''))
                self._data.append((str(name[0]), str(time[0]), coincidence))
            print('#2 ', self._data)
            self.proccess(type_log=True)

    # Если файла script17.log нет - создаём его
    def check_for_file(self):
        if not os.path.exists(os.getcwd() + '\\script18.log'):
            QMessageBox.question(self,
                                 'File not found.',
                                 'Файл не найден. Он будет создан прямо сейчас...',
                                 QMessageBox.Ok, QMessageBox.Ok)  # QMessageBox.Yes | QMessageBox.No - для выбора

            file = open(os.getcwd() + '\\script18.log', 'w')
            file.close()


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    my_app = MyWin()
    my_app.show()
    sys.exit(app.exec_())
