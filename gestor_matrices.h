#ifndef GESTOR_MATRICES_H
#define GESTOR_MATRICES_H
#include "matriz.h"

class gestor_matrices
{
private:
    matriz* matrices;
    int ocupacion;
    int* Dimensiones;
public:
    gestor_matrices();
    void agregar_matriz(matriz Matriz);
    matriz siguiente_grado(matriz &Matriz);
    matriz Obtener_Matriz(int id);
    float Obtener_Mayor(float menores[],int dimension);
    matriz efectos_olvidados(matriz M0,matriz M1);
};

#endif // GESTOR_MATRICES_H
