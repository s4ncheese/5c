add_library(data_structures bitset/bitset.c bitset/bitset.h
            unordered_array_set/unordered_array_set.h
            unordered_array_set/unsorted_array_set.c
            vectors/vector.h
            vectors/vector.c
            matrix/matrix.h
            matrix/matrix.c matrix/tests.h matrix/tests.c)

target_link_libraries(data_structures algorithms)