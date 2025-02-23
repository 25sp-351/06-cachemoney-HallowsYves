#include "memoize.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* memoized[CACHE_SIZE] = {NULL};

// set all pointers to NULL to prevent garage data
void initialize_memo() {
    for (int index = 0; index < CACHE_SIZE; index++)
        memoized[index] = NULL;
}

char* memoize(int input_money) {
    // 1. Check if the value is already in the cache
    // 2. if it is create a copy and allocate memory for the string
    // 3. Copy the cached value into cached_copy, return the copy so the cache
    // is not modified.
    if (input_money < CACHE_SIZE && memoized[input_money] != NULL) {
        char* cached_copy = (char*)malloc(strlen(memoized[input_money]) + 1);
        if (cached_copy != NULL)
            strcpy(cached_copy, memoized[input_money]);
        return cached_copy;
    }

    char* result = converter(input_money);
    // Store into cache
    if (input_money < CACHE_SIZE) {
        memoized[input_money] = (char*)malloc(strlen(result) + 1);
        if (memoized[input_money] != NULL)
            strcpy(memoized[input_money], result);
    }

    return result;
}
