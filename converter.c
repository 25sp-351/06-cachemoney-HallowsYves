#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memoize.h"

const char* units[]     = {"",     "One", "Two",   "Three", "Four",
                           "Five", "Six", "Seven", "Eight", "Nine"};
const char* teens[]     = {"Ten",      "Eleven",  "Twelve",  "Thirteen",
                           "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                           "Eighteen", "Nineteen"};
const char* tens[]      = {"",      "",      "Twenty",  "Thirty", "Forty",
                           "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const char* hundreds[]  = {"",
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

    if (number > 0)
        strcat(result, units[number]);
}

char* converter(int input_money) {
    int dollars = input_money / 100;
    int cents   = input_money % 100;

    // Memory for result string
    char* result_string = (char*)malloc(200 * sizeof(char));
    if (result_string == NULL)
        exit(1);
    result_string[0] = '\0';

    convertNumberToWords(dollars, result_string);
    strcat(result_string, " dollars and ");

    if (cents == 10) {
        strcat(result_string, "Zero ");
    } else {
        convertNumberToWords(cents, result_string);
        strcat(result_string, " cents.");
    }

    if (input_money < CACHE_SIZE) {
        memoized[input_money] = (char*)malloc(strlen(result_string) + 1);
        if (memoized[input_money] != NULL)
            strcpy(memoized[input_money], result_string);
    }
    return result_string;
}
