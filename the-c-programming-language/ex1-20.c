// Exercise 1-20. Write a program detab that replaces tabs in the input with
// the proper number of blanks to space to the next tab stop. Assume a fixed set
// of tab stops, say every n columns. Should n be a variable or a symbolic
// parameter?

#include <stdio.h>
#include <stdlib.h>

#define TAB_STOP 4

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    if (c != '\t') {
      putchar(c);
      continue;
    }
    for (int j = 0; j < TAB_STOP; j++)
      putchar(' ');
  }
}
