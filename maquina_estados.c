#include <stdio.h>

#define NUM_STATES 3 //Numero de estados
#define NUM_SYMBOLS 2 //Numero de simbolos

// Estructura para representar cada estado
typedef struct {
    int id;
    char *name;
} State;

// Estructura para representar cada símbolo
typedef struct {
    int id;
    char *name;
} Symbol;

// Función para realizar la transición a un nuevo estado
int transition(State currentState, Symbol inputSymbol) {
    // Si el estado actual es 0 y el símbolo de entrada es 0, regreso a 0
    if (currentState.id == 0 && inputSymbol.id == 0) {
        return 0;
    }
    // Si el estado actual es 0 y el símbolo de entrada es 1, regreso a 1
    else if (currentState.id == 0 && inputSymbol.id == 1) {
        return 1;
    }
    // Si el estado actual es 1 y el símbolo de entrada es 0, regreso a 2
    else if (currentState.id == 1 && inputSymbol.id == 0) {
        return 2;
    }
    // Si el estado actual es 1 y el símbolo de entrada es 1, regreso a 0
    else if (currentState.id == 1 && inputSymbol.id == 1) {
        return 0;
    }
    // Si el estado actual es 2 y el símbolo de entrada es 0, regreso a 1
    else if (currentState.id == 2 && inputSymbol.id == 0) {
        return 1;
    }
    // Si el estado actual es 2 y el símbolo de entrada es 1, regreso a 2
    else if (currentState.id == 2 && inputSymbol.id == 1) {
        return 2;
    }
    return 0;
}

int main(int argc, char **argv) {
    // Inicializo la máquina de estado finito
    State states[NUM_STATES] = {
            {0, "State A"},
            {1, "State B"},
            {2, "State C"}
    };
    Symbol symbols[NUM_SYMBOLS] = {
            {0, "Symbol 0"},
            {1, "Symbol 1"}
    };
    State currentState = states[0];

    // Leo la secuencia de símbolos
    Symbol inputSymbols[100]; //Array para guardar los símbolos de entrada
    int numInputSymbols = 0; //Número de símbolos de entrada
    printf("Ingresa la secuencia de símbolos: ");
    int input = getchar(); //Leo el primer símbolo
    while (input != '\n') {
        inputSymbols[numInputSymbols++] = symbols[input - '0']; //Guardo el símbolo en el array
        input = getchar();
    }

    // Proceso la secuencia de símbolos
    for (int i = 0; i < numInputSymbols; i++) {
        Symbol inputSymbol = inputSymbols[i]; //Obtengo el símbolo de entrada
        printf("Procesando símbolo %s en estado %s\n", inputSymbol.name, currentState.name); //Imprimo el símbolo y el estado actual
        currentState = states[transition(currentState, inputSymbol)]; //Realizo la transición y cambio el estado actual
    }

    return 0;
}
