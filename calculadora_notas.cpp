#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<string> nombres;
    vector<int> notas_examen_final;
    vector<int> notas_examen_parcial;
    vector<int> notas_final_practicas;
    vector<int> notas_participacion;
    vector<int> notas_finales;

    string nombre;
    int nota_examen_final = 0, nota_examen_parcial = 0, nota_final_practicas = 0, nota_participacion = 0, nota_final = 0;
    int tecla = 0; // Variable para almacenar la tecla pulsada

    while (tecla != 3) { // Mientras no se pulse la tecla 3
        cout << "Bienvenido al programa de calculo de notas" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "1. Ingresar datos" << endl;
        cout << "2. Mostrar datos" << endl;
        cout << "3. Salir" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Opcion: ";
        cin >> tecla;
        cout << "-----------------------------------------" << endl;

        if(tecla == 1){ // Ingresar datos
            cout << "Introduce el nombre de la asignatura: ";
            cin >> nombre; nombres.push_back(nombre);

            cout << "Introduce la nota del examen final: ";
            cin >> nota_examen_final; notas_examen_final.push_back(nota_examen_final);

            cout << "Introduce la nota del examen parcial: ";
            cin >> nota_examen_parcial; notas_examen_parcial.push_back(nota_examen_parcial);

            cout << "¿Cuantas practicas has tenido? ";
            int num; cin >> num;
            int nota;
            for(int i = 0; i < num; i++){
                cout << "Introduce la nota de la practica " << i + 1 << ": ";
                cin >> nota; nota_final_practicas += nota;
            }
            nota_final_practicas /= num;
            notas_final_practicas.push_back(nota_final_practicas);

            cout << "Introduce la nota de participacion: ";
            cin >> nota_participacion; notas_participacion.push_back(nota_participacion);
            cout << "\n\n";

            nota_final = (nota_examen_final * 0.65) + (nota_examen_parcial * 0.15) + (nota_final_practicas * 0.15) + (nota_participacion * 0.05);
            notas_finales.push_back(nota_final);
        }

        else if(tecla == 2){ // Mostrar datos
            for(int i = 0; i < nombres.size(); i++){
                cout << "Asignatura: " << nombres[i] << endl;
                cout << "Nota del examen final: " << notas_examen_final[i] << endl;
                cout << "Nota del examen parcial: " << notas_examen_parcial[i] << endl;
                cout << "Nota final de las practicas: " << notas_final_practicas[i] << endl;
                cout << "Nota de participacion: " << notas_participacion[i] << endl;
                cout << "Nota final: " << notas_finales[i] << "\n\n\n";
            }
        }

        else if(tecla == 3){ // Salir
            cout << "Hasta luego!" << endl;
        }

        else{ // Opcion no valida
            cout << "Opcion incorrecta" << endl;
        }
    }
    return 0;
}