#include <iostream>
using namespace std;

struct cuenta {
    int numero;
    string nombre, password;
    double saldo;
};

cuenta cuenta1 = { 1, "Rafael","patito", 100000.0};
cuenta cuenta2 = { 2, "Cesar","gato", 12000.0};
cuenta cuenta3 = { 3, "Manuel","perro", 700.0};
cuenta cuenta4 = { 4, "Nubia","conejo", 6325.0};

void saldo(cuenta &c) {

}

void depositar(double monto) {

}

void transferir(cuenta &origen, cuenta &destino, double monto) {

}

void retirar(double monto) {

}

int menu() {
    int opc;
    while (true) {
        cout << "\n--- Cajero Automatico ---\n";
        cout << "\n--- Bienvenido Rafael ---\n";
        cout << "1. Consultar saldo\n";
        cout << "2. Depositar\n";
        cout << "3. Retirar\n";
        cout << "4. Transferir\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opc;
        if (opc > 5 or opc < 1)
            cout << "Opcion invalida \n";
        else
            return opc;
    }
}

int inicio() {
    //Aqui ira el inicio de sesion para saber con que cuenta se trabajara

    cout << "\n--- Cajero Automatico ---\n";
    cout << "Ingrese su nombre de usuario (Recuerde que la primer letra siempre es mayuscula)\n";

}

int main()
{
    int opcion;
    do {
        opcion = menu();
        double monto;
        switch (opcion) {
        case 1:
            saldo();
            break;
        case 2:
            cout << "Ingrese monto a depositar: ";
            cin >> monto;
            depositar(monto);
            break;
        case 3:
            cout << "Ingrese monto a retirar: ";
            cin >> monto;
            retirar(monto);
            break;
        case 4:
            //F
            cout << "Ingrese monto a transferir: ";
            cin >> monto;
            transferir();
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
