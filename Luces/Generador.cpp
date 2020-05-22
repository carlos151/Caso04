#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Generador {
    private:
        vector<pair<float,float>> circulo1;
        vector<pair<float,float>> circulo2;
        int radio = 4;

    public:
        Generador(int tamano){
            vector<pair<float,float>> circuloOrigen;

            vector<pair<float,float>> primerCuadrante;
            vector<pair<float,float>> segundoCuadrante;
            vector<pair<float,float>> tercerCuadrante;
            vector<pair<float,float>> cuartoCuadrante;

            primerCuadrante.push_back({radio*tamano,0});
            segundoCuadrante.push_back({0,radio*tamano});
            tercerCuadrante.push_back({-radio*tamano,0});
            cuartoCuadrante.push_back({0,-radio*tamano});

            int contador = 0;
            int cuadrante = 1;
            float const salto = radio*tamano / 4.0;
            pair<float,float> puntoActual;
            pair<float,float> last;
            while(cuadrante <= 4){
                if(cuadrante == 1){
                    last = primerCuadrante.at(primerCuadrante.size()-1);
                    if(contador == 3){
                        puntoActual = {last.first,last.second+salto*(3/4.0)};
                    }
                    else{
                        puntoActual = {last.first,last.second+salto};
                    }
                    while(!puntoEsParteDelCirculo(puntoActual.first,puntoActual.second,radio*tamano)){
                        puntoActual.first -= 0.01;
                    }
                    primerCuadrante.push_back(puntoActual);
                    if(contador == 3){
                        cuadrante++;
                    }
                }
                else if(cuadrante == 2){
                    last = segundoCuadrante.at(segundoCuadrante.size()-1);
                    if(contador == 4){
                        puntoActual = {last.first,last.second-salto*(1/4.0)};
                    }
                    else{
                        puntoActual = {last.first,last.second-salto};
                    }
                    while(!puntoEsParteDelCirculo(puntoActual.first,puntoActual.second,radio*tamano)){
                        puntoActual.first-= 0.01;
                    }
                    segundoCuadrante.push_back(puntoActual);
                    if(contador == 7){
                        cuadrante++;
                    }
                }
                else if(cuadrante == 3){
                    last = tercerCuadrante.at(tercerCuadrante.size()-1);
                    if(contador == 11){
                        puntoActual = {last.first,last.second-salto*(3/4.0)};
                    }
                    else{
                        puntoActual = {last.first,last.second-salto};
                    }
                    while(!puntoEsParteDelCirculo(puntoActual.first,puntoActual.second,radio*tamano)){
                        puntoActual.first+= 0.01;
                    }
                    tercerCuadrante.push_back(puntoActual);
                    if(contador == 11){
                        cuadrante++;
                    }
                }
                else {
                    last = cuartoCuadrante.at(cuartoCuadrante.size()-1);
                    if(contador == 12){
                        puntoActual = {last.first,last.second+salto*(1/4.0)};
                    }
                    else{
                        puntoActual = {last.first,last.second+salto};
                    }
                    while(!puntoEsParteDelCirculo(puntoActual.first,puntoActual.second,radio*tamano)){
                        puntoActual.first+= 0.01;
                    }
                    cuartoCuadrante.push_back(puntoActual);
                    if(contador == 15){
                        cuadrante++;
                    }
                }
                contador++;
            }
            circuloOrigen.reserve(primerCuadrante.size() + segundoCuadrante.size() + tercerCuadrante.size() + cuartoCuadrante.size());
            circuloOrigen.insert(circuloOrigen.end(),primerCuadrante.begin(),primerCuadrante.end());
            circuloOrigen.insert(circuloOrigen.end(),segundoCuadrante.begin(),segundoCuadrante.end());
            circuloOrigen.insert(circuloOrigen.end(),tercerCuadrante.begin(),tercerCuadrante.end());
            circuloOrigen.insert(circuloOrigen.end(),cuartoCuadrante.begin(),cuartoCuadrante.end());
            this->circulo1 = circuloOrigen;
            moverCirculo(circuloOrigen,radio*tamano);
            this->circulo2 = circuloOrigen;
        }

        
        bool puntoEsParteDelCirculo(float x, float y,int radio){
            float formula = sqrtf(pow(x,2)+pow(y,2));
            if(formula < radio+1 && formula >= radio && fmod(formula,1) < 0.01){
                return true;
            }
            return false;
        }

        void moverCirculo(vector<pair<float,float>> &puntos,int radio){
            for(auto iterador = 0; iterador < puntos.size(); iterador++){
                puntos.at(iterador).first += (radio*2-2);
            }
        }

        void printPuntos(){
            cout << "Puntos del circulo izquierdo: " << endl;
            for(int iterador = 0; iterador < circulo1.size();iterador++){
                cout << "(" << circulo1.at(iterador).first << "," << circulo1.at(iterador).second << ")" << endl;
            }
            cout << endl;
            cout << "Puntos del circulo derecho: " << endl;
            for(int iterador = 0; iterador < circulo2.size();iterador++){
                cout << "(" << circulo2.at(iterador).first << "," << circulo2.at(iterador).second << ")" << endl;
            }
        }

};