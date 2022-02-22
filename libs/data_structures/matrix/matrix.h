#ifndef INC_4E_MATRIX_H
#define INC_4E_MATRIX_H

#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

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

long long getSum(int *array, int size);

long long getMaxInRow(int *row, int nElements);

long long getMinInCol(int *col, int nElements);

int getMaxInColPos(int *col, int nElements);

matrix mulMatrices(matrix m1, matrix m2);

float getDistance(int *a, int n);

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int));

void insertionSortRowsMatrixByRowCriteria(matrix m, long long (*criteria)(int *, int));

void selectionSortColsMatrixByColCriteria(matrix m, long long (*criteria)(int *, int));

bool isSquareMatrix(matrix m);

bool isTwoMatricesAreEqual(matrix m1, matrix m2);

bool isEMatrix(matrix m);

bool isSymmetricMatrix(matrix m);

bool isUnique(long long *array, int size);

void transposeSquareMatrix(matrix m);

position getMinValuePos(matrix m);

position getMaxValuePos(matrix m);

matrix createMatrixFromArray(const int *, int nRows, int nCols);

matrix *createArrayOfMatrixFromArray(const int *values, int nMatrices,
                                     int nRows, int nCols);

#endif
