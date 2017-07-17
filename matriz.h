#ifndef MATRIZ_H
#define MATRIZ_H
#include <string>
using namespace std;

class matriz
{
private:
    int grado, dimension;
    float** valores;

public:

    matriz();
    matriz(int Dimension,int Grado);
    void setValor(int fila,int columna,float valor);
    string mostrar();
    int getDimension();
    void setDimension(int temp);
    float getValor(int i,int j);
    void InicializarMatriz();
};

#endif // MATRIZ_H
