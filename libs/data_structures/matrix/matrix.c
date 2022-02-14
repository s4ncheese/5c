#include "matrix.h"
#include <malloc.h>
#include <stdio.h>
#include "../../algorithms/array/array.h"
#include<stdbool.h>

// Возвращает матрицу размером nRows на nCols, размещенную в
// динамической памяти
matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = malloc(sizeof(int) * nCols);

    return (matrix) {values, nRows, nCols};
}

// Возвращает массив из nMatrices матриц размером nRows на nCols,
// размещенный в динамической памяти
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *matrixArray = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int matrixIndex = 0; matrixIndex < nMatrices; matrixIndex++)
        matrixArray[matrixIndex] = getMemMatrix(nRows, nCols);

    return matrixArray;
}

// Освобождает память, выделенную под хранение значений матрицы m
void freeMemMatrix(matrix m) {
    for (int rowInd = 0; rowInd < m.nRows; rowInd++)
        free(m.values[rowInd]);
    free(m.values);
}

// Освобождает память, выделенную под хранение массива mArray из
// nMatrices матриц
void freeMemMatrices(matrix *mArray, int nMatrices) {
    for (int mNumber = 0; mNumber < nMatrices; mNumber++)
        freeMemMatrix((matrix) mArray[mNumber]);
}

// Ввод матрицы m
void inputMatrix(matrix m) {
    for (int rowInd = 0; rowInd < m.nRows; rowInd++)
        for (int colInd = 0; colInd < m.nCols; colInd++)
            scanf("%d", &(m.values[rowInd][colInd]));
}

// Ввод массива матриц mArray размера nMatrix
void inputMatrices(matrix *mArray, int nMatrix) {
    for (int mInd = 0; mInd < nMatrix; mInd++)
        inputMatrix(mArray[mInd]);
}

// Вывод матрицы m
void outputMatrix(matrix m) {
    for (int rowInd = 0; rowInd < m.nRows; rowInd++) {
        for (int colInd = 0; colInd < m.nCols; colInd++)
            printf("%d ", m.values[rowInd][colInd]);

        printf("\n");
    }
}

// Вывод массива матриц mArray размера nMatrix
void outputMatrices(matrix *mArray, int nMatrix) {
    for (int mInd = 0; mInd < nMatrix; mInd++) {
        outputMatrix(mArray[mInd]);
        printf("/n");
    }
}

// Обмен строк с порядковыми номерами row1 и row2 в матрице m
void swapRows(matrix m, int row1, int row2) {
    int *t = m.values[row1];
    m.values[row1] = m.values[row2];
    m.values[row2] = t;
}

// Обмен колонок с порядковыми номерами col1 и col2 в матрице m
void swapColumns(matrix m, int col1, int col2) {
    for (int rowInd = 0; rowInd < m.nRows; rowInd++)
        swap_(&m.values[rowInd][col1], &m.values[rowInd][col2]);
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {

}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {

}

// Возвращает значение истина, если матрица m является квадратной,
// иначе - ложь
bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

// Возвращает значение истина, если матрицы m1 и m2 равны,
// иначе - ложь
bool isTwoMatricesAreEqual(matrix m1, matrix m2) {
    long long nElementsFirstMatrix = (long long) m1.nRows * m1.nCols;
    long long nElementsSecMatrix = (long long) m2.nRows * m2.nCols;
    if (nElementsFirstMatrix != nElementsSecMatrix) return 0;
    for (int rowInd = 0; rowInd < m1.nRows; rowInd++)
        for (int colInd = 0; colInd < m1.nCols; colInd++)
            if (m1.values[rowInd][colInd] != m2.values[rowInd][colInd])
                return false;

    return true;
}

// Возвращает значение истина, если матрица m единичная, иначе ложь
bool isEMatrix(matrix m) {
    for (int rowInd = 0; rowInd < m.nRows; rowInd++)
        for (int colInd = 0; colInd < m.nCols; colInd++) {
            if (rowInd == colInd) {
                if (m.values[rowInd][colInd] != 1) return false;
            }
            else if (m.values[rowInd][colInd] != 0)
                return false;
        }

    return true;
}

// Возвращает значение истина, если матрица m является симметричной,
// иначе - ложь
bool isSymmetricMatrix(matrix m) {
    int diagonalEl = m.values[0][0];
    for (int rowInd = 0, colInd = 0; rowInd < m.nRows && colInd < m.nCols;
        rowInd++, colInd++) {

        if (rowInd == colInd && m.values[rowInd][colInd] != diagonalEl ||
                m.values[rowInd][colInd] != m.values[colInd][rowInd])
            return false;
    }

    return true;
}