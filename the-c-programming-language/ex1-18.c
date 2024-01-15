// Exercise 1-18. Write a program to remove trailing blanks and tabs from each
// line of input, and to delete entirely blank lines.

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *line = NULL;
  size_t len = 0; // length of the line read.
  ssize_t read;   // number of characters read (including delimiter)

  while ((read = getline(&line, &len, stdin)) != -1) {
    int i = read - 1;
    // If the line ends with a newline, start from the character before it
    if (line[i] == '\n')
      --i;

    while (i >= 0 && (line[i] == ' ' || line[i] == '\t'))
      --i;

    // If the line is now empty or contains only a newline
    if (i < 0 || (i == 0 && line[0] == '\n'))
      continue;

    // If the line ended with a newline, put it back
    if (line[read - 1] == '\n') {
      line[i + 1] = '\n';
      line[i + 2] = '\0';
    } else
      line[i + 1] = '\0';

    printf("%s", line);
  }

  free(line);

  return 0;
}
