#include <stdio.h>

// Declaración de funciones
float sumar(float a, float b) {
    return a + b; // Definición de la función sumar
}

float restar(float a, float b) {
    return a - b; // Definición de la función restar
}

float multiplicar(float a, float b) {
    return a * b; // Definición de la función multiplicar
}

float dividir(float a, float b) {
    if (b == 0) { // Manejo de error para división por cero
        printf("Error: División por cero\n");
        return 1;
    }
    return a / b; // Definición de la función dividir
}

// Función calcular que recibe operador y operandos
void calcular(char operador, float x, float y) {
    // Declarar puntero a función que reciba dos floats y devuelva float
    float (*operacion)(float, float) = NULL;

    // Asignar la función al puntero según el operador
    if (operador == '+') {
        operacion = sumar;
    } else if (operador == '-') {
        operacion = restar;
    } else if (operador == '*') {
        operacion = multiplicar;
    } else if (operador == '/') {
        operacion = dividir;
    } else {
        printf("Operador no válido.\n");
        return; // definir los condicionales para identificar la operación que se va a realizar
    }

    // Ejecutar la función a través del puntero
    float resultado = operacion(x, y); // Llamar a la función correspondiente
    printf("Resultado: %.2f\n", resultado); // Imprimir el resultado
}

int main() {
    float x, y;
    char operador;

    // Leer entrada del usuario
    printf("Ingrese el primer número: ");
    scanf("%f", &x); // Leer el primer número

    printf("Ingrese el segundo número: ");
    scanf("%f", &y); // Leer el segundo número

    printf("Ingrese el operador (+, -, *, /): ");
    scanf(" %c", &operador); // Leer el operador

    calcular(operador, x, y); // Llamar a la función calcular con los valores ingresados

    return 0; // Retornar 0 para indicar que el programa terminó correctamente
}