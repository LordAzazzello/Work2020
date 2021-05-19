# Напишите скрипт с графическим интерфейсом пользователя для
# демонстрации работы класса StringFormatter. Примеры окон приведены
# на рис. 4 (все элементы управления необходимо обязательно
# реализовать те же, что присутствуют на рисунке). Разные комбинации
# отмеченных чекбоксов приводят к разным цепочкам операций
# форматирования задаваемой в верхнем поле строки с разными
# результатами

import sys

# импорт нашего интерфейса
from UI_task5 import *
from PyQt5 import QtCore, QtGui, QtWidgets
import re
import threading


class MyWin(QtWidgets.QMainWindow):
    def __init__(self, parent=None):
        QtWidgets.QWidget.__init__(self, parent)
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self._line = ''

        # постоянная проверка на то, можно ли показывать радиокнопки по сортировке
        second_task = threading.Thread(target=self.check_state)
        second_task.start()

        # привязка функций к кнопкам
        self.ui.Button_Formate.clicked.connect(self.clickFormat)

    # функция которая выполняется
    # при нажатии на кнопку

    def check_state(self):
        while True:
            if self.ui.CB_sort.isChecked():
                self.ui.RB_sort_size.setEnabled(True)
                self.ui.RB_sort_lex.setEnabled(True)
            elif not self.ui.CB_sort.isChecked():
                self.ui.RB_sort_size.setEnabled(False)
                self.ui.RB_sort_lex.setEnabled(False)

    def clickFormat(self):
        try:
            self._line = self.ui.lineEdit.text()
            if self._line == '':
                raise Exception('Строка пустая, создаём свою...')
        except Exception as e:
            print(e)
            self._line = 'S0m3 3rrors in y0ur str1ng'

        if self.ui.CB_delete_word_less_than.isChecked():
            num = 0
            try:
                num = self.ui.spinBox.value()
            except Exception as e:
                print(e.args)
            self._line = ' '.join(self.delete_by_num(num))

        if self.ui.CB_enter_spaces.isChecked():
            self._line = self.insert_spaces()

        if self.ui.CB_replace_nums_by_stars.isChecked():
            self._line = self.replace_nums()

        if self.ui.CB_sort.isChecked():
            if self.ui.RB_sort_size.isChecked():
                self._line = self.sort_by_size()
            else:
                self._line = self.sort_by_lec()
        try:
            self.ui.label.setText(self._line)
        except Exception as e:
            print(e.args)

    def delete_by_num(self, n):
        """temp = []
        words = self._line.split(' ')
        for i in range(len(words)):
            if len(words[i]) < n:
                temp.append(words[i])
        return ' '.join(temp)"""
        return [i for i in self._line.split(' ') if (len(i) >= n)]

    def replace_nums(self):
        return re.sub('\d', '*', self._line)

    def insert_spaces(self):
        return ' '.join(self._line)

    def sort_by_size(self):
        words = self._line.split()
        return ' '.join(sorted(words, key=lambda word: len(word)))

    def sort_by_lec(self):
        words = self._line.split()
        return ' '.join(sorted(words))


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    my_app = MyWin()
    my_app.show()
    sys.exit(app.exec_())
