#include <iostream>
#include <vector>

using namespace std;

//Función para juntar dos vectores ordenados en un solo vector ordenado
vector<int> merge(vector<int> const & left, vector<int> const & right){
    auto left_it = 0; //Iterador del vector izquierdo
    auto right_it = 0; //Iterador del vector derecho
    vector<int> vec; 
    while(left_it != left.size() && right_it != right.size()){ //Mientras no se llegue al final de alguna de los vectores
        if(left[left_it] < right[right_it]){ //Si el elemento del vector izquierda es menor que el de la derecha
            vec.push_back(left[left_it]); //Se añade el elemento del vector izquierdo
            left_it++;
        }
        else{ 
            vec.push_back(right[right_it]); //De lo contrario se añade el elemento del vector derecho
            right_it++;
        }
    }
    for(int i = left_it; i < left.size(); i++){ 
        vec.push_back(left[i]); //Se añaden los elementos restantes del vector izquierdo
    }
    for(int i = right_it; i < right.size(); i++){
        vec.push_back(right[i]); //Se añaden los elementos restantes del vector derecho
    }
    return vec; //Se devuelve el vector ordenado
}

//Función que divide el vector en dos y llama a la función merge para ordenarlos
vector<int> mergeSort(vector<int> const & vec){
    if(vec.size() == 1){ 
        return vec; //Si el vector tiene un solo elemento, esta ya esta ordenado
    }
    else{
        auto middle = vec.size() / 2; //Se divide el vector en dos vectores, uno para cada lado
        vector<int> left{vec.begin(), vec.begin() + middle}; //Vector izquierdo
        vector<int> right{vec.begin() + middle, vec.end()}; //Vector derecho

        left = mergeSort(left); //Se ordena el vector izquierdo
        right = mergeSort(right); //Se ordena el vector derecho

        return merge(left, right); //Se juntan ambos vectores
    }
}

//Función para imprimir el vector
void print(vector<int> const & vec){
    for(auto elem: vec) cout << elem << ", ";
}

int main(){
    vector<int> vec{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; //Vector desordenado
    vector<int> ord = mergeSort(vec); //Se ordena la lista
    print(ord); //Se imprime la lista ordenada
}
