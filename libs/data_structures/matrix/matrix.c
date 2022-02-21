#include "matrix.h"
#include <malloc.h>
#include <stdio.h>
#include "../../algorithms/array/array.h"
#include <stdbool.h>
#include <assert.h>
#include <memory.h>

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

long long getSum(int *array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += array[i];

    return sum;
}

int getMaxInRow(int *row, int nElements) {
    int max = row[0];
    for (int elementInd = 0; elementInd < nElements; elementInd++)
        if (row[elementInd] > max)
            max = row[elementInd];

    return max;
}

int getMinInCol(int *col, int nElements) {
    int min = col[0];
    for (int colInd = 0; colInd < nElements; colInd++)
        if (col[colInd] < min)
            min = col[colInd];

    return min;
}

// Возвращает матрицу - произведение матриц m1 и m2
matrix mulMatrices(matrix m1, matrix m2) {
    if (m1.nCols != m2.nRows) {
        fprintf(stderr, "Matrices can't be multiplied");
        exit(1);
    }
    matrix mul = getMemMatrix(m1.nRows, m2.nCols);
    for (int rowInd = 0; rowInd < m1.nRows; rowInd++)
        for (int colInd = 0; colInd < m2.nCols; colInd++) {
            mul.values[rowInd][colInd] = 0;
            for (int i = 0; i < m1.nCols; i++)
                mul.values[rowInd][colInd] += m1.values[rowInd][i] *
                                              m2.values[i][colInd];
        }

    return mul;
}

int searchSum(long long *array, int size, int el) {
    for (int i = 0; i < size; i++)
        if (array[i] == el)
            return i;

    return size;
}

bool isUnique(long long *array, int size) {
    for (int i = 0; i < size; i++) {
        int sumPos = searchSum(array, size, array[i]);
        if (sumPos != i && sumPos != size)
            return false;
    }

    return true;
}

// Выполняет сортировку вставками строк матрицы m по неубыванию
// значения функции criteria, применяемой для строк
void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int *array = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; i++)
        array[i] = criteria(m.values[i], m.nCols);
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nRows; j++) {
            if (array[j] >= array[i]) {
                swap_(&array[j], &array[i]);
                swapRows(m, j, i);
            }
        }
    }

    free(array);
}

// Выполняет сортировку вставками строк матрицы m по неубыванию
// значения функции criteria, применяемой для столбцов
void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *criteriaArr = (int *) malloc(sizeof(int) * m.nCols);
    int *additionalArr = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nCols; i++) {
        for (int j = 0; j < m.nRows; j++)
            additionalArr[j] = m.values[j][i];
        criteriaArr[i] = criteria(additionalArr, m.nRows);
    }
    for (int i = 0; i < m.nCols; i++) {
        for (int j = i; j > 0 && criteriaArr[j - 1] > criteriaArr[j]; j--) {
            swap_(&criteriaArr[j - 1], &criteriaArr[j]);
            swapColumns(m, j, j - 1);
        }
    }
    free(criteriaArr);
    free(additionalArr);
}

// Возвращает значение истина, если матрица m является квадратной,
// иначе - ложь
bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

// Возвращает значение истина, если матрицы m1 и m2 равны,
// иначе - ложь
bool isTwoMatricesAreEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols) return false;
    for (int rowInd = 0; rowInd < m1.nRows; rowInd++)
        if (memcmp(m1.values[rowInd], m2.values[rowInd],
                   m1.nCols * sizeof(int)) != 0)
            return false;

    return true;
}

// Возвращает значение истина, если матрица m единичная, иначе ложь
bool isEMatrix(matrix m) {
    for (int rowInd = 0; rowInd < m.nRows; rowInd++)
        for (int colInd = 0; colInd < m.nCols; colInd++) {
            if (rowInd == colInd) {
                if (m.values[rowInd][colInd] != 1) return false;
            } else if (m.values[rowInd][colInd] != 0)
                return false;
        }

    return true;
}

// Возвращает значение истина, если матрица m является симметричной,
// иначе - ложь
bool isSymmetricMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;
    int diagonalEl = m.values[0][0];
    for (int rowInd = 0, colInd = rowInd + 1; rowInd < m.nRows && colInd < m.nCols;
         rowInd++, colInd++) {

        if (rowInd == colInd && m.values[rowInd][colInd] != diagonalEl ||
            m.values[rowInd][colInd] != m.values[colInd][rowInd])
            return false;
    }

    return true;
}

// Транспортирует квадратную матрицу m
void transposeSquareMatrix(matrix m) {
    if (m.nRows != m.nCols) {
        fprintf(stderr, "Matrix is not square");
        exit(1);
    }
    assert(m.nRows == m.nCols);
    for (int rowInd = 0; rowInd < m.nCols; rowInd++)
        for (int colInd = rowInd + 1; colInd < m.nRows; colInd++)
            swap_(&(m.values[rowInd][colInd]), &(m.values[colInd][rowInd]));
}

// Возвращает позицию первого минимального элемента матрицы m
position getMinValuePos(matrix m) {
    int min = m.values[0][0];
    position minPos = {0, 0};
    for (int rowInd = 0; rowInd < m.nRows; rowInd++)
        for (int colInd = 0; colInd < m.nCols; colInd++)
            if (m.values[rowInd][colInd] < min) {
                min = m.values[rowInd][colInd];
                minPos = (position) {rowInd, colInd};
            }

    return minPos;
}

// Возвращает позицию первого максимального элемента матрицы m
position getMaxValuePos(matrix m) {
    int max = m.values[0][0];
    position maxPos = {0, 0};
    for (int rowInd = 0; rowInd < m.nRows; rowInd++)
        for (int colInd = 0; colInd < m.nCols; colInd++)
            if (m.values[rowInd][colInd] > max) {
                max = m.values[rowInd][colInd];
                maxPos = (position) {rowInd, colInd};
            }

    return maxPos;
}

// Возвращает матрицу размера nRows на nCols, построенную из элементов
//массива array
matrix createMatrixFromArray(const int *array, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);
    int arrayInd = 0;

    for (int rowInd = 0; rowInd < nRows; rowInd++)
        for (int colInd = 0; colInd < nCols; colInd++)
            m.values[rowInd][colInd] = array[arrayInd++];

    return m;
}

// Возвращает указатель на нулевую матрицу массива из nMatrices
// матриц, размещенных в динамической памяти, построенных из
// элементов массива values
matrix *createArrayOfMatrixFromArray(const int *values, int nMatrices,
                                     int nRows, int nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int iWrite = 0;
    for (int matrixInd = 0; matrixInd < nMatrices; matrixInd++)
        for (int rowInd = 0; rowInd < nRows; rowInd++)
            for (int colInd = 0; colInd < nCols; colInd++)
                ms[matrixInd].values[rowInd][colInd] = values[iWrite++];

    return ms;
}