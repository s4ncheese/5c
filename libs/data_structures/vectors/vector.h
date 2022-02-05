//
// Created by s4ncheese on 02.02.2022.
//

#ifndef INC_4E_VECTOR_H
#define INC_4E_VECTOR_H
#include <stdlib.h>

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

#endif //INC_4E_VECTOR_H
