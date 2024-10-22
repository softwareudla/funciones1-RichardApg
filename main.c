#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Sistema de inventario de una tienda

int main() {
    // Declarar variables
    char nombre[10][20];
    float precio[10];
    int cantidad[10];
    float total = 0;
    float promedio = 0;
    float max = 0;
    float min = 0;
    int i = 0;
    int opcion;
    char continuar;

    // Ingresar productos hasta que le pida que pare
    do {
        agregarProducto(nombre, precio, cantidad, i);
        i++;
        if (i < 10) {
            printf("¿Desea ingresar otro producto? (s/n): ");
            scanf(" %c", &continuar);
            getchar();  // Limpiar el buffer
        }
    } while (continuar == 's' && i < 10);

    // Menú
    do {
        printf("Ingrese una opcion:\n");
        printf("1. Calcular el precio total del inventario.\n");
        printf("2. Encontrar el producto mas caro.\n");
        printf("3. Encontrar el producto mas barato.\n");
        printf("4. Promedio de los productos.\n");
        printf("5. Buscar un producto por su nombre y mostrar su precio.\n");
        printf("6. Salir.\n");
        scanf("%d", &opcion);
        getchar();  // Limpiar el buffer

        switch(opcion) {
            case 1:
                total = calcularPrecioTotal(precio, cantidad, i);
                printf("El precio total del inventario es: %.2f\n", total);
                break;
            case 2:
                max = encontrarProductoMasCaro(precio, cantidad, i);
                printf("El producto mas caro es: %.2f\n", max);
                break;
            case 3:
                min = encontrarProductoMasBarato(precio, cantidad, i);
                printf("El producto mas barato es: %.2f\n", min);
                break;
            case 4:
                promedio = calcularPrecioPromedio(precio, cantidad, i);
                printf("El precio promedio de los productos es: %.2f\n", promedio);
                break;
            case 5:
                buscarProducto(nombre, precio, cantidad, i);
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida\n");
                break;
        }
    } while (opcion != 6);

    return 0;
}
