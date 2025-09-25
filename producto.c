#include <stdio.h>
#include <string.h>
 
int main() {
    int id, stock, opcion, cantidad;
    char nombre[50];
    float precio, ganancias = 0, descuento, subtotal;
 
    // Registro inicial
    printf("Ingrese ID del producto(entero): ");
    scanf("%d", &id);
    getchar(); // limpiar buffer
 
    printf("Ingrese nombre del producto: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = 0; // eliminar salto de línea
 
    printf("Ingrese cantidad inicial en stock: ");
    scanf("%d", &stock);
 
    printf("Ingrese precio unitario: ");
    scanf("%f", &precio);
 
    do {
        printf("\n--- MENU ---\n");
        printf("1. Vender producto\n");
        printf("2. Reabastecer producto\n");
        printf("3. Consultar producto\n");
        printf("4. Consultar ganancias\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
 
        switch (opcion) {
            case 1: // Vender
                printf("Ingrese cantidad a vender: ");
                scanf("%d", &cantidad);
 
                if (cantidad <= 0) {
                    printf("Cantidad invalida.\n");
                } else if (cantidad > stock) {
                    printf("Stock insuficiente.\n");
                } else {
                    printf("Ingrese descuento (0-100%%): ");
                    scanf("%f", &descuento);
                    if (descuento < 0 || descuento > 100) {
                        printf("Descuento invalido. No se aplicara descuento.\n");
                        descuento = 0;
                    }
                    // ====total descuento====
                    subtotal = cantidad * precio * (1 - descuento / 100);
                    ganancias += subtotal;
                    stock -= cantidad;
                    printf("Venta realizada! Ganancia: %.2f\n", subtotal);
                }
                break;
 
            case 2: // Reabastecer
                printf("Ingrese cantidad a reabastecer: ");
                scanf("%d", &cantidad);
                if (cantidad > 0) {
                    stock += cantidad;
                    printf("Stock actualizado. Nuevo stock: %d\n", stock);
                } else {
                    printf("Cantidad invalida.\n");
                }
                break;
 
            case 3: // Consultar producto
                printf("\nProducto: %s\n", nombre);
                printf("ID: %d\n", id);
                printf("Stock: %d\n", stock);
                printf("Precio unitario: %.2f\n", precio);
                break;
 
            case 4: // Consultar ganancias
                printf("Ganancias acumuladas: %.2f\n", ganancias);
                break;
 
            case 5:
                printf("Hasta luego...\n");
                break;
 
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 5);
 
    return 0;
}