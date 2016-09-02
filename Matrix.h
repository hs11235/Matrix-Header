#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <vector>
#include <iostream>
#include <cmath>

template <class T>
class Matrix {
private:
    std::vector<T> M;
    int rows;
    int columns;
public:
    Matrix(int r, int c): rows(r), columns(c){
        M.resize(rows*columns);
    }
    // add further constructors
    int getRow() const;
    int getCol() const;
    void setElement(T n, int i, int j);
    T getElement(int i, int j) const;
    void print() const;

    Matrix operator+ (const Matrix& A);
    Matrix operator- (const Matrix& A);
    Matrix operator* (const Matrix& A);
};

#endif // MATRIX_H_INCLUDED
