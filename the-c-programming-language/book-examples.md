# The C Programming Language Code Examples

## Chapter 1

### 1.1 Getting Started

##### Hello World

```c
#include <stdio.h>

int main() {
    printf("hello, world");
}
```

```c
#include <stdio.h>

int main() {
  printf("hello,");
  printf(" world");
  printf("\n");
}
```

### 1.2 Variables and Arithmetic Expressions

##### Fahrenheit Celsius Tables (Integers)

```c
#include <stdio.h>

// print Fahrenheit-Celsius table
int main () {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}
```

##### Fahrenheit Celsius Tables (Floating Points)

```c
#include <stdio.h>

// print Fahrenheit-Celsius table
int main() {
  int fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%d\t%d\n", fahr, celsius);
    fahr = fahr + step;
  }
}
```

### 1.3 The For Statement

##### Fahrenheit Celsius Tables (for loop)

```c
#include <stdio.h>

// print Fahrenheit-Celsius table
int main() {
  int fahr;

  for (fahr = 0; fahr <= 300; fahr = fahr + 20)
    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}
```

### 1.4 Symbolic Constants

##### Fahrenheit Celsius Tables (with constants)

```c
#include <stdio.h>

#define LOWER 0   //  lower limit of table 
#define UPPER 300 //  upper limit 
#define STEP 20   //  step size 

// print Fahrenheit-Celsius table
int main() {
  int fahr;

  for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}
```

### 1.5 Character Input and Output

#### 1.5.1 File Copying

##### Copy Input to Output; 1st version

```c
#include <stdio.h>

// copy input to output; 1st version
int main() {
  int c;

  c = getchar();
  while (c != EOF) {
    putchar(c);
    c = getchar();
  }
}

```

##### Copy Input to Output; 2nd version

```c
#include <stdio.h>

// copy input to output; 2nd version;
int main() {
  int c;

  while ((c = getchar()) != EOF) {
    putchar(c);
  }
}
```

#### 1.5.2 Character Counting

##### Count Characters; 1st Version

```c
#include <stdio.h>

// count characters in input; 1st version
int main() {
  long nc;

  nc = 0;
  while (getchar() != EOF) {
    ++nc;
    printf("%ld\n", nc);
  }
}
```

##### Count Characters; 2nd Version

```c
#include <stdio.h>

// count characters in input; 2nd version
int main() {
  double nc;

  for (nc = 0; getchar() != EOF; nc++)
    ;
  printf("%.0f\n", nc);
}
```

#### 1.5.3 Line Counting

##### Count lines In Input

```c
#include <stdio.h>

// count lines in input
int main() {
  int c, nl;

  nl = 0;
  while ((c = getchar()) != EOF)
    if (c == '\n')
      ++nl;
  printf("%d\n", nl);
}
```

#### 1.5.4 Word Counting

##### Count Lines, Words, and Characters in Input

```c
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
}
```

### 1.6 Arrays

##### Count Digits, White Space, and Others

```c
#include <stdio.h>

// count digits, white space, others
int main() {
  int c, i, n_white, n_other;
  int n_digit[10];

  n_white = n_other = 0;
  for (i = 0; i < 10; ++i)
    n_digit[i] = 0;

  while ((c = getchar()) != EOF)
    if (c >= '0' && c <= '9')
      ++n_digit[c - '0'];
    else if (c == ' ' || c == '\n' || c == '\t')
      ++n_white;
    else
      ++n_other;

  printf("digits=");
  for (i = 0; i < 10; ++i)
    printf("%d", n_digit[i]);
  printf(", white space = %d, other = %d\n", n_white, n_other);
}
```

### 1.7 Functions

##### Power Function

```c
#include <stdio.h>

int power(int m, int n);

// test power function
int main() {
  int i;
  for (i = 0; i < 10; ++i)
    printf("%d %d %d\n", i, power(2, i), power(-3, i));

  return 0;
}

// power: raise base n-th power; n >=0
int power(int base, int n) {
  int i, p;
  p = 1;

  for (i = 1; i <= n; ++i)
    p = p * base;

  return p;
}
```

### 1.8 Arguments -- Call by Value

##### Power Function Version 2

```c
// power; raise base to n-th power n >= 0; version 2
int power(int base, int n) {
  int p;
  for (p = 1; p > 0; --n)
    p = p * base;
  return p;
}
```

### 1.9 Character Arrays

##### Print longest line

```c
#include <stdio.h>

#define MAX_LINE 1000 // maximum input line size

int getline(char line[], int max_line);
void copy(char to[], char from[]);

// print longest input line
int main() {
  int len;                // current line length
  int max;                // maximum line seen so far.
  char line[MAX_LINE];    // current input line
  char longest[MAX_LINE]; // longest line saved here

  max = 0;
  while ((len = getline(line, MAX_LINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  // if there was a line
  if (max > 0) {
    printf("%s", longest);
  }

  return 0;
}

// getline: read a line into s, return length
int getline(char s[], int lim) {
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
```

### 1.10 External Variables and Scope

##### Print Longest Input Line; External Variables Version

```c
#include <stdio.h>

#define MAX_LINE 1000 // maximum input line size

int max;
char line[MAX_LINE];    // current input line
char longest[MAX_LINE]; // longest line saved

int getline_local(void);
void copy(void);

// print longest input line; specialized version
int main() {
  int len;
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = getline_local()) > 0) {
    if (len > max) {
      max = len;
      copy();
    }
  }
  // if there was a line
  if (max > 0) {
    printf("%s", longest);
  }

  return 0;
}

// getline: specialized version
int getline_local(void) {
  int c, i;
  extern char line[];

  for (i = 0; i < MAX_LINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;
}

// copy: specialized version
void copy(void) {
  int i;
  extern char line[], longest[];

  i = 0;
  while ((longest[i] = line[i]) != '\0') {
    ++i;
  }
}

```
