#include <stdio.h>

// Crear la función principal
int main() {

    // Definir una variable que el usuario ingresa para establecer las dimensiones de las matrices
    int n;

    printf("Ingrese de que tamaño desea la matriz cuadrada: ");
    scanf("%d", &n);

    // Definir las matrices con su tamaño n
    int matriz1[n][n];
    int matriz2[n][n];
    int suma[n][n];
    
    // Pedir al usuario que ingrese los elementos para generar la primera matriz
    printf("Ingrese los elementos de la primera matriz (%d x %d):\n", n, n);
    // Para esto implementamos un ciclo for anidado que recorre la matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }
    
    // Pedir al usuario que ingrese los elementos para generar la segunda matriz
    printf("Ingrese los elementos de la segunda matriz (%d x %d):\n", n, n);
   // Para esto implementamos un ciclo for anidado que recorre la matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Calcular la suma de las matrices también con un ciclo for anidado que busca recorrer las matrices y se le asigna a la nueva matriz la suma de las dos matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            suma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    // Imprimir la matriz resultante en pantalla
    printf("La suma de las matrices es:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", suma[i][j]);
        }
        printf("\n");
    }

    return 0;
}