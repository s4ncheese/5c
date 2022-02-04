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