#include <assert.h>
#include <stdbool.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/data_structures/matrix/tasks.h"

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
    test_isSymmetricMatrix_symmetricVer2();
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

void functionsTest() {
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

void test_swapMaxMinRows_firstSecondRows() {
    matrix m = createMatrixFromArray((int[]) {999, 12, 11,
                                              0, 1, 2,
                                              3, 4, 5}, 3, 3);

    swapMaxMinRows(m);

    matrix m1 = createMatrixFromArray((int[]) {0, 1, 2,
                                               999, 12, 11,
                                               3, 4, 5}, 3, 3);

    assert(isTwoMatricesAreEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_swapMaxMinRows_firstThirdRows() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);

    swapMaxMinRows(m);

    matrix m1 = createMatrixFromArray((int[]) {7, 8, 9,
                                               4, 5, 6,
                                               1, 2, 3}, 3, 3);

    assert(isTwoMatricesAreEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_sortRowsByMaxElement_ver1() {
    matrix m = createMatrixFromArray((int[]) {7, 9, 8,
                                              3, 2, 1,
                                              5, 4, 6}, 3, 3);

    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);

    sortRowsByMaxElement(m);

    assert(isTwoMatricesAreEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_sortRowsByMaxElement_ver2() {
    matrix m = createMatrixFromArray((int[]) {-1, 2, 5,
                                              0, 1, 5,
                                              2, 3, 3}, 3, 3);

    matrix m1 = createMatrixFromArray((int[]) {2, 3, 3,
                                               -1, 2, 5,
                                               0, 1, 5}, 3, 3);

    sortRowsByMaxElement(m);

    assert(isTwoMatricesAreEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_sortColsByMinElement_firstSecondThirdCols() {
    matrix m = createMatrixFromArray((int[]) {3, 1, 2,
                                              6, 4, 5,
                                              9, 7, 8}, 3, 3);

    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);

    sortColsByMinElement(m);

    assert(isTwoMatricesAreEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_sortColsByMinElement_firstThirdCols() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 1,
                                              6, 5, 4,
                                              9, 8 ,7}, 3, 3);

    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);

    sortColsByMinElement(m);

    assert(isTwoMatricesAreEqual(m, m1));

    freeMemMatrix(m);
    freeMemMatrix(m1);
}

void test_swapMaxMinRows() {
    test_swapMaxMinRows_firstSecondRows();
    test_swapMaxMinRows_firstThirdRows();
}

void test_sortRowsByMaxElement() {
    test_sortRowsByMaxElement_ver1();
    test_sortRowsByMaxElement_ver2();
}

void test_sortColsByMinElement() {
    test_sortColsByMinElement_firstSecondThirdCols();
    test_sortColsByMinElement_firstThirdCols();
}

void test_getSquareOfMatrixIfSymmetric_symmetric() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 2,
                                              1, 8, 17,
                                              2, 17, 3}, 3, 3);
    getSquareOfMatrixIfSymmetric(&m);
    matrix expectedMatrix = createMatrixFromArray((int[]) {54, 49, 37,
                                                           49, 354, 189,
                                                           37, 189, 302}, 3, 3);

    assert(isTwoMatricesAreEqual(m, expectedMatrix));
}

void test_getSquareOfMatrixIfSymmetric_NotSymmetric() {
    matrix m = createMatrixFromArray((int[]) {7, 3, 2,
                                              1, 8, 17,
                                              8, 17, 3}, 3, 3);
    getSquareOfMatrixIfSymmetric(&m);
    matrix expectedMatrix = createMatrixFromArray((int[]) {7, 3, 2,
                                                           1, 8, 17,
                                                           8, 17, 3}, 3, 3);

    assert(isTwoMatricesAreEqual(m, expectedMatrix));
}

void test_getSquareOfMatrixIfSymmetric() {
    test_getSquareOfMatrixIfSymmetric_symmetric();
    test_getSquareOfMatrixIfSymmetric_NotSymmetric();
}

void test_transposeIfMatrixHasNotEqualSumOfRows_noEqual() {
    matrix m = createMatrixFromArray((int[]) {2, 13, 4,
                                              1, 8, 17,
                                              23, 47, 3}, 3, 3);
    transposeIfMatrixHasNotEqualSumOfRows(m);
    matrix expectedMatrix = createMatrixFromArray((int[]) {2, 1, 23,
                                                           13, 8, 47,
                                                           4, 17, 3}, 3, 3);

    assert(isTwoMatricesAreEqual(m, expectedMatrix));
}

void test_transposeIfMatrixHasNotEqualSumOfRows_equal() {
    matrix m = createMatrixFromArray((int[]) {10, 13, 3,
                                              1, 8, 17,
                                              23, 47, 3}, 3, 3);
    transposeIfMatrixHasNotEqualSumOfRows(m);
    matrix expectedMatrix = createMatrixFromArray((int[]) {10, 13, 3,
                                                           1, 8, 17,
                                                           23, 47, 3}, 3, 3);

    assert(isTwoMatricesAreEqual(m, expectedMatrix));
}

void test_transposeIfMatrixHasNotEqualSumOfRows() {
    test_transposeIfMatrixHasNotEqualSumOfRows_noEqual();
    test_transposeIfMatrixHasNotEqualSumOfRows_equal();
}

