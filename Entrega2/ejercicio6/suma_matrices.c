#include <stdio.h>
#include <stdlib.h>

int capturar_tamaño() {
    // Definir una variable que el usuario ingresa para establecer las dimensiones de las matrices
    int n;

    printf("Ingrese de que tamaño desea la matriz: ");
    scanf("%d", &n);

    // Validar que el tamaño sea positivo
    if (n <= 0) {
        printf("El tamaño de la matriz debe ser positivo.\n");
        return 0; // Salir con un código de error
    }

    return n; // Retornar el tamaño de la matriz
}

int** capturar_matriz(int n) {

    // Reservar memoria dinámica para la matriz
    int** matriz = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matriz[i] = (int*)malloc(n * sizeof(int));
    }

    // Pedir al usuario que ingrese los elementos para generar la primera matriz
    printf("Ingrese los elementos de la primera matriz (%d x %d):\n", n, n);
    // Para esto implementamos un ciclo for anidado que recorre la matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    return matriz; 
}

void liberar_matriz(int** matriz, int n) {
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int main(int n) {

    // Llamar a la función para capturar el tamaño de la matriz
    n = capturar_tamaño();

    // Definir las matrices con su tamaño n
    int** matriz1 = capturar_matriz(n);
    int** matriz2 = capturar_matriz(n);

    // Asignar memoria dinamica para la matriz suma
    int** suma = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        suma[i] = (int*)malloc(n * sizeof(int));
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

    // Liberar la memoria de las matrices
    liberar_matriz(matriz1, n);
    liberar_matriz(matriz2, n);
    liberar_matriz(suma, n);

    return 0;
}