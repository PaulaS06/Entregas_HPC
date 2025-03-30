#include <stdio.h>
#include <math.h> 

int main() {
    // Definir las variables 
    double base = 0.0;
    double lado_a = 0.0;
    double lado_b = 0.0;
    double semiperimetro = 0.0;
    double area = 0.0;

    // Pedir al usuario que ingrese la base y los lados del triángulo
    printf("Ingrese la base del triángulo: ");
    scanf("%lf", &base);
    printf("Ingrese el lado a del triángulo: ");
    scanf("%lf", &lado_a);
    printf("Ingrese el lado b del triángulo: ");
    scanf("%lf", &lado_b);

    // Validar que los lados sean positivos
    if (base <= 0 || lado_a <= 0 || lado_b <= 0) {
        printf("Los lados del triángulo deben ser positivos.\n");
        return 1; // Salir con un código de error
    }

    // Validar que la suma de dos lados sea mayor que el tercero
    if (base + lado_a <= lado_b || base + lado_b <= lado_a || lado_a + lado_b <= base) {
        printf("Los lados ingresados no forman un triángulo válido.\n");
        return 1; // Salir con un código de error
    }

    // Calcular el semiperímetro
    semiperimetro = (base + lado_a + lado_b) / 2.0;

    // Calcular el área usando la fórmula de Herón
    area = sqrt(semiperimetro * (semiperimetro - base) * (semiperimetro - lado_a) * (semiperimetro - lado_b));

    // Imprimir el área
    printf("El área del triángulo es: %.2f\n", area);
}