#ifndef INFERENCIAFUZZY_H
#define INFERENCIAFUZZY_H

#include "fp.h"

class InferenciaFuzzy
{
    private:
        double var1;
        double var2;
        double var3;
        ConjuntoDifuso Retraso;
        ConjuntoDifuso Documentacion;
        ConjuntoDifuso Importancia;
    public:
        InferenciaFuzzy();
        InferenciaFuzzy(double,double,double);
        void InferenciaMamdani();
};

#endif // INFERENCIAFUZZY_H
