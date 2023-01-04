#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book{
    public:
        string title;
        string author;
        int year;

    Book(string title, string author, int year){
        this->title = title;
        this->author = author;
        this->year = year;
    }
};

int main(){
    vector<Book> books;

    while (true){
        cout << "Opciones:" << endl;
        cout << "1. Agregar libro" << endl;
        cout << "2. Eliminar libro" << endl;
        cout << "3. Buscar libro" << endl;
        cout << "4. Salir" << endl;
        cout << "Selecciona una opción: ";

        int option;
        cin >> option;

        if (option == 1){
            cout << "Introduce el título, autor y año del libro: ";
            string title, author;
            int year;
            cin >> title >> author >> year;

            books.push_back(Book(title, author, year));
            cout << "Libro agregado correctamente. \n\n";
        }
        else if (option == 2){
            cout << "Introduce el título del libro a eliminar: ";
            string title;
            cin >> title;

            bool found = false;
            for (vector<Book>::iterator it = books.begin(); it != books.end(); ++it){
                if (it->title == title){
                    books.erase(it);
                    found = true;
                    break;
                }
            }

            if (found) cout << "Libro eliminado correctamente. \n\n";
            else cout << "No se ha encontrado el libro. \n\n";
        }
        else if (option == 3){
            cout << "Introduce el título del libro a buscar: ";
            string title;
            cin >> title;

            bool found = false;
            for (Book book : books){
                if (book.title == title){
                    cout << "Título: " << book.title << endl;
                    cout << "Autor: " << book.author << endl;
                    cout << "Año: " << book.year << endl << endl;
                    found = true;
                    break;
                }
            }

            if (!found) cout << "No se ha encontrado el libro. \n\n";
        }
        else if (option == 4) break;
        else cout << "Opción inválida. \n\n";
    }
    return 0;
}
