//
// Created by s4ncheese on 12.12.2021.
//

#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <math.h>
#include "array.h"
#include <stdbool.h>

long long max2_(const long long a, const long long b) {
    return a > b ? a : b;
}

int absMin2_(const int a, const int b) {
    return abs(a) < abs(b) ? abs(a) : abs(b);
}

void swap_(long long *a, long long *b) {
    long long t = *a;
    *a = *b;
    *b = t;
}

void dSwap_(double *a, double *b) {
    double t = *a;
    *a = *b;
    *b = t;
}

void inputArray_(long long *array, const size_t size) {
    for (size_t i = 0; i < size; i++)
        scanf("%lld", &array[i]);
}

void outputArray_(const long long *array, const size_t size) {
    for (size_t i = 0; i < size; i++)
        printf("%lld ", array[i]);
}

size_t linearSearch_(const long long *array, const size_t size, const long long x) {
    for (size_t i = 0; i < size; i++)
        if (array[i] == x)
            return i;

    return size;
}

size_t binarySearch_(const long long *array, const size_t size, const long long x) {
    size_t left = 0;
    size_t right = size - 1;
    while (left <= right) {
        size_t middle = left + (right - left) / 2;
        if (array[middle] < x)
            left = ++middle;
        else if (array[middle] > x)
            right = --middle;
        else
            return middle;
    }

    return SIZE_MAX;
}

size_t binarySearchMoreOrEqual_(const long long *array, const size_t size,
                                const long long x) {
    if (array[0] >= x)
        return 0;
    size_t left = 0;
    size_t right = size - 1;
    while (right > left) {
        size_t middle = left + (right - left) / 2;
        if (array[middle] >= x)
            right = middle;
        else
            left = middle;
    }

    return right;
}

void insert_(long long *array, size_t *size, const size_t pos,
             const long long value) {
    assert(pos < *size);
    if (*size != 0) {
        size_t lowBound = (pos == 0) ? SIZE_MAX : pos;
        (*size)++;
        for (size_t i = *size; i != lowBound; i--)
            array[i] = array[i - 1];
        array[pos] = value;
    } else {
        (*size)++;
        array[pos] = value;
    }
}

void append_(long long *array, size_t *size, const long long value) {
    array[*size] = value;
    (*size)++;
}

void deleteBySavePosOrder_(long long *array, size_t *size, const size_t pos) {
    for (size_t i = pos + 1; i < *size; i++)
        array[i] = array[i + 1];
    (*size)--;
}

void deleteByUnsavePosOrder_(long long *array, size_t *size, const size_t pos) {
    swap_(&array[pos], &array[*size - 1]);
    (*size)--;
}

int all_(const long long *array, const size_t size, int (*predicate)(long long)) {
    for (size_t i = 0; i < size; i++)
        if (!predicate(array[i]))
            return 0;

    return 1;
}

int any_(const long long *array, const size_t size, int (*predicate)(long long)) {
    for (size_t i = 0; i < size; i++)
        if (predicate(array[i]))
            return 1;

    return 0;
}

void forEach_(long long *source, const size_t size, long long *dest,
              int (*predicate)(long long)) {
    for (size_t i = 0; i < size; i++)
        dest[i] = predicate(source[i]);
}

long long countIf_(const long long *array, const size_t size, int (*predicate)(long long)) {
    long long count = 0;
    for (size_t i = 0; i < size; i++)
        if (predicate(array[i]))
            count++;

    return count;
}

void deleteIf_(long long *array, size_t *size, int (*deletePredicate)(long long)) {
    size_t iRead = 0;
    while (iRead < *size && (!deletePredicate(array[iRead])))
        iRead++;
    size_t iWrite = iRead;
    while (iRead < *size) {
        if (!deletePredicate(array[iRead])) {
            array[iWrite] = array[iRead];
            iWrite++;
        }
        iRead++;
    }
    *size = iWrite;
}

typedef struct unordered_array_set {
    int *data; // элементы множества
    size_t size; // количество элементов в множестве
    size_t capacity; // максимальное количество элементов в множестве
} unordered_array_set;

// возвращает пустое множество для capacity элементов
unordered_array_set unordered_array_set_create(size_t capacity);

// возвращает множество, состоящее из элементов массива a размера size
unordered_array_set unordered_array_set_create_from_array(
        const int *a, size_t size
);

// возвращает позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
size_t unordered_array_set_in(unordered_array_set *set, int value);

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool unordered_array_set_isEqual(
        unordered_array_set set1, unordered_array_set set2
);

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void unordered_array_set_isAbleAppend(unordered_array_set *set);

// добавляет элемент value в множество set
void unordered_array_set_insert(unordered_array_set *set,
                                int value);

// удаляет элемент value из множества set
void unordered_array_set_deleteElement(unordered_array_set *set, int value);

// возвращает объединение множеств set1 и set2
unordered_array_set unordered_array_set_union(unordered_array_set set1,
                                              unordered_array_set set2);

// возвращает пересечение множеств set1 и set2
unordered_array_set unordered_array_set_intersection(unordered_array_set set1,
                                                     unordered_array_set set2);

// возвращает разность множеств set1 и set2
unordered_array_set unordered_array_set_difference(unordered_array_set set1,
                                                   unordered_array_set set2);

// возвращает симметрическую разность множеств set1 и set2
unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1,
                                                            unordered_array_set set2);

// возвращает дополнение до универсума множества set
unordered_array_set unordered_array_set_complement(unordered_array_set set,
                                                   unordered_array_set universumSet);

// вывод множества set
void unordered_array_set_print(unordered_array_set set);

// освобождает память, занимаемую множеством set
void unordered_array_set_delete(unordered_array_set set);