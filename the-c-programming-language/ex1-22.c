// Exercise 1-22. Write a program to “fold” long input lines into two or more
// shorter lines after the last non-blank character that occurs before the n-th
// column of input. Make sure your program does something intelligent with very
// long lines, and if there are no blanks or tabs before the specified column.

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 50

int main() {

  char *line = NULL;
  size_t len = 0; // length of the line read.
  ssize_t read;   // number of characters read (including delimiter)

  while ((read = getline(&line, &len, stdin)) != -1) {
    int last_whitespace_index = -1;
    int c;

    for (int i = 0; i < read; i = last_whitespace_index + 1) {
      // finding last whitespace index.
      for (int j = 0; j < MAX_LENGTH; ++j) {
        c = line[i + j];
        if (c == '\t' || c == ' ' || c == '\0') {
          last_whitespace_index = i;
          if (c == '\0')
            break;
        }
      }

      for (int k = i; k < last_whitespace_index; ++k)
        putchar(line[k]);

      putchar('\n');
    }
  }

  free(line);
  return 0;
}
