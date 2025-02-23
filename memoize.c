#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* units[] = {"",     "One", "Two",   "Three", "Four",
                       "Five", "Six", "Seven", "Eight", "Nine"};
const char* teens[] = {"Ten",      "Eleven",  "Twelve",  "Thirteen",
                       "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                       "Eighteen", "Nineteen"};
const char* tens[] = {"",      "",      "Twenty",  "Thirty", "Forty",
                      "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const char* hundreds[] = {"",
                          "One Hundred",
                          "Two Hundred",
                          "Three Hundred",
                          "Four Hundred",
                          "Five Hundred",
                          "Six Hundred",
                          "Seven Hundred",
                          "Eight Hundred",
                          "Nine Hundred"};
const char* thousands[] = {"",
                           "One Thousand",
                           "Two Thousand",
                           "Three Thousand",
                           "Four Thousand",
                           "Five Thousand",
                           "Six Thousand",
                           "Seven Thousand",
                           "Eight Thousand",
                           "Nine Thousand"};

char* memoized[1500] = {NULL};

void convertNumberToWords(int number, char* result) {
  if (number == 0) {
    strcat(result, "Zero");
    return;
  }

  if (number >= 1000) {
    strcat(result, thousands[number / 1000]);
    strcat(result, " ");
    number %= 1000;
  }

  if (number >= 100) {
    strcat(result, hundreds[number / 100]);
    strcat(result, " ");
    number %= 100;
  }

  if (number >= 20) {
    strcat(result, tens[number / 10]);

    if (number % 10 != 0) {
      strcat(result, "-");
      strcat(result, units[number % 10]);
    }
    return;
  } else if (number >= 10) {
    strcat(result, teens[number - 10]);
    return;
  }

  if (number > 0) {
    strcat(result, units[number]);
  }
}

char* converter(int input_money) {
  int dollars = input_money / 100;
  int cents = input_money % 100;

  char* result = (char*)malloc(200 * sizeof(char));

  if (input_money < 1500 && memoized[input_money] != NULL) {
    char* cached_message = (char*)malloc(250 * sizeof(char));
    if (cached_message == NULL) {
      exit(1);
    }

    sprintf(cached_message, "Retrieved from cache: %d = %s\n", input_money,
            memoized[input_money]);
    return cached_message;
  }

  if (result == NULL) {
    exit(1);
  }

  result[0] = '\0';

  convertNumberToWords(dollars, result);
  strcat(result, " dollars and ");

  if (cents == 10) {
    strcat(result, "Zero ");
  } else {
    convertNumberToWords(cents, result);
    strcat(result, " cents.");
  }

  if (input_money < 1500) {
    memoized[input_money] = result;
  }
  return result;
}