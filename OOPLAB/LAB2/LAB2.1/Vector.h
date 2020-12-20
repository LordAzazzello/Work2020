#pragma once
class Vector
{
private:
    int length;
    float* vector;

public:
    Vector(int length) {
        vector = new float[length];
        length = length;
    }
    ~Vector() {//деструктор
        delete[] vector;
    }

    int GetLength() {
        return length;
    }

    float& operator [] (int index) {
        return vector[index];
    }

    Vector& operator ++ () {
        for (int i = 0; i < length; i++) {
            vector[i]++;
        }
        return *this;
    }
    Vector& operator ++ (int) {
        Vector temp_array(length);
        for (int i = 0; i < length; i++) {
            temp_array[i] = vector[i]++;
        }
        return temp_array;
    }

    Vector& operator -- () {
        for (int i = 0; i < length; i++) {
            vector[i]--;
        }
        return *this;
    }
    Vector& operator -- (int) {
        Vector temp_array(length);
        for (int i = 0; i < length; i++) {
            temp_array[i] = vector[i]--;
        }
        return temp_array;
    }
};
