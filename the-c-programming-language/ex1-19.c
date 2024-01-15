// Exercise 1-19. Write a function reverse(s) that reverses the character
// string s. Use it to write a program that reverses its input a line at a time.

#include <stdio.h>
#include <stdlib.h>

void reverse(char s[], int len);

int main() {
  char *line = NULL;
  size_t len = 0; // length of the line read.
  ssize_t read;   // number of characters read (including delimiter)

  printf("Enter a line of text:\n");

  read = getline(&line, &len, stdin);
  if (read == -1) {
    free(line);
    return 1;
  }

  reverse(line, read);
  printf("%s\n", line);

  free(line);

  return 0;
}

void reverse(char s[], int len) {
  int start = 0;
  int end = len - 1;

  while (start < end) {
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;

    ++start;
    --end;
  }
}
