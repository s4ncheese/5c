#ifndef INC_4E_MATRIX_H
#define INC_4E_MATRIX_H

typedef struct matrix {
    int **values;
    int nRows;
    int nCols;
}matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
}position;

matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

void freeMemMatrix(matrix m);

void freeMemMatrices(matrix *mArray, int nMatrices);

void inputMatrix(matrix m);

void inputMatrices(matrix *mArray, int nMatrix);

void outputMatrix(matrix m);

void swapRows(matrix m, int row1, int row2);

void swapColumns(matrix m, int col1, int col2);

#endif
