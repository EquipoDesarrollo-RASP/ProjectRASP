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

float matriz::getValor(int i, int j){
    return valores[i][j];
}

string matriz::mostrar(){
    string retorna_matriz;
    for (int i = 0; i < getDimension(); ++i) {
            for (int j = 0; j < getDimension(); ++j) {
                std::ostringstream buff;
                buff<<valores[i][j];
                retorna_matriz+=buff.str()+"\t";
            }
            retorna_matriz+="\n";
        }
    return retorna_matriz;
}

int matriz::getDimension(){
    return dimension;
}
