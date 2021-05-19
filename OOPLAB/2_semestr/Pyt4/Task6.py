import numpy
from numpy.linalg import*

def matrix_multiplication():
    print('1) умножение произвольных матриц А (размерности 3х5) и В (5х2):')
    a = numpy.arange(3 * 5).reshape((3, 5))
    b = numpy.arange(5 * 2).reshape((5, 2))
    print('А:\n', a)
    print('В:\n', b)
    print('Итог: \n', a@b)

def vector_multiplication():
    print('\n2) умножение матрицы (5х3) на трехмерный вектор: ', end='')
    matrix = numpy.arange(2 * 3).reshape((3, 2))
    vector = numpy.array([1, 5], dtype=float)
    print(matrix@vector)

def linear_equation():
    print('3) решение произвольной системы линейных уравнений: ', end='') #3x - 4y = 7, 11x + 10y = 3
    matrix = numpy.array([[3., -4.], [11., 10.]])
    vector = numpy.array([7., 3.])
    print(numpy.linalg.solve(matrix, vector))

def det_matrix():
    print('4) расчет определителя матрицы: ', end='\n')
    matrix = numpy.array([[2, 8, 2], [4, 1, 7], [3, 9, 13]])
    print(matrix)
    print('Определитель = ', det(matrix))

def inverse_matrix():
    print('\n5) получение обратной матрицы:')
    a = numpy.array([[2, 8, 2], [4, 1, 7], [3, 9, 13]])
    print(a, '\n=> ')
    a_invented = inv(a)
    print(a_invented)

def transposed_matrix():
    print('\n5) получение транспонированной матрицы: ')
    a = numpy.array([[2, 8, 2], [4, 1, 7], [3, 9, 13]])
    print(a, '\n=> ')
    a = a.transpose()
    print(a)
