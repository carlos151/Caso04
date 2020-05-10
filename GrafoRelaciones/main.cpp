#include <iostream>
#include "Grafo.cpp"

using namespace std;

int main(){
    Grafo grafo;
    grafo.insertarRelacion("perro","gato");
    grafo.insertarRelacion("gato","perro");
    grafo.insertarRelacion("caballo","elefante");
    grafo.insertarRelacion("perro","caballo");
    grafo.insertarRelacion("gato","elefante");

    cout << endl;
    /*cout << "Grafo:" << endl;
    grafo.print();*/

    cout << "Relaciones de perro: " << endl;
    grafo.buscarRelaciones("perro").print();

    return 1;
}