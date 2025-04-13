#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define M 3  // Filas de A y filas de C
#define N 2  // Columnas de A y filas de B
#define P 3  // Columnas de B y columnas de C

int main() {
    // Reservar memoria
    double **A = (double**) malloc(M * sizeof(double*));
    double **B = (double**) malloc(N * sizeof(double*));
    double **C = (double**) malloc(M * sizeof(double*));

    for (int i = 0; i < M; i++) {
        A[i] = (double*) malloc(N * sizeof(double));
        C[i] = (double*) malloc(P * sizeof(double));
    }
    for (int i = 0; i < P; i++) {
        B[i] = (double*) malloc(P * sizeof(double));
    }

    // Inicializar matrices A y B
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            A[i][j] = 1.0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < P; j++)
            B[i][j] = 2.0;

    // Inicializar matriz C en cero
    for (int i = 0; i < M; i++)
        for (int j = 0; j < P; j++)
            C[i][j] = 0.0;

    double t_ini = omp_get_wtime();

    // Multiplicación de matrices: C = A x B
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) { 
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    double t_fin = omp_get_wtime();

    printf("Tiempo secuencial: %f segundos\n", t_fin - t_ini);

    // Imprimir la matriz resultante C
    printf("Matriz resultante C:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            printf("%f ", C[i][j]);
        }
        printf("\n");
    }

    // Liberar memoria
    for (int i = 0; i < M; i++) {
        free(A[i]);
        free(C[i]);
    }
    for (int i = 0; i < P; i++) {
        free(B[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
