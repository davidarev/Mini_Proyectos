#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int TABLERO_SIZE = 10;

char tablero[TABLERO_SIZE][TABLERO_SIZE]; //El tablero es de 10x10

void inicializar_tablero() {
    for (int i = 0; i < TABLERO_SIZE; i++) { 
        for (int j = 0; j < TABLERO_SIZE; j++) { 
            tablero[i][j] = '-'; //Inicializamos el tablero con guiones
        }
    }
}

//Funcion que imprime el tablero por pantalla
void imprimir_tablero() {
    cout << "  ";
    for (int i = 0; i < TABLERO_SIZE; i++) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < TABLERO_SIZE; i++) {
        cout << i << " ";
        for (int j = 0; j < TABLERO_SIZE; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}

//Funcion que coloca una ficha en el tablero
void colocar_barco(int x, int y, int tamanio, char orientacion) {
    if (orientacion == 'h') { //Horizontal
        for (int i = x; i < x + tamanio; i++) {
            tablero[y][i] = 'B'; 
        }
    } else { //Vertical
        for (int i = y; i < y + tamanio; i++) {
            tablero[i][x] = 'B';
        }
    }
}

//Funcion para atacar una posicion del tablero
void atacar(int x, int y) {
    if (tablero[y][x] == 'B') { //Si hay un barco en esa posicion
        tablero[y][x] = 'H'; //Hundido
        cout << "HIT!" << endl; 
    } else if (tablero[y][x] == '-') { //Si no hay nada en esa posicion
        tablero[y][x] = 'M'; //Miss
        cout << "MISS!" << endl; 
    } else { //Si ya habiamos atacado esa posicion
        cout << "Ya has atacado esa posición." << endl;
    }
}

int main() {
    inicializar_tablero(); //Inicializamos el tablero

    //El jugador 1 coloca sus barcos
    cout << "Jugador 1:" << endl;
    cout << "Ingrese la posición x del barco: ";
    int x; cin >> x;
    cout << "Ingrese la posición y del barco: ";
    int y; cin >> y;
    cout << "Ingrese el tamaño del barco: ";
    int tamanio; cin >> tamanio;
    cout << "Ingrese la orientación del barco (h o v): ";
    char orientacion; cin >> orientacion;
    colocar_barco(x, y, tamanio, orientacion); //Colocamos el barco

    //El jugador 2 coloca sus barcos
    cout << "Jugador 2:" << endl;
    cout << "Ingrese la posición x del barco: "; cin >> x;
    cout << "Ingrese la posición y del barco: "; cin >> y;
    cout << "Ingrese el tamaño del barco: "; cin >> tamanio;
    cout << "Ingrese la orientación del barco (h o v): "; cin >> orientacion;
    colocar_barco(x, y, tamanio, orientacion); //Colocamos el barco
    
    while (true) {
        //Turno del jugador 1
        cout << "Jugador 1:" << endl;
        cout << "Ingrese la posición x del ataque: "; cin >> x;
        cout << "Ingrese la posición y del ataque: "; cin >> y;
        atacar(x, y);
        imprimir_tablero();
        //Turno del jugador 2
        cout << "Jugador 2:" << endl;
        cout << "Ingrese la posición x del ataque: "; cin >> x;
        cout << "Ingrese la posición y del ataque: "; cin >> y;
        atacar(x, y);
        imprimir_tablero();
    }
    return 0;
}
