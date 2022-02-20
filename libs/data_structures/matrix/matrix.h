#ifndef INC_4E_MATRIX_H
#define INC_4E_MATRIX_H

#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix {
    int **values;
    int nRows;
    int nCols;
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

void freeMemMatrix(matrix m);

void freeMemMatrices(matrix *mArray, int nMatrices);

void inputMatrix(matrix m);

void inputMatrices(matrix *mArray, int nMatrix);

void outputMatrix(matrix m);

void swapRows(matrix m, int row1, int row2);

void swapColumns(matrix m, int col1, int col2);

int getSum(int *array, int size);

int getMaxInRow(int *row, int nElements);

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int));

void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int));

bool isSquareMatrix(matrix m);

bool isTwoMatricesAreEqual(matrix m1, matrix m2);

bool isEMatrix(matrix m);

bool isSymmetricMatrix(matrix m);

void transposeSquareMatrix(matrix m);

position getMinValuePos(matrix m);

position getMaxValuePos(matrix m);

matrix createMatrixFromArray(const int *, int nRows, int nCols);

matrix *createArrayOfMatrixFromArray(const int *values, int nMatrices,
                                     int nRows, int nCols);

#endif
