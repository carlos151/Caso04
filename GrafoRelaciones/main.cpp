#include <iostream>
//#include "Grafo.cpp"
#include "CargaDatos.cpp"

using namespace std;

int main()
{
    Grafo grafo;
    /*grafo.insertarRelacion("perro", "gato");
    grafo.insertarRelacion("gato", "perro");
    grafo.insertarRelacion("caballo", "elefante");
    grafo.insertarRelacion("perro", "caballo");
    grafo.insertarRelacion("gato", "elefante");

    cout << endl;
    cout << "Grafo:" << endl;
    grafo.print();

    cout << endl;

    cout << "Cantidad de relaciones de caballo: " << grafo.buscarCantidadRelaciones("caballo") << endl;
    
    cout << "Relaciones de perro: " << endl;
    grafo.buscarRelaciones("perro").print();*/

    CargaDatos cargaDatos;
    cargaDatos.inicializar(&grafo);
    grafo.palabrasMasPoderosas(5);
    //grafo.palabrasMasPoderP("algunas");
    //grafo.printRelaciones();
    grafo.GruposPoderosos("camino", 3, 4);
    //grafo.print();
    /*if (cargaDatos.esSustantivo("Alonso"))
        cout
            << "\nEs sustantivo" << endl;
    else
        cout << "\nNo es sustantivo" << endl;*/

    return 1;
}