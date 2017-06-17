#ifndef FP_H
#define FP_H

#include <iostream>
using namespace std;

class ConjuntoDifuso{

    private:

        double resultado;
        double valor;
    public:
        //Constructores
        ConjuntoDifuso();
        ConjuntoDifuso(double);

        //Funcion
        void SetValor(double);
        double GetValor();
        double Triangular(double, double, double);
        double Trapezoidal(double, double, double, double);
        double FuncionL(double, double);
        double Gamma(double, double);

        double GetResultado();
        void PreCalculoDivisor(double,double);
        void PreCalculoDividendo(double,double);

        //std::vector<double> InversaTriangular(double, double, double, double);

};

#endif // FP_H
