#include <iostream>
#include <unordered_map>
#include "Aristas.cpp"

using namespace std;

class Grafo{
    private:
        unordered_map<string,Aristas> relaciones;

    public:
        Grafo(){}

        bool buscarKey(string key){
            if(this->relaciones.find(key) == this->relaciones.end()){
                return false;
            }
            return true;
        }

        void insertarRelacion(string sustantivoA,string sustantivoB){
            if(buscarKey(sustantivoA)){
                relaciones.at(sustantivoA).insertarRelacion(sustantivoB);
            }
            else {
                Aristas aristas;
                aristas.insertarRelacion(sustantivoB);
                relaciones.insert({sustantivoA,aristas});
            }
            if(buscarKey(sustantivoB)){
                relaciones.at(sustantivoB).insertarRelacion(sustantivoA);
            }
            else{
                Aristas aristas;
                aristas.insertarRelacion(sustantivoA);
                relaciones.insert({sustantivoB,aristas});
            }
        }

        Aristas buscarRelaciones(string sustantivo){
            return relaciones.at(sustantivo);
        }

        void print(){
            for (auto pair: relaciones) {
                cout << "{" << pair.first << ": ";
                pair.second.print();
                cout << "}" << endl;
            }
        }

        void print(string sustantivo){
            cout << "{" << sustantivo << ": ";
            relaciones.at(sustantivo).print();
            cout << "}" << endl;
        }
};