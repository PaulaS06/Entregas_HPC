#include <stdio.h>
#include <stdlib.h>

// Utilizar Structs para definir la estructura de los Nodes de la lista enlazada
struct Node {
    int data;
    struct Node* next; // El siguiente Node corresponde a la dirección de memoria del siguiente Node (es de tipo struct Node y con la referencia *)
}; 

// Función para insertar un elemento (push)
void push(struct Node** pila, int valor) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Asignar memoria para el nuevo nodo auxiliar 
    if (newNode == NULL) { // verificar si se pudo asignar memoria
        printf("Error: No se pudo asignar memoria.\n");
        return;
    }
    newNode->data = valor; // Asignar el valor al nuevo nodo
    newNode->next = *pila;  // enlazar el nuevo nodo al tope de la pila
    *pila = newNode; // Actualizar el tope de la pila
    printf("Elemento %d agregado a la pila.\n", valor); // Mensaje de éxito
}

// Función para eliminar un elemento (pop)
int pop(struct Node** pila) {
    if (*pila == NULL) {
        printf("Error: Pila vacía\n");
        return 1;  // Retorna 1 si la pila está vacía, no fue exitoso
    }
    struct Node* temp = *pila; // Guardar el nodo a eliminar en un nodo temporal
    int valor = temp->data; // Guardar el valor del nodo a eliminar para poder retornarlo
    *pila = temp->next;  // Actualizar el tope de la pila al siguiente nodo del eliminado
    free(temp); // Liberar memoria del nodo eliminado
    return valor; // Retornar el valor del nodo eliminado
}

// Función para mostrar la pila
void mostrar(struct Node* pila) {
    if (pila == NULL) {
        printf("Pila vacía\n");
        return; // Si la pila está vacía, no hay nada que mostrar
    }

    printf("Estado de la pila:\n"); 
    struct Node* actual = pila; // Crear un nodo auxiliar para recorrer la pila
    while (actual != NULL) { // Mientras no se llegue al final de la pila
        printf("%d\n", actual->data); // Imprimir el valor del nodo actual
        actual = actual->next; // Mover al siguiente nodo con el next(puntero al siguiente nodo)
    }
}

// Liberar toda la memoria de la pila
void liberarPila(struct Node** pila) {
    while (*pila != NULL) { // Mientras la pila no esté vacía
        struct Node* temp = *pila; // Guardar el nodo a liberar en un nodo temporal
        *pila = temp->next; // Actualizar el tope de la pila al siguiente nodo
        free(temp); // Liberar memoria del nodo eliminado
    }
}

// Función principal
int main() {
    struct Node* pila = NULL; // Inicializar la pila como NULL (vacía)

    // Pruebas
    push(&pila, 5);
    push(&pila, 10);
    push(&pila, 15); // Agregar 3 elementos a la pila
    mostrar(pila); // Mostrar la pila después de los push realizados

    printf("\nPop: %d\n", pop(&pila));  // Eliminar un elemento de la pila y mostrar el valor eliminado
    mostrar(pila);

    printf("\nPop: %d\n", pop(&pila));
    mostrar(pila);

    printf("\nPop: %d\n", pop(&pila));
    mostrar(pila);

    liberarPila(&pila);  // Limpieza final de la pila para liberar la memoria ocupada
    return 0; // Retornar 0 para indicar que el programa se ejecutó exitosamente
}