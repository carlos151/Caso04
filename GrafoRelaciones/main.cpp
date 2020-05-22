#include <iostream>
//#include "Grafo.cpp"
#include "CargaDatos.cpp"

using namespace std;

int main()
{
    Grafo grafo;

    CargaDatos cargaDatos;
    cargaDatos.inicializar(&grafo);
    grafo.palabrasMasPoderosas(5);
    //grafo.palabrasMasPoderP("chaman");

    //cout << "Cantidad de Relaciones: " << grafo.buscarCantidadRelaciones("habitualmente") << endl;
    //grafo.GruposPoderosos("chamanes", 20, 50);

    return 1;
}