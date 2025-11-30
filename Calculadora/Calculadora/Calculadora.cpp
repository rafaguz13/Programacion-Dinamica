#include <iostream>
#include <cmath>   // Librería para pow() y sqrt()
using namespace std;

// Función para calcular el factorial de un número entero
long long factorial(int n) {
    if (n < 0) {
        cout << "No existe factorial de negativos." << endl;
        return -1; // Valor de error
    }
    long long resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    int opcion;
    double a, b;

    do {
        // Menú principal
        cout << "\n--- Calculadora ---\n";
        cout << "1. Suma\n";
        cout << "2. Resta\n";
        cout << "3. Multiplicacion\n";
        cout << "4. Division\n";
        cout << "5. Factorial\n";
        cout << "6. Potencia\n";
        cout << "7. Raiz cuadrada\n";
        cout << "8. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: // Suma
            cout << "Ingrese dos numeros: ";
            cin >> a >> b;
            cout << "Resultado: " << a + b << endl;
            break;
        case 2: // Resta
            cout << "Ingrese dos numeros: ";
            cin >> a >> b;
            cout << "Resultado: " << a - b << endl;
            break;
        case 3: // Multiplicación
            cout << "Ingrese dos numeros: ";
            cin >> a >> b;
            cout << "Resultado: " << a * b << endl;
            break;
        case 4: // División
            cout << "Ingrese dos numeros: ";
            cin >> a >> b;
            if (b != 0)
                cout << "Resultado: " << a / b << endl;
            else
                cout << "Error: division entre cero." << endl;
            break;
        case 5: { // Factorial
            int n;
            cout << "Ingrese un numero entero: ";
            cin >> n;
            cout << "Resultado: " << factorial(n) << endl;
            break;
        }
        case 6: // Potencia
            cout << "Ingrese base y exponente: ";
            cin >> a >> b;
            cout << "Resultado: " << pow(a, b) << endl;
            break;
        case 7: // Raíz cuadrada
            cout << "Ingrese un numero: ";
            cin >> a;
            if (a >= 0)
                cout << "Resultado: " << sqrt(a) << endl;
            else
                cout << "Error: no existe raiz cuadrada de negativos." << endl;
            break;
        case 8: // Salir
            cout << "Saliendo de la calculadora..." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
        }
    } while (opcion != 8);

    return 0;
}
