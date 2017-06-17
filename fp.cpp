#include "fp.h"

/*
Constructores de la clase FuncionPertenencia
*/
ConjuntoDifuso::ConjuntoDifuso(void){
    resultado = 0.0;
    valor = 0.0;
}

ConjuntoDifuso::ConjuntoDifuso(double valorObtenido){
    valor = valorObtenido;
    resultado = 0.0;
}

/*
Con esta funcion se setea el valor inrgesado por el
usuario, para efectuar los calculos con las funciones
de pertenencia.
*/
void ConjuntoDifuso::SetValor(double x){
    valor = x;
}

double ConjuntoDifuso::GetValor(){
    return valor;
}

/*
Funcion de pertenencia triangular recibe como
parametro 3 valores asociados con un valor linguistico
retorna un resultado que es el valor difuso asociado
de la funcion de pertenencia.
*/
double ConjuntoDifuso::Triangular(double alfa, double beta, double gamma){

    if(valor >= alfa && valor <= beta){
        resultado = (valor-alfa)/(beta-alfa);
    }else if(valor >= beta && valor <= gamma){
        resultado = (gamma - valor)/(gamma - beta);
    }else{
        resultado = 0;
    }

    return resultado;
}

/*
Funcion de pertenencia trapezoidal recibe como
parametro 4 valores asociados con un valor linguistico
retorna un resultado que es el valor difuso asociado
de la funcion de pertenencia.
*/
double ConjuntoDifuso::Trapezoidal(double alfa, double beta, double gamma, double delta){

    if(valor >= alfa && valor <= beta){
        resultado = (valor-alfa)/(beta-alfa);
    }else if(valor >= gamma && valor <= delta){
        resultado = (delta - valor)/(delta - gamma);
    }else if(valor > beta && valor < gamma){
        resultado = 1;
    }else if(valor < alfa || valor > delta){
        resultado = 0;
    }

    return resultado;
}

/*
Funcion de pertenencia L recibe como
parametro 2 valores asociados con un valor linguistico
retorna un resultado que es el valor difuso asociado
de la funcion de pertenencia.
*/
double ConjuntoDifuso::FuncionL(double alfa, double beta){

    if(valor >= alfa && valor <= beta){
        resultado = (beta - valor)/(beta - alfa);
    }else if(valor < alfa){
        resultado = 1;
    }else if(valor > beta){
        resultado = 0;
    }

    return resultado;
}

/*
Funcion de pertenencia Gamma recibe como
parametro 2 valores asociados con un valor linguistico
retorna un resultado que es el valor difuso asociado
de la funcion de pertenencia.
*/
double ConjuntoDifuso::Gamma(double alfa, double beta){

    if(valor >= alfa && valor <= beta){
        resultado = (valor - alfa)/(beta - alfa);
    }else if(valor < alfa){
        resultado = 0;
    }else if(valor > beta){
        resultado = 1;
    }

    return resultado;
}


double ConjuntoDifuso::GetResultado(){
    return resultado;
}

void ConjuntoDifuso::PreCalculoDivisor(double minRango, double maxRango){

    while(minRango <= maxRango){
        resultado = minRango + resultado;
        minRango += 10;
    }
    resultado = resultado * valor;

}

void ConjuntoDifuso::PreCalculoDividendo(double minRango,double maxRango){

    while(minRango <= maxRango){
        valor += valor;
        minRango += 10;
    }
}

/*
std::vector<double> FuncionPertenencia::InversaTriangular(double x, double alfa, double beta, double gamma){

    double resultados[2];

    resultados[0] = alfa + (x*beta) - (x*alfa);
    resultados[1] = gamma - (x*gamma) + (x*beta);

    return resultados;
}*/
