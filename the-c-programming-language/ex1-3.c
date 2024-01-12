// Exercise 1-3. Modify the temperature conversion program to print a heading
// above the table.

#include <stdio.h>

// print Fahrenheit-Celsius table
// for fahr = 0, 20, ..., 300
int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;   // lower limit of temperature table
  upper = 300; // upper limit of temperature table
  step = 30;   // step size

  printf("Fahr | Celsius\n--------------\n");

  fahr = lower;
  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32);
    printf("%3.0f  | %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}
