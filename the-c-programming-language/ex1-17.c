// Exercise 1-17. Write a program to print all input lines that are longer than
// 80 characters.

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *line = NULL;
  size_t len = 0; // length of the line read.
  ssize_t read;   // number of characters read (including delimiter)

  while ((read = getline(&line, &len, stdin)) != -1) {
    if (read > 80) {
      printf("%s", line);
    }
  }

  free(line);

  return 0;
}
