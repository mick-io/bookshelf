// Write a program entab that replaces strings of blanks by the minimum number
// of tabs and blanks to achieve the same spacing. Use the same tab stops as for
// detab. When either a tab or a single blank would suffice to reach a tab stop,
// which should be given preference?

#include <stdio.h>

#define TAB_STOP 4

int main() {
  int c, n_spaces;

  n_spaces = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++n_spaces;
      continue;
    }

    while (n_spaces / TAB_STOP >= 1) {
      putchar('\t');
      n_spaces = n_spaces - TAB_STOP;
    }

    while (n_spaces > 0) {
      putchar(' ');
      --n_spaces;
    }

    putchar(c);
  }

  return 0;
}
