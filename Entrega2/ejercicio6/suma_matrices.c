#include <stdio.h>

int main() {
    // Definir las dimensiones de las matrices
    int n;

    printf("Ingrese de que tamaño desea la matriz cuadrada: ");
    scanf("%d", &n);

    // Definir las matrices
    int matriz1[n][n];
    int matriz2[n][n];
    int suma[n][n];
    
    // Pedir al usuario que ingrese los elementos de la primera matriz
    printf("Ingrese los elementos de la primera matriz (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }
    
    // Pedir al usuario que ingrese los elementos de la segunda matriz
    printf("Ingrese los elementos de la segunda matriz (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Calcular la suma de las matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            suma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    // Imprimir la matriz resultante
    printf("La suma de las matrices es:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", suma[i][j]);
        }
        printf("\n");
    }

    return 0;
}