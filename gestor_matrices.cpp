#include "gestor_matrices.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

gestor_matrices::gestor_matrices()
{
    matrices =(matriz*) malloc(sizeof(matriz));
    ocupacion=0;
}

void gestor_matrices::agregar_matriz(matriz Matriz){
    matrices[ocupacion]=Matriz;
    ocupacion++;
}

matriz gestor_matrices::siguiente_grado(matriz &Matriz){
    int dimension=Matriz.getDimension();
    float menores[dimension];

    matriz aux=matriz(dimension,ocupacion);

    for (int i = 0; i < dimension; ++i) {
        for (int k = 0; k < dimension; ++k) {
            for (int j = 0; j < dimension; ++j) {
                if(Matriz.getValor(i,j)<=Matriz.getValor(j,k))menores[j]=Matriz.getValor(i,j);
                else menores[j]=Matriz.getValor(j,k);
            }
        aux.setValor(i,k,Obtener_Mayor(menores,dimension));

        }
    }
    return aux;
}

float gestor_matrices::Obtener_Mayor(float menores[],int dimension){
    float aux=0;

    for (int i = 0; i < dimension; ++i) {
        if(aux<=menores[i])aux=menores[i];
    }

    return aux;
}

matriz gestor_matrices::Obtener_Matriz(int id){
    return matrices[id];
}
