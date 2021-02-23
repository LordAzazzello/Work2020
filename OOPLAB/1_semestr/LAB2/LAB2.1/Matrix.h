#pragma once
class Matrix
{
private:
    int length_rows;
    int length_cols;
    float** matrix;

public:
    Matrix(int x_len, int y_len) {
        matrix = new float* [x_len];
        for (int i = 0; i < x_len; i++) {
            matrix[i] = new float[y_len];
        }
        length_rows = x_len;
        length_cols = y_len;
    }
    ~Matrix() {//Деструктор для удаления массива
        for (int i = 0; i < length_rows; i++) {
            delete matrix[i];
        }
        delete[] matrix;
    }

    float at(int x, int y) {
        return matrix[x][y];
    }
    void setAt(int x, int y, float value) {
        matrix[x][y] = value;
    }

    int GetLength() {
        return length_rows * length_cols;
    }
    int GetRows() {
        return length_rows;
    }
    int GetCols() {
        return length_cols;
    }

    float operator = (float value) {
        return value;
    }
    float* operator [] (int i) {
        return matrix[i];
    }

    Matrix& operator ++ () {
        for (int i = 0; i < length_rows; i++)
            for (int j = 0; j < length_cols; j++)
                matrix[i][j]++;
        return *this;
    }
    Matrix& operator ++ (int) {
        Matrix temp_array(length_rows, length_cols);
        for (int i = 0; i < length_rows; i++)
            for (int j = 0; j < length_cols; j++)
                temp_array[i][j] = matrix[i][j]++;
        return temp_array;
    }

    Matrix& operator -- () {
        for (int i = 0; i < length_rows; i++) {
            for (int j = 0; j < length_cols; j++) {
                matrix[i][j]--;
            }
        }
        return *this;
    }
    Matrix& operator -- (int) {
        Matrix temp_array(length_rows, length_cols);
        for (int i = 0; i < length_rows; i++) {
            for (int j = 0; j < length_cols; j++) {
                temp_array[i][j] = matrix[i][j]--;
            }
        }
        return temp_array;
    }
};