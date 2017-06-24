#ifndef INFERENCIAFUZZY_H
#define INFERENCIAFUZZY_H

class InferenciaFuzzy
{
    private:
        double var1;
        double var2;
        double var3;
        double ResultadoFinal;

    public:
        InferenciaFuzzy();
        InferenciaFuzzy(double,double,double);
        void InferenciaMamdani();
        double GetResultadoFinal(void);
        double GetVar1(void);
        double GetVar2(void);
        double GetVar3(void);
};

#endif // INFERENCIAFUZZY_H
