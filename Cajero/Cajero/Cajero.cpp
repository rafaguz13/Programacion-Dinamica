#include <iostream>
#include <string>
using namespace std;

// Definimos un struct llamado Cuenta que representa una cuenta bancaria
// con número de cuenta, nombre del titular, contraseña y saldo disponible.
struct Cuenta {
    int numero;
    string nombre, contra;
    double saldo;
};

// Cuentas disponibles en el sistema (simulación de base de datos)
Cuenta cuenta1 = { 1, "Rafael","patito", 100000.0 };
Cuenta cuenta2 = { 2, "Cesar","gato", 12000.0 };
Cuenta cuenta3 = { 3, "Manuel","perro", 700.0 };
Cuenta cuenta4 = { 4, "Nubia","conejo", 6325.0 };

// Variable global que almacenará la cuenta activa (la que inicia sesión)
Cuenta cuenta;

// ---------------- FUNCIONES DE OPERACIONES ----------------

// Consultar saldo de la cuenta activa
void saldo(Cuenta& c) {
    cout << "Saldo actual de " << c.nombre << ": $" << c.saldo << endl;
}

// Depositar dinero en la cuenta activa
void depositar(Cuenta& c, double monto) {
    c.saldo += monto;
    cout << "Deposito exitoso. Nuevo saldo: $" << c.saldo << endl;
}

// Retirar dinero de la cuenta activa
void retirar(Cuenta& c, double monto) {
    if (monto <= c.saldo) {
        c.saldo -= monto;
        cout << "Retiro exitoso. Nuevo saldo: $" << c.saldo << endl;
    }
    else {
        cout << "Fondos insuficientes." << endl;
    }
}

// Transferir dinero de una cuenta origen a una cuenta destino
void transferir(Cuenta& origen, Cuenta& destino, double monto) {
    if (monto <= origen.saldo) {
        origen.saldo -= monto;
        destino.saldo += monto;
        cout << "Transferencia exitosa de $" << monto
            << " a " << destino.nombre << endl;
    }
    else {
        cout << "Fondos insuficientes para transferir." << endl;
    }
}

// ---------------- MENÚ PRINCIPAL ----------------

// Muestra el menú de opciones y valida la entrada del usuario
int menu() {
    int opc;
    while (true) {
        cout << "\n--- Cajero Automatico ---\n";
        cout << "Bienvenido " << cuenta.nombre << "\n";
        cout << "1. Consultar saldo\n";
        cout << "2. Depositar\n";
        cout << "3. Retirar\n";
        cout << "4. Transferir\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opc;
        if (opc > 5 || opc < 1)
            cout << "Opcion invalida \n";
        else
            return opc; // Devuelve la opción válida
    }
}

// ---------------- INICIO DE SESIÓN ----------------

// Solicita usuario y contraseña hasta que sean correctos
void inicio() {
    string user, pass;
    bool valido = false;

    while (!valido) {
        cout << "\n--- Inicio de sesion ---\n";
        cout << "--- Cuide mayusculas ---\n";
        cout << "Usuario: ";
        cin >> user;
        cout << "Contraseña: ";
        cin >> pass;

        // Validación de credenciales contra las cuentas disponibles
        if (cuenta1.nombre == user && cuenta1.contra == pass) {
            cuenta = cuenta1;
            valido = true;
        }
        else if (cuenta2.nombre == user && cuenta2.contra == pass) {
            cuenta = cuenta2;
            valido = true;
        }
        else if (cuenta3.nombre == user && cuenta3.contra == pass) {
            cuenta = cuenta3;
            valido = true;
        }
        else if (cuenta4.nombre == user && cuenta4.contra == pass) {
            cuenta = cuenta4;
            valido = true;
        }
        else {
            cout << "Credenciales incorrectas. Intente nuevamente.\n";
        }
    }

    cout << "Inicio de sesion exitoso. Bienvenido " << cuenta.nombre << "!\n";
}

// ---------------- PROGRAMA PRINCIPAL ----------------

int main() {
    inicio(); // Primero iniciar sesión

    int opcion;
    do {
        opcion = menu(); // Mostrar menú y obtener opción
        double monto;
        switch (opcion) {
        case 1: // Consultar saldo
            saldo(cuenta);
            break;
        case 2: // Depositar
            cout << "Ingrese monto a depositar: ";
            cin >> monto;
            depositar(cuenta, monto);
            break;
        case 3: // Retirar
            cout << "Ingrese monto a retirar: ";
            cin >> monto;
            retirar(cuenta, monto);
            break;
        case 4: // Transferir (ejemplo fijo a Cesar)
            cout << "Ingrese monto a transferir: ";
            cin >> monto;
            transferir(cuenta, cuenta2, monto);
            break;
        case 5: // Salir
            cout << "Gracias por usar el cajero." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
        }
    } while (opcion != 5); // Repite hasta que el usuario elija salir

    return 0;
}
