#include "matrix.h"
#include "tasks.h"
#include "..\..\algorithms\array\array.h"

void swapMaxMinRows(matrix m) {
    position maxPos = getMaxValuePos(m);
    position minPos = getMinValuePos(m);
    swapRows(m, maxPos.rowIndex, minPos.rowIndex);
}

void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMaxInRow);
}

void sortColsByMinElement(matrix m) {
    selectionSortColsMatrixByColCriteria(m, getMinInCol);
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m)) {
        *m = mulMatrices(*m, *m);
    }
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    if (m.nRows != m.nCols) {
        fprintf(stderr, "Is not square matrix");
        exit(1);
    }

    long long *sumArray = (long long *) malloc(sizeof(long long) * m.nRows);
    for (int rowInd = 0; rowInd < m.nRows; rowInd++)
        sumArray[rowInd] = getSum(m.values[rowInd], m.nCols);

    if (isUnique(sumArray, m.nRows))
        transposeSquareMatrix(m);

}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;

    return isEMatrix(mulMatrices(m1, m2));
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    size_t size = m.nRows + m.nCols - 1;
    int arrayOfMaxesOfPseudoDiagonals[size];
    for (int i = 0; i < size; i++)
        arrayOfMaxesOfPseudoDiagonals[i] = 0;

    for (int rowInd = 0; rowInd < m.nRows; rowInd++)
        for (int colInd = 0; colInd < m.nCols; colInd++) {
            if (rowInd != colInd) {
                int pseudoDiagonalNumber = colInd - rowInd + 2;
                arrayOfMaxesOfPseudoDiagonals[pseudoDiagonalNumber] =
                        max2_(arrayOfMaxesOfPseudoDiagonals[pseudoDiagonalNumber],
                              m.values[rowInd][colInd]);
            }
        }

    return getSum(arrayOfMaxesOfPseudoDiagonals, size);
}

int getMinInArea(matrix m) {
    position maxPos = getMaxValuePos(m);
    int min = m.values[maxPos.rowIndex][maxPos.colIndex];
    int col = maxPos.colIndex;
    int row = maxPos.rowIndex;
    for (int rowInd = maxPos.rowIndex - 1; rowInd >= 0; rowInd--) {
        if (col - 1 >= 0)
            col--;
        if (row + 1 < m.nCols)
            row++;
        int noFantasy = row;
        while (noFantasy >= col) {
            min = min2_(min, m.values[rowInd][noFantasy]);
            noFantasy--;
        }
    }

    return min;
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

int countEqClassesByRowsSum(matrix m) {
    long long rowsSum[m.nRows];
    for (int rowInd = 0; rowInd < m.nRows; rowInd++)
        rowsSum[rowInd] = getSum(m.values[rowInd], m.nCols);

    return countNUnique(rowsSum, m.nRows);
}

int getNSpecialElements(matrix m) {
    int amountOfSpecials = 0;
    for (int colInd = 0; colInd < m.nCols; colInd++) {
        int specialEl = m.values[0][colInd];
        int sumOfColElements = 0;
        for (int rowInd = 1; rowInd < m.nRows; rowInd++) {
            if (m.values[rowInd][colInd] > specialEl) {
                sumOfColElements += specialEl;
                specialEl = m.values[rowInd][colInd];
            } else
                sumOfColElements += m.values[rowInd][colInd];
        }
        if (specialEl > sumOfColElements)
            amountOfSpecials++;
    }

    return amountOfSpecials;

}

position getLeftMin(matrix m) {
    return (position) getMinValuePos(m);
}

void swapPenultimateRow(matrix m) {
    if (m.nRows < 2) {
        fprintf(stderr, "It is impossible to swap");
        exit(1);
    }

    int col[m.nRows];
    position minPos = getLeftMin(m);
    for (int rowInd = 0; rowInd < m.nRows; rowInd++)
        col[rowInd] = m.values[rowInd][minPos.colIndex];

    memcpy(m.values[m.nRows - 2], col, m.nCols * sizeof(int));
}

bool isNonDescendingSorted(int *array, int size) {
    for (int elementInd = 0; elementInd < size - 1; elementInd++)
        if (array[elementInd] > array[elementInd + 1])
            return false;

    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int rowInd = 0; rowInd < m.nRows; rowInd++)
        if (!isNonDescendingSorted(m.values[rowInd], m.nCols))
            return false;

    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrices) {
    int countMatricesNonDescendingRows = 0;
    for (int matrixInd = 0; matrixInd < nMatrices; matrixInd++)
        if (hasAllNonDescendingRows(ms[matrixInd]))
            countMatricesNonDescendingRows++;

    return countMatricesNonDescendingRows;
}

int countValues(const int *array, int size, const int value) {
    int amountOfValues = 0;
    for (int el = 0; el < size; el++)
        if (array[el] == value)
            amountOfValues++;

    return amountOfValues;
}

int countZeroRows(matrix m) {
    int amountOfZeroRows = 0;
    for (int rowInd = 0; rowInd < m.nRows; rowInd++) {
        amountOfZeroRows += countValues(m.values[rowInd],
                                        m.nCols, 0) == m.nCols;
    }

    return amountOfZeroRows;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrices) {
    int amountOfZeroRowsMatrices[nMatrices];
    for (int mInd = 0; mInd < nMatrices; mInd++)
        amountOfZeroRowsMatrices[mInd] = countZeroRows(ms[mInd]);

    int max = getMax(amountOfZeroRowsMatrices, nMatrices);

    for (int i = 0; i < nMatrices; i++)
        if (amountOfZeroRowsMatrices[i] == max) {
            outputMatrix(ms[i]);
            printf("\n");
        }
}

float getNorm(fMatrix m) {
    float norm = fabs((float)m.values[0][0]);
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (fabs(m.values[i][j]) > norm)
                norm = fabs(m.values[i][j]);

    return norm;
}

void printMaxNormMatrices(fMatrix *ms, int nMatrices) {
    float arrayOfNorms[nMatrices];
    for (int mInd = 0; mInd < nMatrices; mInd++)
        arrayOfNorms[mInd] = getNorm(ms[mInd]);

    int min = getMinF(arrayOfNorms, nMatrices);
    for (int i = 0; i < nMatrices; i++)
        if (min - arrayOfNorms[i] <= F_EPS)
            outputMatrixF(ms[i]);
}