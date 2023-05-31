#include <iostream>
#include <set>
#include <string>
#include <algorithm>

void invertirSubcadena(char arreglo[], int indice){
    char temporal;
    int inicio = 0;
    while (inicio < indice) {
        temporal = arreglo[inicio];
        arreglo[inicio] = arreglo[indice];
        arreglo[indice] = temporal;
        inicio++;
        indice--;
    }
}

bool busquedaProfundidad(std::string actual, std::string fin, std::set<std::string>& visitados, int profundidad, int profundidadMaxima, int& contadorNodos){
    visitados.insert(actual);
    contadorNodos++;

    if (actual == fin){
        return true;
    }

    if (profundidad == profundidadMaxima){
        return false;
    }

    for (int i = 1; i < actual.size(); i++){
        std::string siguiente = actual;
        invertirSubcadena(&siguiente[0], i);
        if (visitados.count(siguiente) == 0){
            if (busquedaProfundidad(siguiente, fin, visitados, profundidad+1, profundidadMaxima, contadorNodos)){
                return true;
            }
        }
    }

    return false;
}

int main(){
    int longitudCadena;
    std::cout << "Introduce la longitud de la cadena a ordenar (maximo 26): ";
    std::cin >> longitudCadena;

    std::string panqueques = "abcdefghijklmnopqrstuvwxyz";
    panqueques = panqueques.substr(0, longitudCadena);
    std::string panquequesOrdenados = panqueques;

    std::random_shuffle(panqueques.begin(), panqueques.end());
    std::cout << "Panqueques desordenados: ";
    std::cout << panqueques << std::endl;
    std::cout << std::endl;
    std::set<std::string> visitados;
    int contadorNodos = 0;
    int profundidadMaxima = 30;
    bool encontrado = busquedaProfundidad(panqueques, panquequesOrdenados, visitados, 0, profundidadMaxima, contadorNodos);
    std::cout << "Panqueques: ";
    std::cout << panqueques << std::endl;
    std::cout << std::endl;
    std::cout << "Panqueques ordenados: ";
    std::cout << panquequesOrdenados << std::endl;
    std::cout << std::endl;
    if (encontrado){
        std::cout << "Nodos visitados: " << contadorNodos << std::endl;
    }
    else {
        std::cout << "No se encontro una solucion" << std::endl;
    }
    return 0;
}