void test_isMutuallyInverseMatrices_isEMatrix() {
    matrix m1 = createMatrixFromArray((int[]) {2, 5, 7,
                                               6, 3, 4,
                                               5, -2, -3}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {1, -1, 1,
                                               -38, 41, -34,
                                               27, -29, 24}, 3, 3);

    assert(isMutuallyInverseMatrices(m1, m2) == true);
}

void test_isMutuallyInverseMatrices_IsNotEMatrix() {
    matrix m1 = createMatrixFromArray((int[]) {2, 5, 7,
                                               6, 3, 4,
                                               5, -2, -3}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {1, 4, 1,
                                               -38, 35, -34,
                                               27, -27, 24}, 3, 3);

    assert(isMutuallyInverseMatrices(m1, m2) == false);
}

void test_isMutuallyInverseMatrices() {
    test_isMutuallyInverseMatrices_isEMatrix();
    test_isMutuallyInverseMatrices_IsNotEMatrix();
}

void test_findSumOfMaxesOfPseudoDiagonal() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4,
                                              1, 3, 6, 3,
                                              3, 2, 1, 2}, 3, 4);
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 20);
}

void test_getMinInArea_ver1() {
    matrix m = createMatrixFromArray((int[]) {6, 8, 9, 2,
                                              7, 12, 3, 4,
                                              10, 11, 5, 1}, 3, 4);

    assert(getMinInArea(m) == 6);
}

void test_getMinInArea_oneElementInArea() {
    matrix m = createMatrixFromArray((int[]) {17, 7, 5, 6,
                                              3, 11, 8, 9,
                                              4, 1, 12, 2}, 3, 4);

    assert(getMinInArea(m) == 17);
}

void test_getMinInArea() {
    test_getMinInArea_ver1();
    test_getMinInArea_oneElementInArea();
}

void test_sortByDistances() {
    matrix m = createMatrixFromArray((int[]) {17, 7, 5, 6,
                                              3, 11, 8, 9,
                                              4, 1, 12, 2}, 3, 4);
    sortByDistances(m);
    matrix expectedMatrix = createMatrixFromArray((int[]) {4, 1, 12, 2,
                                                           3, 11, 8, 9,
                                                           17, 7, 5, 6}, 3, 4);
    assert(isTwoMatricesAreEqual(m, expectedMatrix));

}

void test_countEqClassesByRowsSum_() {
    matrix m = createMatrixFromArray((int[]) {7, 1,
                                              2, 7,
                                              5, 4,
                                              4, 3,
                                              1, 6,
                                              8, 0}, 6, 2);

    assert(countEqClassesByRowsSum(m) == 3);

}

void test_countEqClassesByRowsSum_allSumsAreEqual() {
    matrix m = createMatrixFromArray((int[]) {7, 1,
                                              3, 5,
                                              4, 4,
                                              2, 6,
                                              1, 7,
                                              8, 0}, 6, 2);

    assert(countEqClassesByRowsSum(m) == 1);

}

void test_countEqClassesByRowsSum() {
    test_countEqClassesByRowsSum_();
    test_countEqClassesByRowsSum_allSumsAreEqual();
}

void test_getNSpecialElements_thereElements() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 5, 4,
                                              2, 3, 6, 7,
                                              12, 2, 1, 2}, 3, 4);

    assert(getNSpecialElements(m) == 2);

}

void test_getNSpecialElements_zeroSpecialElements() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 5, 5,
                                              2, 3, 6, 7,
                                              4, 2, 1, 2}, 3, 4);

    assert(getNSpecialElements(m) == 0);

}

void test_getNSpecialElements() {
    test_getNSpecialElements_thereElements();
    test_getNSpecialElements_zeroSpecialElements();
}

void test_swapPenultimateRow() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 1}, 3, 3);
    swapPenultimateRow(m);
    matrix expectedMatrix = createMatrixFromArray((int[]) {1, 2, 3,
                                                           1, 4, 7,
                                                           7, 8, 1}, 3, 3);
    assert(isTwoMatricesAreEqual(m, expectedMatrix));

}

void test_countNonDescendingRowsMatrices() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    7, 1,
                    1, 1,

                    1, 6,
                    2, 2,

                    5, 4,
                    2, 3,

                    1, 3,
                    7, 9
            },
            4, 2, 2);

    assert(countNonDescendingRowsMatrices(ms, 4) == 2);
}

void test_countZeroRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0,
                    1, 0,
                    0, 0,
            },
            3, 2);

    assert(countZeroRows(m) == 2);
}

void testTasks() {
    test_getSquareOfMatrixIfSymmetric();
    test_transposeIfMatrixHasNotEqualSumOfRows();
    test_isMutuallyInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal();
    test_getMinInArea();
    test_sortByDistances();
    test_countEqClassesByRowsSum();
    test_getNSpecialElements();
    test_swapPenultimateRow();
    test_countNonDescendingRowsMatrices();
    test_countZeroRows();
    test_swapMaxMinRows();
    test_sortRowsByMaxElement();
    test_sortColsByMinElement();
}
int main() {
    functionsTest();
    testTasks();

    return 0;
}
