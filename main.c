#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memoize.h"


int main() {
  int money;

  printf("Enter amount to convert (Ctrl+D to stop):\n");

  while (scanf("%d", &money) != EOF) {
    char* text_representation = converter(money);

    if (strncmp(text_representation, "Retrieved from cache:", 22) == 0) {
      printf("%s\n", text_representation);
      free(text_representation);
    } else {
      printf("%d = %s\n", money, text_representation);
      if (money >= 1500) {
        free(text_representation);
      }
    }
  }

  for (int i = 0; i < 1500; i++) {
    if (memoized[i] != NULL) {
      free(memoized[i]);
      memoized[i] = NULL;
    }
  }

  return 0;
}
