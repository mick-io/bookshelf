// Exercise 1-14. Write a program to print a histogram of the frequencies of
// different characters in its input.

#include <stdio.h>

#define N_ASCII_VALUES 128
#define ASCII_CHAR_RANGE_START 33

int main() {
  int c;
  int histogram[N_ASCII_VALUES] = {0};

  while ((c = getchar()) != EOF)
    ++histogram[c];

  for (int c = ASCII_CHAR_RANGE_START; c < N_ASCII_VALUES - 1; ++c) {
    int n_occurrences = histogram[c];

    if (n_occurrences == 0)
      continue;

    printf("%c: ", c);

    for (int i = 0; i < n_occurrences; ++i)
      printf("*");

    printf("\n");
  }

  return 0;
}
