// Exercise 1-8. Write a program to count blanks, tabs, and newlines.

#include <stdio.h>

int main() {
  int c, nl, nt, nb;

  nl = 0, nt = 0, nb = 0;
  while ((c = getchar()) != EOF) {
    switch (c) {
    case ' ':
      ++nb;
      break;
    case '\t':
      ++nt;
      break;
    case '\n':
      ++nl;
      break;
    }
  }

  printf("Number of blanks: %d\n", nb);
  printf("Number of tabs: %d\n", nt);
  printf("Number of line: %d\n", nl);

  return 0;
}
