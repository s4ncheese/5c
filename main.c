#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <memory.h>
#include "libs/algorithms/array/array.h"

// функция сортировки
typedef struct SortFunc {
    void (*sort )(int *a, size_t n); // указатель на функцию
    // сортировки
    char name[64]; // имя сортировки,
    // используемое при выводе
} SortFunc;

// функция генерации
typedef struct GeneratingFunc {
    void (*generate )(int *a, size_t n); // указатель на функцию
    // генерации последоват.
    char name[64]; // имя генератора,
    // используемое при выводе
} GeneratingFunc;

// функция сортировки
typedef struct nCompSort {
    long long (*nComp)(int *a, size_t n); // указатель на функцию
    // сортировки
    char name[64];                   // имя сортировки,
    // используемое при выводе
} nCompSort;

#define TIME_TEST(testCode, time){ \
    clock_t start_time = clock() ; \
    testCode \
        clock_t end_time = clock() ;\
    clock_t sort_time = end_time - start_time ; \
time = (double) sort_time / CLOCKS_PER_SEC ; \
}

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

/*------------Generation Functions---------*/

void generateRandomArray(int *array, const size_t size) {
    srand(time(0));
    for (size_t i = 0; i < size; i++)
        array[i] = 100000 - rand() % 100000;

}

void generateOrderedArray(int *array, const size_t size) {
    srand(time(0));
    for (size_t i = 0; i < size; i++)
        array[i] = i;

}

void generateOrderedBackwards(int *array, const size_t size) {
    srand(time(0));
    for (size_t i = 0; i < size; i++)
        array[i] = size - i - 1;
}

/*--------------Chek Time-------------*/

void checkTime(void (*sortFunc )(int *, size_t),
               void (*generateFunc )(int *, size_t),
               size_t size, char *experimentName) {
    static size_t runCounter = 1;

    // генерация последовательности
    static int innerBuffer[100000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf(" Name : %s\n", experimentName);
// замер времени
    double time;
    TIME_TEST ({ sortFunc(innerBuffer, size); }, time);
    // результаты замера
    printf(" Status : ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Time : %.3f s.\n", time);

        // запись в файл
        char filename[256];
        sprintf(filename, "./data/%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf(" FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %.3f\n", size, time);
        fclose(f);
    } else {
        printf(" Wrong !\n");

        // вывод массива, который не смог быть отсортирован
        outputArray(innerBuffer, size);

        exit(1);
    }
}

/*---------------------Selection Sort-----------------------*/

void selectionSort(int *array, const size_t size) {
    for (int i = 0; i < size - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < size; j++)
            if (array[j] < array[minPos])
                minPos = j;
        swap_(&array[i], &array[minPos]);
    }
}

long long getNCmpsOfSelectionSort(int *array, const size_t size) {
    long long countComp = 0;
    for (int i = 0; i < size - 1 && ++countComp; i++) {
        int minPos = i;
        for (int j = i + 1; j < size && ++countComp; j++)
            if (array[j] < array[minPos] && ++countComp)
                minPos = j;
        swap_(&array[i], &array[minPos]);
    }
    return countComp;
}

/*------------Insertion Sort-----------------*/

void insertionSort(int *array, const size_t size) {
    for (size_t i = 1; i < size; i++) {
        int t = array[i];
        size_t j = i;
        while (j > 0 && array[j - 1] > t) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = t;
    }
}

long long getNCmpsOfIntersections(int *array, const size_t size) {
    long long countComp = 0;
    for (size_t i = 1; i < size && ++countComp; i++) {
        int t = array[i];
        size_t j = i;
        while (j > 0 && ++countComp && array[j - 1] > t && ++countComp) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = t;
    }
    return countComp;
}

/*--------------------Bubble----------------------*/

void bubbleSort(int *array, const size_t size) {
    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = size - 1; j > i; j--)
            if (array[j - 1] > array[j])
                swap_(&array[j - 1], &array[j]);
}

long long getNCmpsOfBubble(int *array, const size_t size) {
    long long countComp = 0;
    for (size_t i = 0; i < size - 1 && ++countComp; i++)
        for (size_t j = size - 1; j > i && ++countComp; j--)
            if (array[j - 1] > array[j] && ++countComp)
                swap_(&array[j - 1], &array[j]);

    return countComp;
}

/*-------------------Comb Sort----------------*/

void combsort(int *array, const size_t size) {
    size_t step = size;
    int swapped = 1;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; j < size; ++i, ++j)
            if (array[i] > array[j]) {
                swap_(&array[i], &array[j]);
                swapped = 1;
            }
    }
}

long long getNCmpsOfComb(int *array, const size_t size) {
    size_t step = size;
    int swapped = 1;
    long long countComp = 0;
    while (step > 1 && ++countComp || swapped && ++countComp) {
        if (step > 1 && ++countComp)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; j < size && ++countComp; ++i, ++j)
            if (array[i] > array[j] && ++countComp) {
                swap_(&array[i], &array[j]);
                swapped = 1;
            }
    }
    return countComp;
}

/*-----------------------Shell Sort-----------------*/

