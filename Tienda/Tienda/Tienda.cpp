#include <iostream>
#include <string>
using namespace std;

// Definimos un struct llamado Producto que contiene
// los atributos básicos de cada producto en el inventario
struct Producto {
    string nombre;   // Nombre del producto
    double precio;   // Precio del producto
    int cantidad;    // Cantidad disponible en inventario
};

// Constante que define el máximo de productos permitidos
const int MAX = 100;

// Arreglo de productos que simula el inventario
Producto inventario[MAX];

// Variable que lleva el conteo de productos registrados
int total = 0;

// ---------------- FUNCIONES ----------------

// Mostrar todos los productos registrados en el inventario
void mostrarProductos() {
    cout << "\n--- Lista de Productos ---\n";
    for (int i = 0; i < total; i++) {
        cout << i + 1 << ". " << inventario[i].nombre
            << " | Precio: $" << inventario[i].precio
            << " | Cantidad: " << inventario[i].cantidad << endl;
    }
}

// Buscar un producto por su nombre
void buscarProducto(string nombre) {
    bool encontrado = false;
    for (int i = 0; i < total; i++) {
        if (inventario[i].nombre == nombre) {
            cout << "Producto encontrado: " << inventario[i].nombre
                << " | Precio: $" << inventario[i].precio
                << " | Cantidad: " << inventario[i].cantidad << endl;
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Producto no encontrado.\n";
}

// Ordenar productos por nombre usando el método burbuja
void ordenarPorNombre() {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - 1 - i; j++) {
            if (inventario[j].nombre > inventario[j + 1].nombre) {
                swap(inventario[j], inventario[j + 1]);
            }
        }
    }
    cout << "Productos ordenados por nombre.\n";
}

// Ordenar productos por precio usando el método burbuja
void ordenarPorPrecio() {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - 1 - i; j++) {
            if (inventario[j].precio > inventario[j + 1].precio) {
                swap(inventario[j], inventario[j + 1]);
            }
        }
    }
    cout << "Productos ordenados por precio.\n";
}

// Ordenar productos por cantidad usando el método burbuja
void ordenarPorCantidad() {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - 1 - i; j++) {
            if (inventario[j].cantidad > inventario[j + 1].cantidad) {
                swap(inventario[j], inventario[j + 1]);
            }
        }
    }
    cout << "Productos ordenados por cantidad.\n";
}

// ---------------- PROGRAMA PRINCIPAL ----------------

int main() {
    int opcion;
    do {
        // Menú principal
        cout << "\n--- Sistema de Inventario ---\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar productos\n";
        cout << "3. Buscar producto\n";
        cout << "4. Ordenar por nombre\n";
        cout << "5. Ordenar por precio\n";
        cout << "6. Ordenar por cantidad\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // Limpia la pantalla (solo funciona en Windows)
        system("cls");

        // Opciones del menú
        if (opcion == 1) {
            // Agregar producto al inventario
            if (total < MAX) {
                cout << "Ingrese nombre: ";
                cin >> inventario[total].nombre;
                cout << "Ingrese precio: ";
                cin >> inventario[total].precio;
                cout << "Ingrese cantidad: ";
                cin >> inventario[total].cantidad;
                total++; // Incrementa el contador de productos
            }
            else {
                cout << "Inventario lleno.\n";
            }
        }
        else if (opcion == 2) {
            // Mostrar todos los productos
            mostrarProductos();
        }
        else if (opcion == 3) {
            // Buscar producto por nombre
            string nombre;
            cout << "Ingrese nombre a buscar: ";
            cin >> nombre;
            buscarProducto(nombre);
        }
        else if (opcion == 4) {
            // Ordenar productos por nombre
            ordenarPorNombre();
        }
        else if (opcion == 5) {
            // Ordenar productos por precio
            ordenarPorPrecio();
        }
        else if (opcion == 6) {
            // Ordenar productos por cantidad
            ordenarPorCantidad();
        }
        else if (opcion == 7) {
            // Salir del sistema
            cout << "Saliendo del sistema...\n";
        }
        else {
            // Validación de opción incorrecta
            cout << "Opcion invalida.\n";
        }
    } while (opcion != 7); // Repite hasta que se elija salir

    return 0;
}
