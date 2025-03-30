#include <stdio.h>

int main() {
    // Definir la variable para el número de términos
    int n = 0;
    int suma = 0; // Inicializar la suma en 0

    // Pedir al usuario que ingrese el número de términos
    printf("Ingrese el número de términos: ");
    scanf("%d", &n);

    // Validar que n sea positivo
    if (n <= 0) {
        printf("El número de términos debe ser positivo.\n");
        return 1; // Salir con un código de error
    }

    // Calcular la suma de los primeros n números naturales
    int i = 1; // Inicializar el contador fuera del bucle
    while (i <= n) {
        suma += i; // Sumar cada número natural
        i++; // Incrementar el contador
    }
    
    // Imprimir el resultado
    printf("La suma de los primeros %d números naturales es: %d\n", n, suma);

    return 0;
}
