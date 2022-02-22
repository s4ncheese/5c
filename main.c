#include "libs\data_structures\vectors\vector.h"
#include "libs\data_structures\matrix\matrix.h"
#include "libs\algorithms\array\array.h"
#include <assert.h>
#include <stdio.h>

void test_swapRows_firstAndSecond() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    swapRows(m, 0, 1);
    matrix expectedMatrix = createMatrixFromArray((int[]) {4, 5, 6,
                                                           1, 2, 3,
                                                           7, 8, 9}, 3, 3);
    bool isEqual = true;
    for (int rowInd = 0; rowInd < m.nRows; rowInd++) {
        for (int colInd = 0; colInd < m.nCols; colInd++) {
            if (m.values[rowInd][colInd] != expectedMatrix.values[rowInd][colInd])
                isEqual = false;

            assert(isEqual == true);
        }
    }

    freeMemMatrix(m);
    freeMemMatrix(expectedMatrix);
}

void test_swapRows_firstAndThird() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    swapRows(m, 1, 2);
    matrix expectedMatrix = createMatrixFromArray((int[]) {7, 8, 9,
                                                           4, 5, 6,
                                                           1, 2, 3}, 3, 3);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            if (m.values[i][j] == expectedMatrix.values[i][j])
                isEqual = true;
            else
                isEqual = false;
            assert(isEqual == 0);
        }
    }


    freeMemMatrix(m);
    freeMemMatrix(expectedMatrix);
}

void test_swapColumns_firstAndSecond() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              1, 2, 3,
                                              1, 2, 3}, 3, 3);
    swapColumns(m, 0, 1);
    matrix expectedMatrix = createMatrixFromArray((int[]) {2, 1, 3,
                                                           2, 1, 3,
                                                           2, 1, 3}, 3, 3);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }

    freeMemMatrix(m);
    freeMemMatrix(expectedMatrix);
}

void test_swapCols_firstAndThird() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    swapColumns(m, 0, 2);
    matrix expectedMatrix = createMatrixFromArray((int[]) {3, 2, 1,
                                                           6, 5, 4,
                                                           9, 8, 7}, 3, 3);
    assert(m.nRows == expectedMatrix.nRows);
    assert(m.nCols == expectedMatrix.nCols);
    bool isEqual = false;
    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++) {
            isEqual = (bool) (m.values[i][j] == expectedMatrix.values[i][j]);
            assert(isEqual == true);
        }
    }

    freeMemMatrix(m);
    freeMemMatrix(expectedMatrix);
}

void test_isEMatrix() {
    matrix m =
            createMatrixFromArray((int[]) {1, 0, 0,
                                           0, 1, 0,
                                           0, 0, 1}, 3, 3);
    assert(isEMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix_symmetricVer1() {
    matrix m = createMatrixFromArray((int[]) {1, 6, 10,
                                              6, 1, 3,
                                              10, 3, 1}, 3, 3);
    assert(isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix_symmetricVer2() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              2, 4, 0,
                                              3, 0, 2}, 3, 3);

    assert(isSymmetricMatrix(m) == true);

    freeMemMatrix(m);
}

void test_isSymmetricMatrix_notSymmetric() {
    matrix m = createMatrixFromArray((int[]) {1, 6, 10,
                                              3, 1, 3,
                                              10, 3, 1}, 3, 3);
    assert(!isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_transposeSquareMatrixFirstVer() {
    matrix m = createMatrixFromArray((int[]) {1, 8, 4,
                                              10, 9, 8,
                                              3, 11, 2}, 3, 3);
    transposeSquareMatrix(m);
    matrix answerMatrix = createMatrixFromArray((int[]) {1, 10, 3,
                                                         8, 9, 11,
                                                         4, 8, 2}, 3, 3);

    assert(isTwoMatricesAreEqual(m, answerMatrix) == 1);

    freeMemMatrix(m);
    freeMemMatrix(answerMatrix);
}

void test_transposeSquareMatrixSecVer() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    transposeSquareMatrix(m);
    matrix answerMatrix = createMatrixFromArray((int[]) {1, 4, 7,
                                                         2, 5, 8,
                                                         3, 6, 9}, 3, 3);

    assert(isTwoMatricesAreEqual(m, answerMatrix) == 1);

    freeMemMatrix(m);
    freeMemMatrix(answerMatrix);
}

void test_getMinValuePosFirstVer() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    position expectedMinPos = (position) {0, 0};
    position minPos = getMinValuePos(m);
    assert(minPos.rowIndex == expectedMinPos.rowIndex);
    assert(minPos.colIndex == expectedMinPos.colIndex);

    freeMemMatrix(m);
}

void test_getMinValuePosSecVer() {
    matrix m = createMatrixFromArray((int[]) {12, 4, 0,
                                              32, -1, 11,
                                              7, 4, -1}, 3, 3);
    position expectedMinPos = (position) {1, 1};
    position minPos = getMinValuePos(m);
    assert(minPos.rowIndex == expectedMinPos.rowIndex);
    assert(minPos.colIndex == expectedMinPos.colIndex);

    freeMemMatrix(m);
}

void test_getMaxValuePosFirstVer() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    position expectedMaxPos = (position) {2, 2};
    position maxPos = getMaxValuePos(m);
    assert(maxPos.rowIndex == expectedMaxPos.rowIndex);
    assert(maxPos.colIndex == expectedMaxPos.colIndex);

    freeMemMatrix(m);
}

