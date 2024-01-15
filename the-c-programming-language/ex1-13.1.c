// Exercise 1-13. Write a program to print a histogram of the lengths of words
// in its input. It is easy to draw the histogram with the bars horizontal; a
// vertical orientation is more challenging.

#include <stdio.h>
#include <stdlib.h>

#define CHAR_LIMIT 45 // The longest english word has 45 characters

int main() {
  int c, n_chars;
  int histogram[CHAR_LIMIT] = {0};

  n_chars = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (n_chars > CHAR_LIMIT) {
        printf("ERROR: word exceeds max character limit\n");
        return 1;
      }
      ++histogram[n_chars];
      n_chars = 0;
    } else {
      ++n_chars;
    }
  }

  for (int i = 1; i < CHAR_LIMIT; ++i) {
    if (histogram[i] > 0) {
      printf("%2d: ", i);
      for (int j = 0; j < histogram[i]; ++j) {
        printf("*");
      }
      printf("\n");
    }
  }

  return 0;
}
