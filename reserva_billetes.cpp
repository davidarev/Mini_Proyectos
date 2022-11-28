#include <iostream>

using namespace std;

// Declaracion de constantes
const int MAX_BILLETES = 100;
const int MAX_DESTINOS = 5;
const int MAX_NOMBRE = 20;

// Declaracion de variables globales
int billetes_disponibles[MAX_DESTINOS] = {10, 20, 30, 40, 50};
float precios[MAX_DESTINOS] = {100, 200, 300, 400, 500};
char destinos[MAX_DESTINOS][MAX_NOMBRE] = {"Madrid", "Barcelona", "Valencia", "Malaga", "Sevilla"};

int menu() {
    int opcion;
    cout << "------------------- \n";
    cout << "1. Mostrar destinos \n";
    cout << "2. Mostrar precios \n";
    cout << "3. Reservar billete \n";
    cout << "4. Salir \n\n";
    cout << "Opcion: ";
    cin >> opcion;
    return opcion;
}

void mostrar_destinos() {
    cout << "Destinos disponibles:" << endl;
    for (int i = 0; i < MAX_DESTINOS; i++) {
        cout << "  " << i + 1 << ". " << destinos[i] << endl;
    }
    cout << endl;
}

void mostrar_precios() {
    cout << "Precios:" << endl;
    for (int i = 0; i < MAX_DESTINOS; i++) {
        cout << "  " << i + 1 << ". " << destinos[i] << ": " << precios[i] << " euros" << endl;
    }
    cout << endl;
}

void reservar_billete() {
    int destino, billetes;
    mostrar_destinos();
    cout << "Destino (número): ";
    cin >> destino;
    cout << "Numero de billetes (número): ";
    cin >> billetes;

    if (billetes_disponibles[destino - 1] >= billetes) {
        billetes_disponibles[destino - 1] -= billetes;
        cout << "Precio total: " << billetes * precios[destino - 1] << " euros" << endl;
    } else {
        cout << "No hay suficientes billetes disponibles" << endl;
    }
    cout << endl;
}

int main() {
    int opcion;
    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                mostrar_destinos();
                break;
            case 2:
                mostrar_precios();
                break;
            case 3:
                reservar_billete();
                break;
            case 4:
                cout << "Hasta pronto" << endl;
                break;
            default:
                cout << "Opcion incorrecta" << endl;
        }
    } while (opcion != 4);
    return 0;
}


