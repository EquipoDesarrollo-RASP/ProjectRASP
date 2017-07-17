#include "matriz.h"
#include <stdlib.h>
#include <string>
#include <sstream>
using namespace std;

matriz::matriz(int Dimension,int Grado)
{
    grado=Grado;
    dimension=Dimension;
    valores = new float* [Dimension];
    for (int i = 0; i < Dimension; ++i) {
        valores[i]=new float [Dimension];
    }
}


void matriz::setValor(int fila, int columna,float valor){
    valores[fila][columna]=valor;
}

void matriz::setDimension(int temp){
    dimension = temp;
}

float matriz::getValor(int i, int j){
    return valores[i][j];
}

void matriz::InicializarMatriz(){
    for(int fila = 0; fila < dimension ; fila++){
        for(int columna = 0; columna < dimension ; columna++){
            if(fila == columna){
                setValor(fila,columna,-1);
            }else{
                setValor(fila,columna,0);
            }
        }
    }
}

string matriz::mostrar(){
    string retorna_matriz;
    for (int i = 0; i < getDimension(); ++i) {
            for (int j = 0; j < getDimension(); ++j) {
                std::ostringstream buff;
                buff<<valores[i][j];
                retorna_matriz+=buff.str()+" ";
            }
            retorna_matriz+="\n";
        }
    return retorna_matriz;
}

int matriz::getDimension(){
    return dimension;
}
