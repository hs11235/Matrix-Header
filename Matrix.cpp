#include "Matrix.h"
//#include <vector>

template <class T>
int Matrix<T>::getRow() const {
    return rows;
}

template <class T>
int Matrix<T>::getCol() const {
    return columns;
}

template <class T>
void Matrix<T>::setElement(T n, int i, int j) {
    M[columns * j + i] = n;
}

template <class T>
T Matrix<T>::getElement(int i, int j) const {
    return M[columns * j + i];
}

template <class T>
void Matrix<T>::print() const {
    for (int j=0; j<rows; j++) {
        std::cout << " | ";
        for (int i=0; i<columns; i++) {
            std::cout << M[columns * j + i] << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template <class T>
Matrix<T> Matrix<T>::operator+ (const Matrix& A) {

    Matrix<T> temp(std::max(rows, A.getRow()), std::max(columns, A.getCol()));

    for (int j=0; j<std::min(rows, A.getRow()); j++) {
        for (int i=0; i<std::min(columns, A.getCol()); i++) {
            temp.setElement(M[j * columns + i] + A.getElement(i,j), i, j);
        }
        for (int i=std::min(columns, A.getCol()); i<std::max(columns, A.getCol()); i++) {
            columns > A.getCol() ? temp.setElement(M[j * columns + i], i, j) : temp.setElement(A.getElement(i,j), i, j);
        }
    }


    for (int j=std::min(rows, A.getRow()); j<std::max(rows, A.getRow()); j++) {
        if (rows > A.getRow()) {
            for (int i=0; i<columns; i++) {
                temp.setElement(M[j * columns + i], i, j);
            }
        } else if (A.getRow() > rows) {
            for (int i=0; i<A.getCol(); i++) {
                temp.setElement(A.getElement(i,j), i, j);
            }
        }
    }

    return temp;
}

template <class T>
Matrix<T> Matrix<T>::operator- (const Matrix& A) {

    Matrix<T> temp(std::max(rows, A.getRow()), std::max(columns, A.getCol()));

    for (int j=0; j<std::min(rows, A.getRow()); j++) {
        for (int i=0; i<std::min(columns, A.getCol()); i++) {
            temp.setElement(M[j * columns + i] - A.getElement(i,j), i, j);
        }
        for (int i=std::min(columns, A.getCol()); i<std::max(columns, A.getCol()); i++) {
            columns > A.getCol() ? temp.setElement(M[j * columns + i], i, j) : temp.setElement(-A.getElement(i,j), i, j);
        }
    }

    for (int j=std::min(rows, A.getRow()); j<std::max(rows, A.getRow()); j++) {
        if (rows > A.getRow()) {
            for (int i=0; i<columns; i++) {
                temp.setElement(M[j * columns + i], i, j);
            }
        } else if (A.getRow() > rows) {
            for (int i=0; i<A.getCol(); i++) {
                temp.setElement(-A.getElement(i,j), i, j);
            }
        }
    }

    return temp;
}

template <class T>
Matrix<T> Matrix<T>::operator* (const Matrix& A) {
    if (columns != A.getRow()) {
        std::cout << "Invalid dimensions for Matrix Multiplication, subject unchanged by * operator." << std::endl;
        return *this;
    }

    Matrix<T> temp(rows, A.getCol());

    for (int j=0; j<rows; j++) {
        for (int i=0; i<A.getCol(); i++) {
            T input = 0;
            for (int k=0; k<columns; k++) {
                input += M[columns * j + k] * A.getElement(i, k);
            }
            temp.setElement(input, i, j);
        }
    }
    return temp;
}
