#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string shuffleWord(string word){
    vector<char> chars(word.begin(), word.end()); //Convierte el string en un vector de caracteres

    random_shuffle(chars.begin(), chars.end()); //Desordena el vector de caracteres

    string shuffledWord(chars.begin(), chars.end()); //Convierte el vector de caracteres en un string
    return shuffledWord; 
}

int main(){
    vector<string> words = {"perro", "gato", "casa", "arbol", "elefante"};

    cout << "Rompecabezas:" << endl;
    for (auto elem: words) cout << shuffleWord(elem) << endl; //Desordena cada palabra del vector y la imprime

    cout << endl << "Adivina las palabras (en orden):" << endl;
    for (auto elem: words){
        string guess;
        cout << "Palabra: ";
        cin >> guess;

        if (guess == elem) words.erase(remove(words.begin(), words.end(), elem), words.end()); //Elimina la palabra del vector si se adivina
    }

    if (words.empty()) cout << "¡Felicidades! Adivinaste todas las palabras." << endl; 
    else cout << "Lo siento, no adivinaste todas las palabras." << endl;

    return 0;
}
