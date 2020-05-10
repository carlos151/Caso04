#include <iostream>
#include "Grafo.cpp"
#include "CargaDatos.cpp"

using namespace std;

int main()
{
    Grafo grafo;
    grafo.insertarRelacion("perro", "gato");
    grafo.insertarRelacion("gato", "perro");
    grafo.insertarRelacion("caballo", "elefante");
    grafo.insertarRelacion("perro", "caballo");
    grafo.insertarRelacion("gato", "elefante");

    cout << endl;
    /*cout << "Grafo:" << endl;
    grafo.print();*/

    cout << "Relaciones de perro: " << endl;
    grafo.buscarRelaciones("perro").print();

    CargaDatos cargaDatos;
    cargaDatos.inicializar();
    if (cargaDatos.esSustantivo("jugadores"))
    {
        cout << "\nEs sustantivo" << endl;
    }
    else
    {
        cout << "\nNo es sustantivo" << endl;
    }

    return 1;
}