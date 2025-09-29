#include <stdio.h>

int main() {
    int   id, stock, cantidad, opcion;
    float precio, total_ganancias = 0.0;
    float descuento, precio_con_descuento, total_venta;
    char  nombre[30];

    // Registro del producto
    printf("Ingrese el ID del producto: ");
    scanf("%d", &id);

    // Lee nombre con espacios, hasta '\n' (máx 29 chars)
    printf("Ingrese el nombre del producto: ");
    scanf(" %29[^\n]", nombre);

    // Validar que el stock no sea negativo
    do {
        printf("Ingrese la cantidad inicial en stock (>= 0): ");
        scanf("%d", &stock);
        if (stock < 0) {
            printf("El stock no puede ser negativo. Intente nuevamente.\n");
        }
    } while (stock < 0);

    // Validar que el precio no sea negativo
    do {
        printf("Ingrese el precio unitario del producto (>= 0): ");
        scanf("%f", &precio);
        if (precio < 0) {
            printf("El precio no puede ser negativo. Intente nuevamente.\n");
        }
    } while (precio < 0);

    // Menú principal
    do {
        printf("\nMenu de Opciones:\n");
        printf("1. Vender producto\n");
        printf("2. Reabastecer producto\n");
        printf("3. Mostrar informacion del producto\n");
        printf("4. Mostrar total de ganancias\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Validar cantidad a vender
                do {
                    printf("Ingrese la cantidad a vender (>= 0): ");
                    scanf("%d", &cantidad);
                    if (cantidad < 0) {
                        printf("La cantidad no puede ser negativa. Intente nuevamente.\n");
                    }
                } while (cantidad < 0);

                if (cantidad > stock) {
                    printf("No hay suficientes unidades en stock; no se puede vender.\n");
                } else {
                    // Descuento 
                    do {
                        printf("Ingrese el porcentaje de descuento (0-100): ");
                        scanf("%f", &descuento);
                        if (descuento < 0 || descuento > 100) {
                            printf("Porcentaje de descuento invalido. Debe estar entre 0 y 100.\n");
                        }
                    } while (descuento < 0 || descuento > 100);

                    // Precio final y total
                    precio_con_descuento = precio * (1.0f - descuento / 100.0f);
                    total_venta = cantidad * precio_con_descuento;

                    // Actualizar stock y ganancias
                    stock -= cantidad;
                    total_ganancias += total_venta;

                    printf("Venta realizada con exito, %d unidades vendidas.\n", cantidad);
                    printf("Precio con descuento: %.2f\n", precio_con_descuento);
                    printf("Total de la venta: %.2f\n", total_venta);
                }
                break;

            case 2:
                // Reabastecer
                do {
                    printf("Ingrese la cantidad a agregar al stock (>= 0): ");
                    scanf("%d", &cantidad);
                    if (cantidad < 0) {
                        printf("La cantidad no puede ser negativa. Intente nuevamente.\n");
                    }
                } while (cantidad < 0);

                stock += cantidad;
                printf("Stock actualizado. Nuevo stock: %d\n", stock);
                break;

            case 3:
                // Mostrar info
                printf("\nInformacion del producto:\n");
                printf("ID: %d\n", id);
                printf("Nombre: %s\n", nombre);
                printf("Stock disponible: %d\n", stock);
                printf("Precio unitario: %.2f\n", precio);
                break;

            case 4:
                // Ganancias
                printf("Total de ganancias: %.2f\n", total_ganancias);
                break;

            case 5:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }

    } while (opcion != 5);

    return 0;
}
