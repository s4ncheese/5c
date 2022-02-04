//
// Created by s$ncheese on 12.12.2021.
//

#include "bitset.h"
#include <assert.h>
#include <stdio.h>

// Создает пустое множество с универсумом {1, 2, ..., maxValue}
bitset bitset_create(unsigned maxValue) {
    assert(maxValue < sizeof(unsigned) * 8);
    unsigned values = 0;
    return (bitset){values, maxValue};
}

// возвращает значение ’истина’, если значение value имеется в множестве set
// иначе - ’ложь’
bool bitset_in(bitset set, unsigned value) {
    return set.values >> value & 1;
}

// Возвращает значение 'истина', если множество set1 равно множеству set2,
// иначе - 'ложь'
bool bitset_isEqual(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return set1.values == set2.values;
}

// Возвращает значение 'истина', если множество set1 является подмножеством
// множества set2
bool bitset_isSubset(bitset set1, bitset set2) {
    assert(set1.maxValue <= set2.maxValue);
    return set2.values == set1.values;
}

// Добавляет элемент value в множество set
void bitset_insert(bitset *set, unsigned value) {
    assert(value <= set->maxValue && value >= 0);
    set->values |= 1 << value;
}

// Удаляет значение value множества set
void bitset_deleteElement(bitset *set, unsigned value) {
    set->values &= ~(1 << value);
}

// Возвращает объединение множеств set1 и set2
bitset bitset_union(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset){set1.values | set2.values, set2.maxValue};
}

// возвращает пересечение множеств set1 и set2
bitset bitset_inntersection(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset){set1.values & set2.values, set2.maxValue};
}

// возвращает разность множеств set1 и set2
bitset bitset_difference(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset){set1.values & ~set2.values, set2.maxValue};
}

// возвращает симметрическую разность множеств set1 и set2
bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    bitset symmetricDif = bitset_union(bitset_difference(set1, set2),
                                       bitset_difference(set2, set1));
    return symmetricDif;
}

// возвращает дополнение до универсума множества set
bitset bitset_complement(bitset set) {
    return (bitset){~set.values, set.maxValue};
}

// вывод множества set
void bitset_print(bitset set) {
    printf("{");
    bool isEmpty = true;
    for (int i = 0; i <= set.maxValue; i++)
        if (bitset_in(set, i)) {
            printf("%d, ", i);
            isEmpty = false;
        }

    if (isEmpty)
        printf("}\n");
    else
        printf("\b\b}\n");
}