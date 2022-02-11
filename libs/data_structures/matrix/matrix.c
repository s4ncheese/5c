#include "matrix.h"
#include <malloc.h>
#include <stdio.h>

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
            scanf("%d", &m.values[rowInd][colInd]);
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