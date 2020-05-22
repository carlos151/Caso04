#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "Aristas.cpp"

using namespace std;

class Grafo
{
private:
    unordered_map<string, Aristas> grafo;
    unordered_map<string, int> cantidadRelaciones;

public:
    Grafo() {}

    int buscarCantidadRelaciones(string sustantivo)
    {
        if (this->cantidadRelaciones.find(sustantivo) != this->cantidadRelaciones.end())
        {
            return cantidadRelaciones.at(sustantivo);
        }
        return 0;
    }

    bool buscarKey(string key)
    {
        if (this->grafo.find(key) == this->grafo.end())
        {
            return false;
        }
        return true;
    }

    void insertarRelacion(string sustantivoA, string sustantivoB)
    {
        if (buscarKey(sustantivoA))
        {
            grafo.at(sustantivoA).insertarRelacion(sustantivoB);
        }
        else
        {
            Aristas aristas;
            aristas.insertarRelacion(sustantivoB);
            grafo.insert({sustantivoA, aristas});
            cantidadRelaciones.insert({sustantivoA, 0});
        }
        cantidadRelaciones.at(sustantivoA) += 1;
    }

    Aristas buscarRelaciones(string sustantivo)
    {
        return grafo.at(sustantivo);
    }

    void print()
    {
        for (auto pair : grafo)
        {
            cout << "{" << pair.first << ": ";
            pair.second.print();
            cout << "}" << endl;
        }
    }

    void printRelaciones()
    {
        for (auto pair : cantidadRelaciones)
        {
            cout << "{" << pair.first << ": " << pair.second << "}" << endl;
        }
    }

    void print(string sustantivo)
    {
        cout << "{" << sustantivo << ": ";
        grafo.at(sustantivo).print();
        cout << "}" << endl;
    }

    bool static comparar(pair<string, int> a, pair<string, int> b)
    {
        return (a.second > b.second);
    }

    void palabrasMasPoderosas(int cantidad)
    {
        vector<pair<string, int>> sortRelaciones(cantidadRelaciones.begin(), cantidadRelaciones.end());
        sort(sortRelaciones.begin(), sortRelaciones.end(), comparar);
        cout << "Las " << cantidad << " palabras más poderosas:" << endl;
        for (int iterador = 0; iterador < cantidad; iterador++)
        {
            cout << sortRelaciones.at(iterador).first << endl;
        }
        cout << endl;
    }

    bool esLaRelacionMasPoderosa(string palabra, string palabraP)
    {
        unordered_map<string, int> relacionesDePalabra = buscarRelaciones(palabra).getMap();
        vector<pair<string, int>> sortRelaciones(relacionesDePalabra.begin(), relacionesDePalabra.end());
        sort(sortRelaciones.begin(), sortRelaciones.end(), comparar);
        if (sortRelaciones.at(0).first == palabraP)
        {
            return true;
        }
        return false;
    }

    void palabrasMasPoderP(string palabraP)
    {
        unordered_map<string, int> relacionesDeP = buscarRelaciones(palabraP).getMap();
        cout << "Palabras sobre la que la palabra " << palabraP << " tiene más poder:" << endl;
        for (auto iterador = relacionesDeP.begin(); iterador != relacionesDeP.end(); iterador++)
        {
            if (esLaRelacionMasPoderosa(iterador->first, palabraP))
            {
                cout << iterador->first << endl;
            }
        }
        cout << endl;
    }

    vector<pair<string, int>> getVectorOrdenado(Aristas relaciones)
    {
        vector<pair<string, int>> sortRelaciones(relaciones.getMap().begin(), relaciones.getMap().end());
        sort(sortRelaciones.begin(), sortRelaciones.end(), comparar);
        return sortRelaciones;
    }

    int obtenerValorAdecuado(vector<pair<string, int>> posibles, Aristas *visitados)
    {
        for (unsigned int i = 0; i < posibles.size(); i++)
        {
            if (!visitados->buscarKey(posibles.at(i).first))
                return i;
        }
        return -1;
    }
    void obtenerSubVector(string palabra, int profundidad, vector<string> *v, Aristas *visitados)
    {
        if (profundidad <= 0)
            return;

        Aristas relaciones = buscarRelaciones(palabra);
        vector<pair<string, int>> sortRelaciones = getVectorOrdenado(relaciones);
        int index = obtenerValorAdecuado(sortRelaciones, visitados);
        if (index != -1)
        {
            v->push_back(sortRelaciones.at(index).first);
            visitados->insertarRelacion(sortRelaciones.at(index).first);
            return obtenerSubVector(sortRelaciones.at(index).first, profundidad - 1, v, visitados);
        }
        return;
    }
    void GruposPoderosos(string palabra, int cantidadGrupos, int tamGrupo)
    {
        if (!buscarKey(palabra))
        {
            cout << "'" << palabra << "' no se encontró en el texto" << endl;
            return;
        }

        Aristas visitados;
        Aristas relaciones = buscarRelaciones(palabra);
        visitados.insertarRelacion(palabra);
        vector<pair<string, int>> sortRelaciones = getVectorOrdenado(relaciones);
        vector<vector<string>> result;
        visitados.insertarRelacion(palabra);
        int iterador = 0;
        unsigned int contador = 0;
        while (iterador < cantidadGrupos && contador != sortRelaciones.size())
        {
            if (!visitados.buscarKey(sortRelaciones.at(contador).first))
            {
                vector<string> subvector;
                string nuevaPalabra = sortRelaciones.at(contador).first;
                subvector.push_back(palabra);
                subvector.push_back(nuevaPalabra);
                visitados.insertarRelacion(nuevaPalabra);
                obtenerSubVector(nuevaPalabra, tamGrupo - 2, &subvector, &visitados);
                result.push_back(subvector);
                iterador++;
            }
            contador++;
        }
        imprimirGruposPodersos(result);
    }

    void imprimirGruposPodersos(vector<vector<string>> result)
    {
        for (unsigned int i = 0; i < result.size(); i++)
        {
            cout << "Grupo #" << i + 1 << ":" << result.at(i).size() << "items { ";
            for (unsigned int j = 0; j < result.at(i).size(); j++)
            {
                if (j != result.at(i).size() - 1)
                    cout << result.at(i).at(j) << " , ";
                else
                    cout << result.at(i).at(j);
            }
            cout << " }\n";
        }
        cout << "Se hicieron " << result.size() << " grupos" << endl;
    }
};