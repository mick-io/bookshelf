// Exercise 1-23. Write a program to remove all comments from a C program. Don’t
// forget to handle quoted strings and character constants properly. C comments
// do not nest.

#include <stdbool.h>
#include <stdio.h>

int main() {
  int c = -1, d = -1;
  bool in_line_comment = false, in_comment = false, in_quote = false;

  while ((c = getchar()) != EOF) {
    if (in_comment) {
      if (c == '*' && getchar() == '/') {
        in_comment = false;
      }
      continue;
    }

    if (in_line_comment) {
      if (c == '\n') {
        in_line_comment = false;
        putchar(c);
      }
      continue;
    }

    if (c == '"') {
      in_quote = !in_quote;
    }

    if (!in_quote && c == '/') {
      d = getchar();
      if (d == '*') {
        in_comment = true;
        continue;
      }
      if (d == '/') {
        in_line_comment = true;
        continue;
      }

      putchar(c);
      if (d != EOF) {
        putchar(d);
      }

      continue;
    }

    putchar(c);
  }

  return 0;
}
