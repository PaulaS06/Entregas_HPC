#include <stdio.h>
#include <stdlib.h>

// Utilizar Structs para definir la estructura de los nodos de la lista enlazada
struct Node {
    int data;
    struct Node* next; // El siguiente nodo corresponde a la dirección de memoria del siguiente nodo (es de tipo struct Node y con la referencia *)
}; 

// NOTA: Para acceder a la estructura es necesario crear una variable de tipo struct Node.

void insertar_nodo_final(struct Node** head, int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Crear un nuevo nodo
    newNode->data = value;  // Asignar el valor al nuevo nodo
    newNode->next = NULL;  // Inicializar el siguiente nodo como NULL

    if (*head == NULL){
        *head = newNode; // Si la lista está vacía, el nuevo nodo es el primero
    }
    else {
        struct Node* current = *head; // Crear un puntero auxiliar para recorrer la lista
        while (current->next != NULL){ // Mientras no haya llegado hasta el último nodo
            current = current->next; // Avanzar al siguiente nodo
        }
        current->next = newNode; // Asignar el nuevo nodo al final de la lista cuando se encuentre en el último nodo
        }
    }

void imprimir_lista(struct Node* head){
    if (head == NULL){ // Verificar si la lista está vacía
        printf("La lista está vacía.\n");
        return;
    }

    struct Node* current = head; // Crear un puntero auxiliar para recorrer la lista
    while (current != NULL){
        printf("%d -> ", current->data); // Imprimir el VALOR del nodo actual
        current = current->next; // Avanzar al siguiente nodo
    }

    printf("NULL\n"); // Indicar el final de la lista cuando se recorra toda
    }

int eliminar_nodo(struct Node** head, int value){
    if (*head == NULL){
        return 0; // La lista está vacía
    }

    struct Node* current = *head; // Crear un puntero auxiliar para recorrer la lista
    struct Node* previous = NULL; // Crear un puntero para el nodo anterior

    while (current != NULL && current->data != value){
        previous = current; // Guardar el nodo anterior
        current = current->next; // Avanzar al siguiente nodo
    }

    if (current == NULL){
        return 1; // El valor no se encontró en la lista
    }

    if (previous == NULL){
        *head = current->next; // El nodo a eliminar es el primero
    }
    else {
        previous->next = current->next; // Eliminar el nodo de la lista
    }

    free(current); // Liberar la memoria del nodo eliminado
    return 0; // El nodo fue eliminado con éxito
    }

int main(){
    struct Node* head = NULL; // Inicializar la lista vacía

    insertar_nodo_final(&head, 10);
    insertar_nodo_final(&head, 20);
    insertar_nodo_final(&head, 30);

    printf("Lista enlazada: ");
    imprimir_lista(head); // Imprimir la lista enlazada

    printf("Eliminando 20...\n");
    eliminar_nodo(&head, 20);
    imprimir_lista(head); // Imprimir la lista enlazada

    return 0;
    
    }