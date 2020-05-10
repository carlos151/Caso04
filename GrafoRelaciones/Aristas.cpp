#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Aristas{
    private:
        unordered_map<string,int> aristas;
    
    public:
        Aristas(){}

        bool buscarKey(string key){
            if(this->aristas.find(key) == this->aristas.end()){
                return false;
            }
            return true;
        }

        void insertarRelacion(string sustantivo){
            if(buscarKey(sustantivo)){
                aristas.at(sustantivo)++;
            }
            else{
                aristas.insert({sustantivo,1});
            }
        }

        void print(){
            for (auto const& pair: aristas) {
                cout << "{" << pair.first << ": " << pair.second << "}";
            }
        }

        void print(string sustantivo){
            cout << "{" << sustantivo << ": " << aristas.at(sustantivo) << "}\n";
        }
};