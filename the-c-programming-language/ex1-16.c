// Exercise 1-16. Revise the main routine of the longest-line program so it will
// correctly print the length of arbitrarily long input lines, and as much as
// possible of the text.

#include <stdio.h>

#define MAX_LINE 1000 // maximum input line size

int getline_local(char line[], int max_line);
void copy(char to[], char from[]);

// print longest input line
int main() {
  int len;                // curent line length
  int max;                // maximum line seen so far.
  char line[MAX_LINE];    // current input line
  char longest[MAX_LINE]; // longest line saved here

  max = 0;
  while ((len = getline_local(line, MAX_LINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  // if there was a line
  if (max > 0) {
    printf("Length of longest line: %d\n", max);
    printf("Segment of longest line: %s", longest);
  }

  return 0;
}

// getline: read a line into s, return length
int getline_local(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

// copy: copy 'from' into 'to'; assume 'to' is big enough
void copy(char to[], char from[]) {
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
