// Exercise 1-11. How would you test the word count program? What kinds of input
// are most likely to uncover bugs if there are any?

/*
# I'd test using the following shell commands:

echo "" | ./a.out  # Empty input
echo "word" | ./a.out  # Single word
echo "one two three" | ./a.out  # Multiple words, spaces
echo -e "one\ntwo\nthree" | ./a.out  # Multiple words, newlines
echo -e "one\ttwo\tthree" | ./a.out  # Multiple words, tabs
echo "   one   two   three   " | ./a.out  # Leading, trailing, consecutive
spaces head -c 1000000 /dev/urandom | ./a.out  # Long input
*/

#include <stdio.h>

#define IN 1  // inside a word
#define OUT 0 // outside a word

// counts lines, words, and characters in input
int main() {
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }

  printf("%d %d %d\n", nl, nw, nc);

  return 0;
}
