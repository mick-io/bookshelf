// Exercise 1-9. Write a program to copy its input to its output, replacing
// each string of one or more blanks by a single blank.

#include <stdio.h>

int main() {
  int c, last_c;

  last_c = -1;

  while ((c = getchar()) != EOF) {
    if (c != ' ' || last_c != ' ') {
      putchar(c);
    }
    last_c = c;
  }

  return 0;
}