void ShellSort(int *array, const size_t size) {
    int tmp;
    for (size_t step = size / 2; step > 0; step /= 2)
        for (size_t i = step; i < size; i++) {
            tmp = array[i];
            size_t j;
            for (j = i; j >= step; j -= step) {
                if (tmp < array[j - step])
                    array[j] = array[j - step];
                else
                    break;
            }
            array[j] = tmp;
        }
}

long long getNCmpsOfShell(int *array, const size_t size) {
    long long countComp = 0;
    for (size_t step = size / 2; step > 0 && ++countComp; step /= 2)
        for (size_t i = step; i < size && ++countComp; i++) {
            int tmp = array[i];
            size_t j;
            for (j = i; j >= step && ++countComp; j -= step) {
                if (tmp < array[j - step] && ++countComp)
                    array[j] = array[j - step];
                else
                    break;
            }
            array[j] = tmp;
        }
    return countComp;
}

/*----------------Digit Sort-------------*/

int digit(int n, int k, int N, int M) {
    return (n >> (N * k) & (M - 1));
}

void _radixSort(int *l, int *r, int N) {
    int k = (32 + N - 1) / N;
    int M = 1 << N;
    int sz = r - l;
    int *b = (int *) malloc(sizeof(int) * sz);
    int *c = (int *) malloc(sizeof(int) * M);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < M; j++)
            c[j] = 0;

        for (int *j = l; j < r; j++)
            c[digit(*j, i, N, M)]++;

        for (int j = 1; j < M; j++)
            c[j] += c[j - 1];

        for (int *j = r - 1; j >= l; j--)
            b[--c[digit(*j, i, N, M)]] = *j;

        int cur = 0;
        for (int *j = l; j < r; j++)
            *j = b[cur++];
    }
    free(b);
    free(c);
}

void radixSort(int *array, const size_t n) {
    _radixSort(array, array + n, 8);
}

void checkNComp(long long (*nComp )(int *a, size_t n),
                void (*generateFunc)(int *, size_t),
                size_t size, char *experimentName, char *name) {
    static size_t runCounter = 1;

    // генерация последовательности
    static int innerBuffer[100000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf("Name: %s\n", experimentName);

    // замер времени
    long long nComps = nComp(innerBuffer, size);

    // результаты замера
    printf("Status: ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Comps: %lld\n", nComps);

        // запись в файл
        char filename[256];
        sprintf(filename, "./data/Comps/%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf("FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %lld\n", size, nComps);
        fclose(f);
    } else {
        printf("Wrong!\n");

        // вывод массива, который не смог быть отсортирован
        outputArray(innerBuffer, size);

        exit(1);
    }
}

void timeExperiment() {
    // описание функций сортировки
    SortFunc sorts[] = {
            {selectionSort, "selectionSort"},
            {insertionSort, "insertionSort"},
            {bubbleSort,    "bubbleSort"},
            {combsort,      "combSort"},
            {ShellSort,     "shellSort"},
            {radixSort,     "radixSort"},
    };
    const unsigned FUNCS_N = ARRAY_SIZE (sorts);

    nCompSort nComps[] = {
            {getNCmpsOfSelectionSort, "getNCmpsOfSelectionSort"},
            {getNCmpsOfIntersections, "getNCmpsOfIntersections"},
            {getNCmpsOfBubble,        "getNCmpsOfBubble"},
            {getNCmpsOfComb,          "combSortN"},
            {getNCmpsOfShell,         "getNCmpsOfShell"},
    };

    const unsigned COMPS_N = ARRAY_SIZE(nComps);

    // описание функций генерации
    GeneratingFunc generatingFuncs[] = {
            // генерируется случайный массив
            {generateRandomArray,      " random "},
            // генерируется массив 0, 1, 2, ..., n - 1
            {generateOrderedArray,     " ordered "},
            // генерируется массив n - 1, n - 2, ..., 0
            {generateOrderedBackwards, " orderedBackwards "}
    };
    const unsigned CASES_N = ARRAY_SIZE (generatingFuncs);

    // запись статистики в файл
    for (size_t size = 10000; size <= 100000; size += 10000) {
        printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf(" Size : %d\n", size);
        for (int i = 0; i < FUNCS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {
                // генерация имени файла
                static char filename[128];
                sprintf(filename, "%s_%s_time ",
                        sorts[i].name, generatingFuncs[j].name);
                checkTime(sorts[i].sort,
                          generatingFuncs[j].generate,
                          size, filename);
            }
        }
        printf("\n");
    }

    // запись статистики в файл
    for (size_t size = 10000; size <= 100000; size += 10000) {
        printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf("Size : %zu\n", size);
        for (int i = 0; i < COMPS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {
                // генерация имени файла
                static char filename[128];
                sprintf(filename, "%s_%s_comps",
                        nComps[i].name, generatingFuncs[j].name);
                checkNComp(nComps[i].nComp,
                           generatingFuncs[j].generate,
                           size, filename, nComps[i].name);
            }
        }
        printf("\n");
    }
}

int main() {
    timeExperiment();

    return 0;
}