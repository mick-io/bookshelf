// Exercise 1-13. Write a program to print a histogram of the lengths of words
// in its input. It is easy to draw the histogram with the bars horizontal; a
// vertical orientation is more challenging.

#include <stdio.h>

#define CHAR_LIMIT 45 // The longest english word is 45 characters longs

int main() {
  int c, word_length, max_frequency, max_length;
  int histogram[CHAR_LIMIT] = {0};

  word_length = max_length = max_frequency = 0;
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
      // Storing the longest word length
      if (word_length > max_length)
        max_length = word_length;
      // Storing the most frequent word length
      if (histogram[word_length] > max_frequency)
        max_frequency = histogram[word_length];
    } else {
      printf("WARN: Word exceeds max character limit\n");
    }

    // Resetting world length
    word_length = 0;
  } while (c != EOF);

  // Printing the vertical histogram
  for (int freq = max_frequency; freq > 0; freq--) {
    for (int i = 1; i <= max_length; i++) {
      if (histogram[i] >= freq) {
        printf("* ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  // Print word length labels
  for (int i = 1; i <= max_length; i++) {
    printf("%d ", i);
  }
  printf("\n");

  return 0;
}
