#include <iostream>
using namespace std;

int contadorProcesos = 0;

void Proceso() {
    contadorProcesos++;
    cout << "Proceso realizado." << endl;
}

int NContadorProcesos() {
    return contadorProcesos;
}

int main() {
    int opcion;

    while (true) {
        cout << "Seleccione una opcion:\n";
        cout << "1. Ejecutar proceso\n";
        cout << "2. Consultar contador de Procesos\n";
        cout << "3. Salir\n";
        cin >> opcion;

        if (opcion == 1) {
            Proceso();
        } else if (opcion == 2) {
            cout << "La funcion de proceso se ha llamado " << NContadorProcesos() << " veces." << endl;
        } else if (opcion == 3) {
            break;
        } else {
            cout << "Opcion no valida, intentelo de nuevo." << endl;
        }
    }

    return 0;
}
