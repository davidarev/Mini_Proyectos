#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]){
    time_t t = time(0); // Devuelve la hora actual
    struct tm * now = localtime( & t );  // Convierte la hora actual a una estructura tm

    int hora = now->tm_hour; // Obtiene la hora
    int minuto = now->tm_min; // Obtiene los minutos
    int segundo = now->tm_sec; // Obtiene los segundos
    int dia = now->tm_mday; // Obtiene el dia
    int mes = now->tm_mon + 1; // Obtiene el mes
    int anio = now->tm_year + 1900; // Obtiene el año
    string mesString;

    switch (mes) {
        case 1:
            mesString = "enero";
            break;
        case 2:
            mesString = "febrero";
            break;
        case 3:
            mesString = "marzo";
            break;
        case 4:
            mesString = "abril";
            break;
        case 5:
            mesString = "mayo";
            break;
        case 6:
            mesString = "junio";
            break;
        case 7:
            mesString = "julio";
            break;
        case 8:
            mesString = "agosto";
            break;
        case 9:
            mesString = "septiembre";
            break;
        case 10:
            mesString = "octubre";
            break;
        case 11:
            mesString = "noviembre";
            break;
        case 12:
            mesString = "diciembre";
            break;
        default:
            mesString = "mes invalido";
            break;
    }

    while (true) { // Ciclo infinito
        stringstream ss; // Crea un stream de string
        ss << setfill('0') << setw(2) << hora << ":" << setfill('0') << setw(2) << minuto << ":" << setfill('0') << setw(2) << segundo; // Agrega la hora, minutos y segundos al stream
        string horaString = ss.str(); // Convierte el stream a string
        cout << horaString << "     " << dia << " de " << mesString << " de " << anio << endl; // Imprime la hora, minutos, segundos, dia, mes y año
        sleep(1); // Espera 1 segundo
        segundo++;

        if (segundo == 60) { //Definimos las condiciones para que los segundos, minutos y horas se reinicien
            segundo = 0;
            minuto++;
            if (minuto == 60) {
                minuto = 0;
                hora++;
                if (hora == 24) {
                    hora = 0;
                }
            }
        }
    }
    return 0;
}