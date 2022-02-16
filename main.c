#include "libs\data_structures\vectors\vector.h"
#include "libs\data_structures\matrix\matrix.h"
#include <assert.h>
#include <stdio.h>

#define ZERO_SIZE 0
#define ONE_SIZE 1
#define TEN_SIZE 10
#define HUND_SIZE 100
#define THOUS_SIZE 1000

/*--------------------------------------------------PUSH BACK EMPTY--------------------------------------------------*/

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

/*------------------------------------------------PUSH BACK NOT EMPTY------------------------------------------------*/

void test_pushBack_notEmptyThousSize() {
    vector v = createVector(THOUS_SIZE);
    v.size = TEN_SIZE;
    int x = 2;
    pushBack(&v, x);

    assert(v.size == TEN_SIZE + 1);
    assert(v.capacity == THOUS_SIZE);
    assert(v.data[TEN_SIZE] == x);

    deleteVector(&v);
}

void test_pushBack_notEmptyTenSize() {
    vector v = createVector(TEN_SIZE);
    v.size = TEN_SIZE - 1;
    int x = 2549;
    pushBack(&v, x);

    assert(isFull(&v));
    assert(v.data[v.size - 1] == x);
    assert(v.capacity == TEN_SIZE);

    deleteVector(&v);
}

/*--------------------------------------------------PUSH BACK FULL---------------------------------------------------*/

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

/*------------------------------------------------POP BACK NOT EMPTY-------------------------------------------------*/

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

void test_popBack_notEmptyZeroSize() {
    vector v = createVector(ZERO_SIZE);
    int x = 10;
    pushBack(&v, x);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);

    deleteVector(&v);
}

/*------------------------------------------------AT NOT EMPTY VECTOR------------------------------------------------*/

void test_atVector_notEmptyVectorVar1() {
    vector v = createVector(TEN_SIZE);
    v.size = v.capacity;
    for (size_t i = 0; i < v.size; i++)
        assert(*atVector(&v, i) == v.data[i]);

    deleteVector(&v);
}

void test_atVector_notEmptyVectorVar2() {
    vector v = createVector(HUND_SIZE);
    v.size = v.capacity;

    for (size_t i = 0; i < v.size; i++)
        assert(*atVector(&v, i) == v.data[i]);

    deleteVector(&v);

}

/*----------------------------------------------REQUEST TO LAST ELEMENT----------------------------------------------*/

void test_atVector_requestToLastElementVar1() {
    vector v = createVector(TEN_SIZE);
    v.size = v.capacity;

    assert(*atVector(&v, v.size - 1) == v.data[v.size - 1]);

    deleteVector(&v);

}

void test_atVector_requestToLastElementVar2() {
    vector v = createVector(ONE_SIZE);
    v.size = v.capacity;

    assert(*atVector(&v, v.size - 1) == v.data[v.size - 1]);

    deleteVector(&v);
}

/*--------------------------------------------------BACK ONE ELEMENT-------------------------------------------------*/

void test_back_oneElementVer1() {
    vector v = createVector(ONE_SIZE);
    v.size = v.capacity;

    assert(*back(&v) == v.data[v.size - 1]);

    deleteVector(&v);
}

void test_back_oneElementVer2() {
    vector v = createVector(ONE_SIZE);
    v.size = v.capacity;

    assert(*back(&v) == v.data[v.size - 1]);

    deleteVector(&v);
}

/*----------------------------------------------------FINAL TESTS----------------------------------------------------*/

void test_pushBack_emptyVector() {
    test_pushBack_emptyVectorZeroSize();
    test_pushBack_emptyVectorHundSize();
}

void test_pushBack_notEmpty() {
    test_pushBack_notEmptyThousSize();
    test_pushBack_notEmptyTenSize();
}

void test_pushBack_full() {
    test_pushBack_fullZeroSize();
    test_pushBack_fullThousSize();
}

void test_popBack() {
    test_popBack_notEmptyOneSize();
    test_popBack_notEmptyTenSize();
    test_popBack_notEmptyZeroSize();
}

void test_atVector_notEmptyVector() {
    test_atVector_notEmptyVectorVar1();
    test_atVector_notEmptyVectorVar2();
}

void test_back_oneElementInVector() {
    test_back_oneElementVer1();
    test_back_oneElementVer2();
}

void test_atVector_requestToLastElement() {
    test_atVector_requestToLastElementVar1();
    test_atVector_requestToLastElementVar2();
}

void test() {
    test_atVector_requestToLastElement();
    test_atVector_notEmptyVector();
    test_back_oneElementInVector();
    test_pushBack_emptyVector();
    test_pushBack_notEmpty();
    test_pushBack_full();
    test_popBack();
}

int main() {
//    test();
    matrix m = getMemMatrix(4, 4);
    inputMatrix(m);
    position p = getMinValuePos(m);

    printf("{%d;%d}", p.rowIndex, p.colIndex);

    return 0;
}