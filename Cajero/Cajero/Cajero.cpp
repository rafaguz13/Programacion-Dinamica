#include <iostream>
#include <string>
using namespace std;

struct Cuenta {
    int numero;
    string nombre, contra;
    double saldo;
};

// Cuentas disponibles
Cuenta cuenta1 = { 1, "Rafael","patito", 100000.0 };
Cuenta cuenta2 = { 2, "Cesar","gato", 12000.0 };
Cuenta cuenta3 = { 3, "Manuel","perro", 700.0 };
Cuenta cuenta4 = { 4, "Nubia","conejo", 6325.0 };

// Cuenta activa
Cuenta cuenta;

void saldo(Cuenta& c) {
    cout << "Saldo actual de " << c.nombre << ": $" << c.saldo << endl;
}

void depositar(Cuenta& c, double monto) {
    c.saldo += monto;
    cout << "Deposito exitoso. Nuevo saldo: $" << c.saldo << endl;
}

void retirar(Cuenta& c, double monto) {
    if (monto <= c.saldo) {
        c.saldo -= monto;
        cout << "Retiro exitoso. Nuevo saldo: $" << c.saldo << endl;
    }
    else {
        cout << "Fondos insuficientes." << endl;
    }
}

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
            return opc;
    }
}

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


int main() {
    inicio(); // Primero iniciar sesión

    int opcion;
    do {
        opcion = menu();
        double monto;
        switch (opcion) {
        case 1:
            saldo(cuenta);
            break;
        case 2:
            cout << "Ingrese monto a depositar: ";
            cin >> monto;
            depositar(cuenta, monto);
            break;
        case 3:
            cout << "Ingrese monto a retirar: ";
            cin >> monto;
            retirar(cuenta, monto);
            break;
        case 4:
            cout << "Ingrese monto a transferir: ";
            cin >> monto;
            transferir(cuenta, cuenta2, monto); // ejemplo: transferir a Cesar
            break;
        case 5:
            cout << "Gracias por usar el cajero." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
        }
    } while (opcion != 5);

    return 0;
}
