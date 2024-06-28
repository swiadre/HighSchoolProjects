#include "matrix.h"
#include <iostream>


// konstruktory
Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    data.resize(rows, std::vector<double>(cols, 0));
}

// konstruktor kopiujacy
Matrix::Matrix(const Matrix& other) {
    rows = other.rows;
    cols = other.cols;
    data = other.data;
}

// destruktor
Matrix::~Matrix() = default;

// dane
int Matrix::get_rows() const{
    return rows;
}

int Matrix::get_cols() const{
    return cols;
}

void Matrix::set_value(int row, int col, double value) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        data[row][col] = value;
    } else {
        std::cout << "Indeks poza zakresem" << std::endl;
    }
}

// transpozycja
Matrix Matrix::transpozycja() const {
    Matrix trans(cols, rows);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            trans.data[j][i] = data[i][j];
    return trans;
}

// dodawanie
Matrix operator+(const Matrix& a, const Matrix& b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        std::cout << "Aby dalo sie dodac macierze musza byc takich samych rozmiarow" << std::endl;
        return Matrix(0, 0);
    }

    Matrix wynik(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++)
        for (int j = 0; j < a.cols; j++)
            wynik.data[i][j] = a.data[i][j] + b.data[i][j];
    return wynik;
}


// wyznacznik metoda laplace'a
Matrix getMinor(const Matrix& matrix, int skipRow, int skipCol) {
    int rows = matrix.get_rows();
    int cols = matrix.get_cols();
    Matrix minor(rows - 1, cols - 1);

    for (int i = 0, mi = 0; i < rows; i++) {
        if (i == skipRow) continue;
        for (int j = 0, mj = 0; j < cols; j++) {
            if (j == skipCol) continue;
            minor.data[mi][mj] = matrix.get_data(i, j);
            mj++;
        }
        mi++;
    }
    return minor;
}

double Matrix::wyznacznik(const Matrix &matrix) {
    int rows = matrix.get_rows();
    int cols = matrix.get_cols();

    if (rows != cols) {
        std::cout << "Wyznacznik macierzy mozna policzyc tylko dla macierzy kwadratowych" << std::endl;
        return -1.79769E+308;
    }

    if (rows == 1) {
        return matrix.get_data(0, 0);
    }

    if (rows == 2) {
        return matrix.get_data(0, 0) * matrix.get_data(1, 1) - matrix.get_data(0, 1) * matrix.get_data(1, 0);
    }

    double det = 0;
    for (int j = 0; j < cols; j++) {
        Matrix minor = getMinor(matrix, 0, j);
        det += (j % 2 == 0 ? 1 : -1) * matrix.get_data(0, j) * wyznacznik(minor);
    }
    return det;
}

// mnozenie macierzy
Matrix operator*(const Matrix& a, const Matrix& b) {
    if (a.cols != b.rows) {
        std::cout << "Wymiary macierzy sa nieprawidlowe do wymnozenie ich" << std::endl;
        return {0, 0};
    }

    Matrix wynik(a.rows, b.cols);
    for (int i = 0; i < wynik.rows; i++) {
        for (int j = 0; j < wynik.cols; j++) {
            wynik.data[i][j] = 0;
            for (int k = 0; k < a.cols; ++k) {
                wynik.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }

    return wynik;
}


// mnozenie przez skalar
Matrix operator*(const Matrix& a, double skalar) {
    Matrix result(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++)
        for (int j = 0; j < a.cols; j++)
            result.data[i][j] = a.data[i][j] * skalar;
    return result;
}

// operator wyjscia
std::ostream& operator<<(std::ostream& out, const Matrix& matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            out << matrix.data[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}

// operator wejscia
std::istream& operator>>(std::istream& in, Matrix& matrix) {
    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.cols; j++)
            in >> matrix.data[i][j];
    return in;
}
