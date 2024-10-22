#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Función para agregar productos
void agregarProducto(char nombre[10][20], float precio[10], int cantidad[10], int i){
    printf("Ingrese el nombre del producto: ");
    fgets(nombre[i], 20, stdin);
    nombre[i][strcspn(nombre[i], "\n")] = 0;  // Eliminar el salto de línea

    // Validar que el precio sea positivo
    do {
        printf("Ingrese el precio del producto (no puede ser negativo): ");
        scanf("%f", &precio[i]);
        if (precio[i] < 0) {
            printf("Error: El precio no puede ser negativo.\n");
        }
    } while (precio[i] < 0);

    // Validar que la cantidad sea positiva
    do {
        printf("Ingrese la cantidad del producto (no puede ser negativa): ");
        scanf("%d", &cantidad[i]);
        if (cantidad[i] < 0) {
            printf("Error: La cantidad no puede ser negativa.\n");
        }
    } while (cantidad[i] < 0);
    getchar(); // Limpiar el buffer de entrada
}

// Función para calcular el precio total
float calcularPrecioTotal(float precio[10], int cantidad[10], int i){
    float total = 0;
    for(int j = 0; j < i; j++){
        total += precio[j] * cantidad[j];
    }
    return total;
}

// Función para calcular el precio promedio
float calcularPrecioPromedio(float precio[10], int cantidad[10], int i){
    float promedio = 0;
    for(int j = 0; j < i; j++){
        promedio += precio[j] * cantidad[j];
    }
    promedio /= i;
    return promedio;
}

// Función para encontrar el producto más caro
float encontrarProductoMasCaro(float precio[10], int cantidad[10], int i){
    float max = 0;
    for(int j = 0; j < i; j++){
        if(precio[j] > max){
            max = precio[j];
        }
    }
    return max;
}

// Función para encontrar el producto más barato
float encontrarProductoMasBarato(float precio[10], int cantidad[10], int i){
    float min = precio[0];
    for(int j = 1; j < i; j++){
        if(precio[j] < min){
            min = precio[j];
        }
    }
    return min;
}

// Función para buscar un producto por su nombre
void buscarProducto(char nombre[10][20], float precio[10], int cantidad[10], int i) {
    char buscar[20];
    printf("Ingrese el nombre del producto a buscar:\n ");
    fgets(buscar, 20, stdin);
    buscar[strcspn(buscar, "\n")] = 0;  // Eliminar el salto de línea
    
    int encontrado = 0;  // Variable para verificar si se encontró el producto

    for(int j = 0; j < i; j++) {
        if(strcmp(nombre[j], buscar) == 0) {
            printf("El producto %s tiene un precio de %.2f y una cantidad de %d\n", nombre[j], precio[j], cantidad[j]);
            encontrado = 1;  // Marcar como encontrado
            break;  // Salir del bucle una vez encontrado
        }
    }
    
    // Mensaje de producto no encontrado
    if (!encontrado) {
        printf("El producto no se encuentra en este inventario\n");
    }
}