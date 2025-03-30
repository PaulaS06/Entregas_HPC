#include <stdio.h>

// main function
int main() {

  // define variables
  double celcius = 0.0;
  double fahrenheit = 0.0;
  double kelvin = 0.0;

  // ask user for input
  printf("Digite una temperatura en grados Celsius: ");

  // store user input
  scanf("%lf", &celcius);

  // convert celcius to fahrenheit and kelvin
  fahrenheit = (celcius * 9/5) + 32;
  kelvin = celcius + 273.15;

  // print results
  printf("%.2f grados Celsius son %.2f grados Fahrenheit\n", celcius, fahrenheit);
  printf("%.2f grados Celsius son %.2f grados Kelvin\n", celcius, kelvin);
  
  // return 0 if everything is ok
  return 0;
}
