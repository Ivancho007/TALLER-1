#include <stdio.h>
 
// Variables globales
int id = 0;
char nombre[50];
int stock = 0;
double precio = 0.0;
double ganancias = 0.0;
 
// Registrar producto
int registrar() {
    printf("\n--- Registro de producto ---\n");
    printf("ID del producto (entero): ");
    scanf("%d", &id);
 
    printf("Nombre del producto (sin espacios): ");
    scanf("%49s", nombre);
 
    printf("Precio unitario: ");
    scanf("%lf", &precio);
 
    printf("Stock inicial: ");
    scanf("%d", &stock);
 
    printf("Producto registrado con éxito.\n");
    return 0;
}
 
// Vender producto
int vender() {
    if (id == 0 || nombre[0] == '\0') {
        printf("Primero registre el producto.\n");
        return 0;
    }
 
    printf("\n--- Venta ---\n");
    printf("Stock actual: %d | Precio unitario: %.2f\n", stock, precio);
 
    int cantidad = 0;
    printf("Cantidad a vender (>0): ");
    scanf("%d", &cantidad);
 
    if (cantidad <= 0) {
        printf("Cantidad inválida.\n");
        return 0;
    }
 
    if (cantidad > stock) {
        printf("No hay stock suficiente. Venta rechazada.\n");
        return 0;
    }
 
    double subtotal = precio * cantidad;
 
    stock -= cantidad;
    ganancias += subtotal;
 
    printf("Venta realizada.\n");
    printf("Unidades: %d | Subtotal: %.2f\n", cantidad, subtotal);
    printf("Stock restante: %d | Ganancias acumuladas: %.2f\n", stock, ganancias);
 
    return 0;
}
 
// Mostrar información
int mostrar() {
    if (id == 0 || nombre[0] == '\0') {
        printf("Primero registre el producto.\n");
        return 0;
    }
 
    printf("\n--- Información del producto ---\n");
    printf("ID: %d\n", id);
    printf("Nombre: %s\n", nombre);
    printf("Precio: %.2f\n", precio);
    printf("Stock: %d\n", stock);
    printf("Ganancias: %.2f\n", ganancias);
    return 0;
}
 
// Menú principal
int main() {
    int opcion = 0;
    do {
        printf("\n=== Menú principal ===\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Mostrar información\n");
        printf("4. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);
 
        switch(opcion) {
            case 1: registrar(); break;
            case 2: vender(); break;
            case 3: mostrar(); break;
            case 4: printf("Saliendo...\n"); break;
            default: printf("Opción inválida.\n");
        }
    } while(opcion != 4);
 
    return 0;
}