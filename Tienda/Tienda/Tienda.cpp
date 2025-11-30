#include <iostream>
#include <string>
using namespace std;

struct Producto {
    string nombre;
    double precio;
    int cantidad;
};

const int MAX = 100; // máximo de productos
Producto inventario[MAX];
int total = 0; // número de productos registrados

// Mostrar productos
void mostrarProductos() {
    cout << "\n--- Lista de Productos ---\n";
    for (int i = 0; i < total; i++) {
        cout << i + 1 << ". " << inventario[i].nombre
            << " | Precio: $" << inventario[i].precio
            << " | Cantidad: " << inventario[i].cantidad << endl;
    }
}

// Buscar producto por nombre
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

// Ordenar por nombre (burbuja)
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

// Ordenar por precio
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

// Ordenar por cantidad
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

int main() {
    int opcion;
    do {
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
        system("cls");
        if (opcion == 1) {
            if (total < MAX) {
                cout << "Ingrese nombre: ";
                cin >> inventario[total].nombre;
                cout << "Ingrese precio: ";
                cin >> inventario[total].precio;
                cout << "Ingrese cantidad: ";
                cin >> inventario[total].cantidad;
                total++;
            }
            else {
                cout << "Inventario lleno.\n";
            }
        }
        else if (opcion == 2) {
            mostrarProductos();
        }
        else if (opcion == 3) {
            string nombre;
            cout << "Ingrese nombre a buscar: ";
            cin >> nombre;
            buscarProducto(nombre);
        }
        else if (opcion == 4) {
            ordenarPorNombre();
        }
        else if (opcion == 5) {
            ordenarPorPrecio();
        }
        else if (opcion == 6) {
            ordenarPorCantidad();
        }
        else if (opcion == 7) {
            cout << "Saliendo del sistema...\n";
        }
        else {
            cout << "Opcion invalida.\n";
        }
    } while (opcion != 7);

    return 0;
}
