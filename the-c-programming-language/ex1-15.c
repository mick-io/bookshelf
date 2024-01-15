// Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to
// use a function for conversion.

#include <stdio.h>

// Function prototypes
float convert_celsius(float celsius);
float convert_fahrenheit(float fahr);

int main() {
  float fahr, celsius;
  float lower, upper, step;

  char border[] = "|-------------------|";

  lower = 0.0;   // lower limit of temperature table
  upper = 300.0; // upper limit of temperature table
  step = 30.0;   // step size

  printf("%s\n| Celsius |   Fahr  |\n%s\n", border, border);
  for (celsius = lower; celsius <= upper; celsius = celsius + step) {
    fahr = convert_celsius(celsius);
    printf("|  %3.0f    | %6.1f  |\n", celsius, fahr);
  }
  printf("%s\n", border);

  return 0;
}

float convert_celsius(float celsius) {
  float fahr;
  fahr = celsius * (9.0 / 5.0) + 32;
  return fahr;
}

float convert_fahrenheit(float fahr) {
  float celsius;
  celsius = (5.0 / 9.0) * (fahr - 32);
  return celsius;
}
