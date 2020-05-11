#include <iostream>
#include <unordered_map>
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
            if(buscarKey(sustantivoB)){
                grafo.at(sustantivoB).insertarRelacion(sustantivoA);
            }
            else{
                Aristas aristas;
                aristas.insertarRelacion(sustantivoA);
                grafo.insert({sustantivoB,aristas});
                cantidadRelaciones.insert({sustantivoB,0});
            }
            cantidadRelaciones.at(sustantivoA) += 1;
            cantidadRelaciones.at(sustantivoB) += 1;
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
};