#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Funciones de conversión
int binario_a_decimal(int numero_binario) {
    int numero_decimal = 0, base = 1, digito;
    while (numero_binario != 0) {
        digito = numero_binario % 10;
        numero_decimal += digito * base;
        numero_binario /= 10;
        base *= 2;
    }
    return numero_decimal;
}

int decimal_a_binario(int numero_decimal) {
    int numero_binario = 0, resto, i = 1;
    while (numero_decimal != 0) {
        resto = numero_decimal % 2;
        numero_decimal /= 2;
        numero_binario += resto * i;
        i *= 10;
    }
    return numero_binario;
}

// Funciones para operaciones aritméticas en diferentes bases
int suma_base(int num1, int num2, int base) {
    return num1 + num2;
}

int resta_base(int num1, int num2, int base) {
    return num1 - num2;
}

int multiplicacion_base(int num1, int num2, int base) {
    return num1 * num2;
}

int division_base(int num1, int num2, int base) {
    if (num2 == 0) {
        printf("Error: división por cero.\n");
        return 0;
    } else {
        return num1 / num2;
    }
}

int main() {
    int opcion, base, num1, num2, resultado;
    
    printf("Seleccione la base numérica (2 = binario, 10 = decimal, 16 = hexadecimal): ");
    scanf("%d", &base);

    printf("Operaciones disponibles:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicación\n");
    printf("4. División\n");
    printf("Ingrese el número de la operación deseada: ");
    scanf("%d", &opcion);

    printf("Ingrese el primer número: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);

    switch (opcion) {
        case 1:
            resultado = suma_base(num1, num2, base);
            break;
        case 2:
            resultado = resta_base(num1, num2, base);
            break;
        case 3:
            resultado = multiplicacion_base(num1, num2, base);
            break;
        case 4:
            resultado = division_base(num1, num2, base);
            break;
        default:
            printf("Opción no válida.\n");
            return 1;
    }

    if (base == 16) {
        printf("Resultado: %X\n", resultado);
    } else {
        printf("Resultado: %d\n", resultado);
    }

    return 0;
}

