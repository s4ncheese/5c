#ifndef INC_4E_TASKS_H
#define INC_4E_TASKS_H

#include "matrix.h"
#define F_EPS 0.0000001
#include <math.h>

void swapMaxMinRows(matrix m);

void sortRowsByMaxElement(matrix m);

void sortColsByMinElement(matrix m);

void getSquareOfMatrixIfSymmetric(matrix *m);

void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

bool isMutuallyInverseMatrices(matrix m1, matrix m2);

long long findSumOfMaxesOfPseudoDiagonal(matrix m);

int getMinInArea(matrix m);

void sortByDistances(matrix m);

int countEqClassesByRowsSum(matrix m);

int getNSpecialElements(matrix m);

position getLeftMin(matrix m);

void swapPenultimateRow(matrix m);

bool isNonDescendingSorted(int *array, int size);

bool hasAllNonDescendingRows(matrix m);

int countNonDescendingRowsMatrices(matrix *ms, int nMatrices);

int countValues(const int *array, int size, const int value);

int countZeroRows(matrix m);

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrices);

float getNorm(fMatrix m);

void printMaxNormMatrices(fMatrix *ms, int nMatrices);



#endif //INC_4E_TASKS_H
