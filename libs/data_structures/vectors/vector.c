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

    return (vector) {a, 0, n};
}

// Изменяет количество памяти, выделенное под хранение элементов
// вектора v на newCapacity, если newCapacity не равно 0,
// иначе
void reserve(vector *v, size_t newCapacity) {
    if (newCapacity != 0) {
        v->data = realloc(v->data, newCapacity * sizeof(int));
        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(2);
        }
    } else
        v->data = NULL;
    v->capacity = newCapacity;
    if (v->size > newCapacity)
        v->size = newCapacity;
}

// Удаляет элементы из контейнера v, не освобождая при этом память
void clear(vector *v) {
    v->size = 0;
}

// Освобождает память, выделенную под неиспользуемые элементы
// контейнера v
void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

// Освобождает память, выделенную для вектора v
void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}