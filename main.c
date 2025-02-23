#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memoize.h"

int main() {
    int money;

    printf("Enter amount to convert (Ctrl+D to stop):\n");

    initialize_memo();

    char* (*function_pointer)(int) = memoize;

    // Read user input
    while (scanf("%d", &money) != EOF) {
        if (money < 0) {
          printf("Improper value, please enter a value greater than 0.\n");
          exit(1);
        }
        char* text_representation = function_pointer(money);
        printf("%d = %s\n", money, text_representation);

        free(text_representation);
    }

    // Free up Cache
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (memoized[i] != NULL) {
            free(memoized[i]);
            memoized[i] = NULL;
        }
    }
    return 0;
}
