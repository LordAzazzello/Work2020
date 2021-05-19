import os
import threading
import Task5Window
import requests
import matplotlib
import numpy as np
import matplotlib.pyplot as plt
from time import time
from PyQt5 import QtCore, QtWidgets

class Task5(QtWidgets.QMainWindow):
    def __init__(self):
        QtWidgets.QMainWindow.__init__(self)
        self.ui = Task5Window.MainWindow()
        self.ui.setupUi(self)
        self.ui.pushButton.clicked.connect(self.download)
        self.datas = []

    def plot_stuff(self):
        len = len(self.datas)
        timeMeans = np.array([i.time_to_download for i in self.datas])
        ind = np.arange(len)
        width = 0.35
        plt.subplot(2, 1, 1)
        plt.bar(ind, timeMeans, width)
        plt.ylabel('Время')
        plt.title('Время для каждого файла')
        plt.xticks(ind, ([i.filename for i in self.datas]))
        plt.yticks(np.arange(0, 10, 1))
        plt.subplot(2, 1, 2)
        titles = [i.filename for i in self.datas]
        sizes = [i.size for i in self.datas]
        plt.pie(sizes, labels=titles)
        plt.show()
        
        
    def download(self):
        th1 = threading.Thread(target = self.threading, args=(self.ui.lineEdit, self.ui.progressBar))
        th2 = threading.Thread(target = self.threading, args=(self.ui.lineEdit_2, self.ui.progressBar_2))
        th3 = threading.Thread(target = self.threading, args=(self.ui.lineEdit_3, self.ui.progressBar_3))
        th1.start()
        th2.start()
        th3.start()
        th1.join()
        th2.join()
        th3.join()
        self.plot_stuff()

    def threading(self, line_edit : QtWidgets.QLineEdit, progress_bar : QtWidgets.QProgressBar):
        data = DownloadData()
        if self.ui.lineEdit.text() != '':
            start = time()
            url = line_edit.text()
            request = requests.get(url, stream=True)
            file_name = url.split('/')[-1]
            data.filename = file_name
            content_length = int(request.headers.get('content-length'))
            data.size = content_length
            progress_bar.setMaximum(content_length)
            with open(file_name, "wb") as file:
                i = 0
                for j in request.iter_content(4):
                    i += 4
                    file.write(j)
                    progress_bar.setValue(i)
            time_download = time() - start
            data.time_to_download = time_download
            progress_bar.setValue(content_length)
            self.datas.append(data)
            
class DownloadData():
    def __init__(self):
        file_name = ""
        time_download = ""
        size = ""
