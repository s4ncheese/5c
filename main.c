#include "libs\data_structures\vectors\vector.h"
#include <assert.h>

#define ZERO_SIZE 0
#define ONE_SIZE 1
#define TEN_SIZE 10
#define HUND_SIZE 100
#define THOUS_SIZE 1000

void test_pushBack_emptyVectorZeroSize() {
    vector v = createVector(ZERO_SIZE);
    int x = 193458;
    pushBack(&v, x);

    assert(v.size == 1);
    assert(v.capacity == 1);
    assert(v.data[0] == x);

    deleteVector(&v);
}

void test_pushBack_emptyVectorHundSize() {
    vector v = createVector(HUND_SIZE);
    int x = 2402;
    pushBack(&v, x);

    assert(v.size == 1);
    assert(v.capacity == HUND_SIZE);
    assert(v.data[0] == x);

    deleteVector(&v);
}

/* ----------------------------------------------------------------------------------------------------------------- */

void test1_pushBack_notEmpty_thous_size() {
    vector v = createVector(THOUS_SIZE);
    v.size = TEN_SIZE;
    int x = 2;
    pushBack(&v, x);

    assert(v.size == TEN_SIZE + 1);
    assert(v.capacity == THOUS_SIZE);
    assert(v.data[TEN_SIZE] == x);

    deleteVector(&v);
}

void test2_pushBack_notEmpty_ten_size() {
    vector v = createVector(TEN_SIZE);
    v.size = TEN_SIZE - 1;
    int x = 2549;
    pushBack(&v, x);

    assert(isFull(&v));
    assert(v.data[v.size - 1] == x);
    assert(v.capacity == TEN_SIZE);

    deleteVector(&v);
}

/* ----------------------------------------------------------------------------------------------------------------- */

void test_pushBack_fullZeroSize() {
    vector v = createVector(ZERO_SIZE);
    int x = 193458;
    pushBack(&v, x);

    assert(v.capacity == ZERO_SIZE + 1);
    assert(v.size == 1);
    assert(v.data[0] == x);

    deleteVector(&v);
}

void test_pushBack_fullThousSize() {
    vector v = createVector(THOUS_SIZE);
    v.size = THOUS_SIZE;
    int x = 1;
    pushBack(&v, x);

    assert(v.capacity == THOUS_SIZE * 2);
    assert(v.size == THOUS_SIZE + 1);
    assert(v.data[v.size - 1] == x);
}

/* ----------------------------------------------------------------------------------------------------------------- */

void test_popBack_notEmptyOneSize() {
    vector v = createVector(ONE_SIZE);
    v.size = ONE_SIZE;
    popBack(&v);

    assert(v.capacity == ONE_SIZE);
    assert(v.size == ONE_SIZE - 1);
    assert(v.data != NULL);
}

void test_popBack_notEmptyTenSize() {
    vector v = createVector(TEN_SIZE);
    v.size = TEN_SIZE;
    popBack(&v);

    assert(v.capacity == TEN_SIZE);
    assert(v.size == TEN_SIZE - 1);
}

/* ----------------------------------------------------------------------------------------------------------------- */

void test_pushBack_emptyVector() {
    test_pushBack_emptyVectorZeroSize();
    test_pushBack_emptyVectorHundSize();
}

void test_pushBack_notEmpty() {
    test1_pushBack_notEmpty_thous_size();
    test2_pushBack_notEmpty_ten_size();
}

void test_pushBack_full() {
    test_pushBack_fullZeroSize();
    test_pushBack_fullThousSize();
}

void test_popBack() {
    test_popBack_notEmptyOneSize();
    test_popBack_notEmptyTenSize();
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_notEmpty();
    test_pushBack_full();
    test_popBack();
}

int main() {
    test();

    return 0;
}