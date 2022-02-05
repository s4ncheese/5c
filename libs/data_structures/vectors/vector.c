//
// Created by s4ncheese on 02.02.2022.
//

#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// Возвращает структуру - дескриптор vector из n значений
vector createVector(size_t n) {
    int *a = malloc(sizeof(int) * n);
    if (a == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vector){a, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == NULL)
        v->data = 0;
}
// Удаляет элементы из контейнера v, не освобождая при этом память
void clear(vector *v) {
    v->size = 0;
}

// Освобождает память, выделенную под неиспользуемые элементы
// контейнера v
void shrinkToFit(vector *v) {
    v->capacity = v->size;
}

// Освобождает память, выделенную для вектора v
void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}