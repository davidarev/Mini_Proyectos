#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string, double> conversiones = { //Creo un diccionario con las conversiones
            {"pulgadas", 2.54},
            {"pies", 30.48},
            {"yardas", 91.44},
            {"millas", 160934},
            {"libras", 0.45359237},
            {"onzas", 28.3495231},
            {"toneladas", 907184.74}
    };

    double valor;
    string unidad;
    cout << "Introduce una cantidad y una unidad (pulgadas, pies, yardas, millas, libras, onzas, toneladas): ";
    cin >> valor >> unidad;

    double valorCM = valor * conversiones[unidad]; //Multiplico el valor por la conversion correspondiente
    cout << valor << " " << unidad << " son " << valorCM << " centímetros." << endl;

    return 0;
}
