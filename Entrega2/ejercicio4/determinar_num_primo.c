#include <stdio.h>
#include <stdbool.h> // Para usar el tipo bool
#include <math.h> // Para usar la función sqrt

// determinar si un número es primo - recibir el número como parámetro
bool esPrimo(int n) {
    if (n <= 1) {
        return false; // Los números menores o iguales a 1 no son primos
    }
    if (n == 2 || n == 3) {
        return true; // 2 y 3 son primos
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false; // Si es divisible por 2 o 3, no es primo
    }
    // Verificar divisores desde hasta √n
    for (int i = 4; i < sqrt(n); i ++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int numero;

    printf("Ingrese un número entero positivo mayor que 1: ");
    scanf("%d", &numero);

    if (esPrimo(numero)) {
        printf("%d es un número primo.\n", numero);
    } else {
        printf("%d no es un número primo.\n", numero);
    }

    return 0;
}