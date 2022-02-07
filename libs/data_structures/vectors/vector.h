//
// Created by s4ncheese on 02.02.2022.
//

#ifndef INC_4E_VECTOR_H
#define INC_4E_VECTOR_H
#include <stdlib.h>
#include <stdbool.h>

typedef struct vector {
    int *data;       // Указатель на элементы вектора
    size_t size;     // Размер вектора
    size_t capacity; // Вместимость вектора
}vector;

vector createVector(size_t n);

void reserve(vector *v, size_t newCapacity);

void clear(vector *v);

void shrinkToFit(vector *v);

void deleteVector(vector *v);

bool isEmpty(vector *v);

bool isFull(vector *v);

int getVectorValue(vector *v, size_t i);

void pushBack(vector *v, int x);

void popBack(vector *v);

#endif //INC_4E_VECTOR_H