void test_getMaxValuePosSecVer() {
    matrix m = createMatrixFromArray((int[]) {-45, -99, -3,
                                              -5, -7, 0,
                                              -11, -2, 0}, 3, 3);
    position expectedMaxPos = (position) {1, 2};
    position maxPos = getMaxValuePos(m);
    assert(maxPos.rowIndex == expectedMaxPos.rowIndex);
    assert(maxPos.colIndex == expectedMaxPos.colIndex);

    freeMemMatrix(m);
}

void test_insertionSortRows_firstVer() {
    matrix m = createMatrixFromArray((int[]) {7, 8, 9,
                                              4, 5, 6,
                                              1, 2, 3}, 3, 3);
    insertionSortRowsMatrixByRowCriteria(m, getSum);

    matrix answerM = createMatrixFromArray((int[]) {1, 2, 3,
                                                    4, 5, 6,
                                                    7, 8, 9}, 3, 3);

    assert(isTwoMatricesAreEqual(m, answerM) == true);

    freeMemMatrix(m);
    freeMemMatrix(answerM);
}

void test_insertionSortRows_secVer() {
    matrix m = createMatrixFromArray((int[]) {-1, 3, 45,
                                              0, 9, 2,
                                              5, 7, -11}, 3, 3);

    insertionSortRowsMatrixByRowCriteria(m, getSum);

    matrix answerM = createMatrixFromArray((int[]) {5, 7, -11,
                                                    0, 9, 2,
                                                    -1, 3, 45}, 3, 3);

    assert(isTwoMatricesAreEqual(m, answerM));

    freeMemMatrix(m);
    freeMemMatrix(answerM);
}

void test_selectionSortCols_firstVer() {
    matrix m = createMatrixFromArray((int[]) {1, 3, 2,
                                              4, 6, 5,
                                              7, 9, 8}, 3, 3);

    selectionSortColsMatrixByColCriteria(m, getSum);

    matrix answerM = createMatrixFromArray((int[]) {1, 2, 3,
                                                    4, 5, 6,
                                                    7, 8, 9}, 3, 3);

    assert(isTwoMatricesAreEqual(m, answerM));

    freeMemMatrix(m);
    freeMemMatrix(answerM);
}

void test_selectionSortCols_secVer() {
    matrix m = createMatrixFromArray((int[]) {-1, 8, 14,
                                              0, 2, 5,
                                              42, 51, -4}, 3, 3);

    selectionSortColsMatrixByColCriteria(m, getSum);

    matrix answerM = createMatrixFromArray((int[]) {14, -1, 8,
                                                    5, 0, 2,
                                                    -4, 42, 51}, 3, 3);

    assert(isTwoMatricesAreEqual(m, answerM));

    freeMemMatrix(m);
    freeMemMatrix(answerM);
}

void test_swapRows() {
    test_swapRows_firstAndSecond();
    test_swapRows_firstAndThird();
}

void test_swapCols() {
    test_swapColumns_firstAndSecond();
    test_swapCols_firstAndThird();
}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix_symmetricVer1();
    test_isSymmetricMatrix_notSymmetric();
}

void test_transpose() {
    test_transposeSquareMatrixFirstVer();
    test_transposeSquareMatrixSecVer();
}

void test_getMinPos() {
    test_getMinValuePosFirstVer();
    test_getMinValuePosSecVer();
}

void test_getMaxPos() {
    test_getMaxValuePosFirstVer();
    test_getMaxValuePosSecVer();
}

void test_insertionSortRows() {
    test_insertionSortRows_firstVer();
    test_insertionSortRows_secVer();
}

void test_selectionSortCols() {
    test_selectionSortCols_firstVer();
    test_selectionSortCols_secVer();
}

void test() {
    test_swapRows();
    test_swapCols();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transpose();
    test_getMinPos();
    test_getMaxPos();
    test_insertionSortRows();
    test_selectionSortCols();
}

void firstTask(matrix m) {
    position maxPos = getMaxValuePos(m);
    position minPos = getMinValuePos(m);
    swapRows(m, maxPos.rowIndex, minPos.rowIndex);
}

void secondTask(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMaxInRow);
}

void thirdTask(matrix m) {
    selectionSortColsMatrixByColCriteria(m, getMinInCol);
}

void fourthTask(matrix *m) {
    if (isSymmetricMatrix(*m)) {
        *m = mulMatrices(*m, *m);
    }
}

void fifthTask(matrix m) {
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

bool sixthTask(matrix m1, matrix m2) {
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

void swapPenultimateRow(matrix m, int n) {
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

int main() {
    test();

    int nRows, nCols;
    scanf("%d %d", &nRows, &nCols);

    matrix m = getMemMatrix(nRows, nCols);
    inputMatrix(m);

    swapPenultimateRow(m, m.nRows);

    outputMatrix(m);

    return 0;
}
