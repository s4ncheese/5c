//
// Created by s4ncheese on 25.12.2021.
//

#include "unordered_array_set.h"

// возвращает пустое множество для capacity элементов
unordered_array_set unordered_array_set_create(size_t capacity) {
    int size = 0;
    return (unordered_array_set) {malloc(sizeof(int) * capacity),
                                  size, capacity};
}

// возвращает позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
size_t unordered_array_set_in(unordered_array_set *set, int value) {
    return linearSearch_(set->data, set->size, value);
}

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert(set->size < set->capacity);
}

// добавляет элемент value в множество set
void unordered_array_set_insert(unordered_array_set *set, int value) {
    unordered_array_set_isAbleAppend(set);
    if (unordered_array_set_in(set, value) == set->size)
        append_(&set, &set->size, value);
}

// возвращает множество, состоящее из элементов массива a размера size
unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size) {
    unordered_array_set setFromArray = unordered_array_set_create(size);
    for (size_t i = 0; i < size; i++)
        unordered_array_set_insert(&setFromArray, a[i]);
    return setFromArray;
}


// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    assert(set1.capacity == set2.capacity);
    if (set1.size != set2.size)
        return 0;
    else
        for (size_t i = 0; i < set1.size; i++)
            if (!unordered_array_set_in(&set1, set1.data[i]))
                return false;

    return true;
}

// удаляет элемент value из множества set
void unordered_array_set_deleteElement(unordered_array_set *set, int value) {
    if (unordered_array_set_in(set, value) < set->size) {
        size_t indexOfDeleteEl = unordered_array_set_in(set, value);
        deleteBySavePosOrder_(&set, &set->size, indexOfDeleteEl);
    }
}

// возвращает объединение множеств set1 и set2
unordered_array_set unordered_array_set_union(unordered_array_set set1,
                                              unordered_array_set set2) {
    assert(set1.capacity == set2.capacity);
    unordered_array_set unionSet = unordered_array_set_create(set1.capacity);
    for (size_t i = 0; i < set1.size; i++)
        append_(unionSet.data, &set1.size, set1.data[i]);
    for (size_t i = 0; i < set2.size; i++) {
        unordered_array_set_insert(&unionSet, set2.data[i]);
    }

    return unionSet;
}

// возвращает пересечение множеств set1 и set2
unordered_array_set unordered_array_set_intersection(unordered_array_set set1,
                                                     unordered_array_set set2) {
    assert(set1.capacity == set2.capacity);
    unordered_array_set intersectionSet = unordered_array_set_create(set1.capacity);
    for (size_t i = 0; i < set1.size; i++) {
        if (unordered_array_set_in(&set2, set1.data[i]))
            unordered_array_set_insert(&intersectionSet, set1.data[i]);
    }

    return intersectionSet;
}

// возвращает разность множеств set1 и set2
unordered_array_set unordered_array_set_difference(unordered_array_set set1,
                                                   unordered_array_set set2) {
    assert(set1.capacity == set2.capacity);
    unordered_array_set differenceSet = unordered_array_set_create(set1.capacity);
    for (size_t i = 0; i < set1.size; i++)
        if (unordered_array_set_in(&set2, set1.data[i]) == set1.capacity)
            unordered_array_set_insert(&differenceSet, set1.data[i]);

    return differenceSet;
}

// возвращает симметрическую разность множеств set1 и set2
unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1,
                                                            unordered_array_set set2) {
    assert(set1.capacity == set2.capacity);
    unordered_array_set symDifSet = unordered_array_set_difference(set1, set2);
    unordered_array_set symDifSet2 = unordered_array_set_difference(set1, set2);
    unordered_array_set unionSymDifSets = unordered_array_set_union(symDifSet,
                                                                    symDifSet2);
    free(symDifSet2.data);
    free(symDifSet.data);

    return unionSymDifSets;
}

// возвращает дополнение до универсума множества set
unordered_array_set unordered_array_set_complement(unordered_array_set set,
                                                   unordered_array_set universumSet) {
    return unordered_array_set_difference(set, universumSet);
}

// вывод множества set
void unordered_array_set_print(unordered_array_set set) {
    printf("{");
    for (size_t i = 0; i < set.size; i++)
       printf("%d, ", set.data[i]);
    if (set.size == 0)
        printf("}");
    else
        printf("\b\b}");
}

// освобождает память, занимаемую множеством set
void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}