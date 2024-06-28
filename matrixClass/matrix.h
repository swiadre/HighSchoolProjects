#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

// clasa Matrix
class Matrix {
// dane prywatne
private:
    int rows, cols;

public:
    // konstruktory
    Matrix(int rows, int cols);
    Matrix(const Matrix& other);
    // destruktor
    ~Matrix();

    // get valie i get data
    void set_value(int row, int col, double value);

    double get_data(int row, int col) const {
        return data[row][col];
    }

    int get_cols() const;
    int get_rows() const;

    // transpozycja
    Matrix transpozycja() const;

    // wyznaczanie wyznacznika metoda laplace'a
    static double wyznacznik(const Matrix& matrix);

    // operatory
    friend Matrix operator+(const Matrix& a, const Matrix& b);
    friend Matrix operator*(const Matrix& a, const Matrix& b);
    friend Matrix operator*(const Matrix& a, double skalar);
    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
    friend std::istream& operator>>(std::istream& in, Matrix& matrix);

    // dane
    std::vector<std::vector<double>> data;


};

#endif
