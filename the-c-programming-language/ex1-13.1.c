// Exercise 1-13. Write a program to print a histogram of the lengths of words
// in its input. It is easy to draw the histogram with the bars horizontal; a
// vertical orientation is more challenging.

#include <stdio.h>

#define CHAR_LIMIT 45 // The longest english word is 45 characters longs

int main() {
  int c, word_length;
  int histogram[CHAR_LIMIT] = {0};

  word_length = 0;
  do {
    c = getchar();
    // If not whitespace, increment stored word length.
    if (c != ' ' && c != '\n' && c != '\t' && c != EOF) {
      ++word_length;
      continue;
    }

    // Ignoring repeat whitespace.
    if (word_length == 0)
      continue;

    // Excluding word lengths that exceeds the character limit.
    if (word_length <= CHAR_LIMIT) {
      ++histogram[word_length];
    } else {
      printf("WARN: Word exceeds max character limit\n");
    }

    // Resetting world length
    word_length = 0;
  } while (c != EOF);

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
