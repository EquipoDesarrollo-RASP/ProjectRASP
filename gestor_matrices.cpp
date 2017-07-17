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

matriz gestor_matrices::efectos_olvidados(matriz M0, matriz M1){
    int dimension=M0.getDimension();
    matriz aux=matriz(dimension,0);
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            aux.setValor(i,j,M1.getValor(i,j)-M0.getValor(i,j));
        }
    }
    return aux;
}

string gestor_matrices::buscarIntermediario(matriz R1, int fila, int columna){

    string FactorIntermediario;

    for(int i = fila; i < 15 ; i++){
        for(int j = 0; j < 15 ; j++){
            if(R1.getValor(i,j) >= 0.8){
                if(R1.getValor(j,columna) >= 0.8){
                    switch(j){
                        case 0:
                            FactorIntermediario = "Modelo Solución";
                            break;
                        case 1:
                            FactorIntermediario = "Requerimientos";
                            break;
                        case 2:
                            FactorIntermediario = "Diseño";
                            break;
                        case 3:
                            FactorIntermediario = "Plan de Pruebas";
                            break;
                        case 4:
                            FactorIntermediario = "Plan General";
                            break;
                        case 5:
                            FactorIntermediario = "Temporización";
                            break;
                        case 6:
                            FactorIntermediario = "Ciclo de Vida";
                            break;
                        case 7:
                            FactorIntermediario = "Gestión de Riesgos";
                            break;
                        case 8:
                            FactorIntermediario = "Desarrollo";
                            break;
                        case 9:
                            FactorIntermediario = "Riesgos de Tecnología";
                            break;
                        case 10:
                            FactorIntermediario = "Riesgos de Personal";
                            break;
                        case 11:
                            FactorIntermediario = "Riesgo Organizacional";
                            break;
                        case 12:
                            FactorIntermediario = "Riesgos de Herramientas";
                            break;
                        case 13:
                            FactorIntermediario = "Riesgos de Requerimientos";
                            break;
                        case 14:
                            FactorIntermediario = "Riesgo de Estimación";
                            break;
                    }
                    return FactorIntermediario;
                }
            }
        }
    }

}
