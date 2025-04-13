#include <stdio.h>
#include <stdlib.h>
#include <omp.h> // Aunque no usamos paralelismo, se usa para medir tiempo

#define M 1000 // Número de filas
#define N 1000 // Número de columnas

int main() {
    // Reservar memoria
    double **A = (double**) malloc(M * sizeof(double*));
    double **B = (double**) malloc(M * sizeof(double*));
    double **C = (double**) malloc(M * sizeof(double*));

    for (int i = 0; i < M; i++) {
        A[i] = (double*) malloc(N * sizeof(double));
        B[i] = (double*) malloc(N * sizeof(double));
        C[i] = (double*) malloc(N * sizeof(double));
    }

    // Inicializar matrices A y B
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 1.0;
            B[i][j] = 2.0;
        }
    }

    double t_ini = omp_get_wtime();

    // Suma de matrices: C = A + B
    #pragma omp parallel for  // Paralelizar la suma de matrices
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    double t_fin = omp_get_wtime();


    printf("Tiempo paralelismo: %f segundos\n", t_fin - t_ini);

    // Liberar memoria
    for (int i = 0; i < M; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
