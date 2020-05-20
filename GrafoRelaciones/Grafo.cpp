#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "Aristas.cpp"

using namespace std;

class Grafo{
    private:
        unordered_map<string,Aristas> grafo;
        unordered_map<string,int> cantidadRelaciones;

    public:
        Grafo(){}

        int buscarCantidadRelaciones(string sustantivo){
            if(this->cantidadRelaciones.find(sustantivo) != this->cantidadRelaciones.end()){
                return cantidadRelaciones.at(sustantivo);
            }
            return 0;
        }

        bool buscarKey(string key){
            if(this->grafo.find(key) == this->grafo.end()){
                return false;
            }
            return true;
        }

        void insertarRelacion(string sustantivoA,string sustantivoB){
            if(buscarKey(sustantivoA)){
                grafo.at(sustantivoA).insertarRelacion(sustantivoB);
            }
            else {
                Aristas aristas;
                aristas.insertarRelacion(sustantivoB);
                grafo.insert({sustantivoA,aristas});
                cantidadRelaciones.insert({sustantivoA,0});
            }
            cantidadRelaciones.at(sustantivoA) += 1;
        }

        Aristas buscarRelaciones(string sustantivo){
            return grafo.at(sustantivo);
        }

        void print(){
            for (auto pair: grafo) {
                cout << "{" << pair.first << ": ";
                pair.second.print();
                cout << "}" << endl;
            }
        }

        void printRelaciones(){
            for (auto pair: cantidadRelaciones) {
                cout << "{" << pair.first << ": " << pair.second << "}" << endl;
            }
        }

        void print(string sustantivo){
            cout << "{" << sustantivo << ": ";
            grafo.at(sustantivo).print();
            cout << "}" << endl;
        }

        bool static comparar(pair<string,int> a, pair<string,int> b) {
            return (a.second > b.second);
        }

        void palabrasMasPoderosas(int cantidad){
            vector<pair<string,int>> sortRelaciones(cantidadRelaciones.begin(),cantidadRelaciones.end());
            sort(sortRelaciones.begin(),sortRelaciones.end(),comparar);
            cout << "Las " << cantidad << " palabras más poderosas:" << endl;
            for(int iterador = 0; iterador < cantidad; iterador++){
                cout << sortRelaciones.at(iterador).first << endl;
            }
            cout << endl;
        }

        bool esLaRelacionMasPoderosa(string palabra,string palabraP){
            unordered_map<string,int> relacionesDePalabra = buscarRelaciones(palabra).getMap();
            vector<pair<string,int>> sortRelaciones(relacionesDePalabra.begin(),relacionesDePalabra.end());
            sort(sortRelaciones.begin(),sortRelaciones.end(),comparar);
            if(sortRelaciones.at(0).first == palabraP){
                return true;
            }
            return false;
        }

        void palabrasMasPoderP(string palabraP){
            unordered_map<string,int> relacionesDeP = buscarRelaciones(palabraP).getMap();
            cout << "Palabras sobre la que la palabra " << palabraP << " tiene más poder:" << endl;
            for(auto iterador = relacionesDeP.begin(); iterador != relacionesDeP.end();iterador++){
                if(esLaRelacionMasPoderosa(iterador->first,palabraP)){
                    cout << iterador->first << endl;
                }
            }
            cout << endl;
        }
};