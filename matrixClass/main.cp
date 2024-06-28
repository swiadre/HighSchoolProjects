#include "matrix.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));

    int rows1 = 3, cols1 = 3;
    int rows2 = 3, cols2 = 3;

    // inicjalizacja macierzy losowych
    Matrix mat1(rows1, cols1);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            mat1.set_value(i, j, (double)(rand() % 10));
        }
    }

    Matrix mat2(rows2, cols2);
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            mat2.set_value(i, j, (double)(rand() % 10));
        }
    }

    // wypisujemy macierze
    std::cout << "Macierz 1:\n" << mat1 << std::endl;
    std::cout << "Macierz 2:\n" << mat2 << std::endl;

    // suma macierzy
    std::cout << "Suma macierzy:\n";
    Matrix sum = mat1 + mat2;
    std::cout << sum << std::endl;

    // mnozenie prez losowy skalar 2-5
    auto scalar = (double)((rand() % 3)+1);
    Matrix iloczyn1 = mat1 * scalar;
    std::cout << "Macierz 1 pomnozona przez " << scalar << ":\n" << iloczyn1 << std::endl;

    // transpozycja
    Matrix trans = mat1.transpozycja();
    std::cout << "Transpozycja macierzy 1:\n" << trans << std::endl;

    // iloczyn macierzy
    std::cout << "Iloczyn macierzy:\n";
    Matrix iloczyn2 = mat1 * mat2;
    std::cout << iloczyn2 << std::endl;


    // wyznacznik maciery
    std::cout << "Wyznacznik macierzy 1: " << std::endl;
    double wyzn = Matrix::wyznacznik(mat1);
    if(wyzn != -1.79769E+308)
        std::cout << wyzn << std::endl;
    else


    return 0;
}
