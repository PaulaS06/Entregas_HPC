//Código de ordenamiento de burbuja usando índices en C

#include <stdio.h>

// Función para intercambiar dos valores
void intercambiar(int *a, int *b) {
    int temp = *a; // Guardamos el valor de a en temp
    *a = *b; // Asignamos el valor de b a a 
    *b = temp; // Asignamos el valor de temp a b
}

// Función de ordenamiento de burbuja usando índices
void ordenarBurbuja(int arr[], int n) {
    int flag; // Variable para controlar si hubo intercambio
    do {
        flag = 0; // control de que ya está ordenado el array
        for (int i = 0; i < n - 1; i++) { // Recorremos el arreglo
            if (arr[i] > arr[i + 1]) { // Comparar elementos usando índices
                intercambiar(&arr[i], &arr[i + 1]);
                flag = 1; // Hubo un intercambio
            }
        }
    } while (flag == 1); // Repetir mientras haya intercambios
}

// Función para imprimir el arreglo
void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) { // Recorrer el arreglo
        printf("%d ", arr[i]); // Imprimir cada elemento
    }
    printf("\n"); // Salto de línea al final
}

int main() {
    int n;
    printf("Ingrese el tamaño del arreglo: "); // Solicitar al usuario el tamaño del arreglo
    scanf("%d", &n); // Leer el tamaño del arreglo
    
    if (n <= 0) { // Validar que el tamaño sea positivo
        printf("El tamaño del arreglo debe ser mayor que cero.\n");
        return 1; // Salir del programa si el tamaño no es válido
    } 
    
    int arr[n];
    printf("Ingrese %d elementos: ", n); // Solicitar al usuario los elementos del arreglo
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Leer cada elemento del arreglo
    }
    
    printf("Arreglo original: ");
    imprimirArreglo(arr, n); // Imprimir el arreglo original
    
    ordenarBurbuja(arr, n); // Llamar a la función de ordenamiento
    
    printf("Arreglo ordenado: ");
    imprimirArreglo(arr, n); // Imprimir el arreglo ordenado
    
    return 0; // Salir del programa de forma exitosa
}
