// Producto escalar paralelizado
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(){
    int N = 100000000; // Tamaño del vector
    double *A = (double*) malloc(N * sizeof(double));
    double *B = (double*) malloc(N * sizeof(double));
    double dot = 0.0;

    //Inicialización: ejemplo, A[i] = 1.0, B[i] = 2.0
    for (int i = 0; i < N; i++){
        A[i] = 1.0;
        B[i] = 2.0;
    }

    double t_ini = omp_get_wtime();
    #pragma omp parallel for reduction(+:dot)
    for (int i = 0; i < N; i++) {
        dot += A[i] * B[i];
    }
    double t_fin = omp_get_wtime();
    printf("Saliendo del bloque paralelo\n");

    printf("Producto escalar (Paralelizado): %f\n", dot);
    printf("Tiempo paralelismo: %f segundos\n", t_fin - t_ini);

    free(A);
    free(B);
    return 0;
}