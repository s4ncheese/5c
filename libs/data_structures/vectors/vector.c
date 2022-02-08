#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

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
// иначе значениям вектора присваивает NULL
void reserve(vector *v, size_t newCapacity) {
    if (newCapacity != 0) {
        v->data = realloc(v->data, newCapacity * sizeof(int));
        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(2);
        }
    } else {
        v->data = NULL;
    }
    v->capacity = newCapacity;
    if (v->size > newCapacity)
        v->size = newCapacity;
}

// Удаляет элементы вектора v, не освобождая при этом память
void clear(vector *v) {
    v->size = 0;
}

// Освобождает память, выделенную под неиспользуемые элементы
// вектора v
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

// Возвращает значение true, если вектор v является пустым
bool isEmpty(vector *v) {
    return v->size == 0;
}

// Возвращает значение true, если вектор v является полным
bool isFull(vector *v) {
    return v->size == v->capacity;
}

// Возвращает элемент вектора v с индексом i
int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

// Добавляет элемент x в конец вектора v.
// Если вектор заполнен, увеличивает количество выделенной памяти
// в два раза
void pushBack(vector *v, int x) {
    if (isFull(v)) {
        if (v->capacity)
            reserve(v, v->capacity * 2);
        else
            reserve(v, 1);
    }
    v->data[v->size] = x;
    v->size++;
}

// Удаляет последний элемент вектора v. Если вектор пустой,
// выдает ошибку
void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "impossible to delete last element:"
                        " the vector is empty");
        exit(1);
    }
    v->size--;
}

// Возвращает указатель на элемент вектора v с индексом
// index, если он принадлежит вектору. Иначе выводится сообщение об
// ошибке
int *atVector(vector *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%zu] is not exist", index);
        exit(3);
    } else
        return &v->data[index];
}

// Возвращает указатель на последний элемент вектора v
int *back(vector *v) {
    if (v->data == NULL || isEmpty(v)) {
        fprintf(stderr, "IndexError: element is not exist");
        exit(3);
    } else
        return &v->data[v->size - 1];
}

// Возвращает адрес нулевого элемента вектора v, если его размер
// не равен 0, или значения не хранят NULL, иначе выводит сообщение
// об ошибке
int *front(vector *v) {
    if (v->data == NULL || isEmpty(v)) {
        fprintf(stderr, "IndexError: element is not exist");
        exit(3);
    } else
        return &v->data[0];
}