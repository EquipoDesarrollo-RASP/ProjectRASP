#ifndef INFERENCIAFUZZY_H
#define INFERENCIAFUZZY_H
#include <string>
using namespace std;

class InferenciaFuzzy
{
    private:
        double var1;
        double var2;
        double var3;
        double ResultadoFinal;
        string categoria;

    public:
        InferenciaFuzzy();
        InferenciaFuzzy(double,double,double,string);
        void InferenciaMamdani();
        double GetResultadoFinal(void);
        double GetVar1(void);
        double GetVar2(void);
        double GetVar3(void);
};

#endif // INFERENCIAFUZZY_H
