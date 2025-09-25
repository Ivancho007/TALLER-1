#include <stdio.h>
 
int main() {
    // Variables
    int id = 0;
    char nombre[50];
    int stock = 0;
    double precio = 0.0;
    double ganancias = 0.0;
    int opcion;
 
    // Registro inicial del producto
    printf("=== Registro del producto ===\n");
    printf("ID del producto (entero): ");
    scanf("%d", &id);
 
    printf("Nombre del producto (sin espacios): ");
    scanf("%49s", nombre);
 
    printf("Precio unitario: ");
    scanf("%lf", &precio);
 
    printf("Stock inicial: ");
    scanf("%d", &stock);
 
    printf("Producto registrado con éxito.\n");
 
    // Menú principal
    do {
        printf("\n=== Menú principal ===\n");
        printf("1. Registrar/Editar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer stock\n");
        printf("4. Mostrar información\n");
        printf("5. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);
 
        if (opcion == 1) {
            // Registrar/editar
            printf("\n--- Registrar/Editar producto ---\n");
            printf("ID del producto (entero): ");
            scanf("%d", &id);
 
            printf("Nombre del producto (sin espacios): ");
            scanf("%49s", nombre);
 
            printf("Precio unitario: ");
            scanf("%lf", &precio);
 
            printf("Stock inicial: ");
            scanf("%d", &stock);
 
            printf("Producto actualizado.\n");
        }
        else if (opcion == 2) {
            // Vender
            if (id == 0 || nombre[0] == '\0') {
                printf("Primero registre el producto.\n");
                continue;
            }
 
            printf("\n--- Venta ---\n");
            printf("Stock actual: %d | Precio unitario: %.2f\n", stock, precio);
 
            int cantidad;
            printf("Cantidad a vender (>0): ");
            scanf("%d", &cantidad);
 
            if (cantidad <= 0) {
                printf("Cantidad inválida.\n");
                continue;
            }
 
            if (cantidad > stock) {
                printf("No hay stock suficiente. Venta rechazada.\n");
                continue;
            }
 
            double subtotal = precio * cantidad;
            stock -= cantidad;
            ganancias += subtotal;
 
            printf("Venta realizada.\n");
            printf("Unidades: %d | Subtotal: %.2f\n", cantidad, subtotal);
            printf("Stock restante: %d | Ganancias acumuladas: %.2f\n", stock, ganancias);
        }
        else if (opcion == 3) {
            // Reabastecer
            if (id == 0 || nombre[0] == '\0') {
                printf("Primero registre el producto.\n");
                continue;
            }
 
            int agregar;
            printf("\n--- Reabastecer stock ---\n");
            printf("Cantidad a agregar (>0): ");
            scanf("%d", &agregar);
 
            if (agregar <= 0) {
                printf("Cantidad inválida.\n");
                continue;
            }
 
            stock += agregar;
            printf("Stock actualizado: %d\n", stock);
        }
        else if (opcion == 4) {
            // Mostrar información
            if (id == 0 || nombre[0] == '\0') {
                printf("Primero registre el producto.\n");
                continue;
            }
 
            printf("\n--- Información del producto ---\n");
            printf("ID: %d\n", id);
            printf("Nombre: %s\n", nombre);
            printf("Precio: %.2f\n", precio);
            printf("Stock: %d\n", stock);
            printf("Ganancias: %.2f\n", ganancias);
        }
        else if (opcion == 5) {
            printf("Saliendo del programa...\n");
        }
        else {
            printf("Opción inválida.\n");
        }
 
    } while (opcion != 5);
 
    return 0;
}