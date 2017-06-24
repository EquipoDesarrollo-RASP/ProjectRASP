#include "inferenciafuzzy.h"
#include "fp.h"
#include "fo.h"

InferenciaFuzzy::InferenciaFuzzy()
{
    var1 = 0;
    var2 = 0;
    var3 = 0;
    ResultadoFinal = 0;
}

InferenciaFuzzy::InferenciaFuzzy(double PrimerValor, double SegundoValor, double TercerValor){
    var1 = PrimerValor;
    var2 = SegundoValor;
    var3 = TercerValor;
}

void InferenciaFuzzy::InferenciaMamdani(){
        //DeclaraciÃ³n de variables linguisticas
        ConjuntoDifuso Retraso(var1);
        ConjuntoDifuso Documentacion(var2);
        ConjuntoDifuso Importancia(var3);

        // Declaracion de valores linguisticos de sus respectivas variables linguisticas
        // Para la Variable RETRASO
        double Poco_retraso = Retraso.FuncionL(10,30);
        double Algo_retraso = Retraso.Triangular(20,40,60);
        double Mucho_retraso = Retraso.Gamma(50,70);

        // Para la variable DOCUMENTACION
        double Nada_documentacion = Documentacion.FuncionL(0,10);
        double Pobre_documentacion = Documentacion.Trapezoidal(0,10,20,30);
        double AlgoBuena_documentacion = Documentacion.Trapezoidal(20,40,70,90);
        double Buena_documentacion = Documentacion.Gamma(80,100);

        // Para la variable IMPORTANCIA
        double Poco_importante = Importancia.FuncionL(10,30);
        double Algo_importante = Importancia.Triangular(20,40,60);
        double Muy_importante = Importancia.Gamma(50,70);

        //REGLAS DIFUSAS
        FuzzyOperator operador;
        ConjuntoDifuso Riesgos[4];

        //Regla 1
        if(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Mucho_retraso,Muy_importante)) >= 0.4){
            Riesgos[0].SetValor(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Mucho_retraso,Muy_importante)));
            Riesgos[0].PreCalculoDivisor(80,100);
            Riesgos[0].PreCalculoDividendo(80,100);
        }

        //Regla 2
        if(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Algo_retraso,Muy_importante)) >= 0.4){
            Riesgos[1].SetValor(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Algo_retraso,Muy_importante)));
            Riesgos[1].PreCalculoDivisor(80,100);
            Riesgos[1].PreCalculoDividendo(80,100);
        }else{
            Riesgos[1].SetValor(0);
            Riesgos[1].PreCalculoDivisor(80,100);
            Riesgos[1].PreCalculoDividendo(80,100);
        }

        //Regla 3
        if(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Algo_retraso,Algo_importante)) >= 0.4){
            Riesgos[2].SetValor(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Algo_retraso,Algo_importante)));
            Riesgos[2].PreCalculoDivisor(50,90);
            Riesgos[2].PreCalculoDividendo(50,90);
        }

        //Regla 4
        if(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Poco_retraso,Algo_importante)) >= 0.4){
            Riesgos[3].SetValor(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Poco_retraso,Algo_importante)));
            Riesgos[3].PreCalculoDivisor(50,90);
            Riesgos[3].PreCalculoDividendo(50,90);
        }

        //DESFUSIFICACION
        int i;
        double divisor,dividendo;
        for(i = 0; i < 4 ; i++){
            divisor += Riesgos[i].GetResultado();
            dividendo += Riesgos[i].GetValor();
        }
        ResultadoFinal = (divisor / dividendo)*100;

}

double InferenciaFuzzy::GetResultadoFinal(){
    return ResultadoFinal;
}

double InferenciaFuzzy::GetVar1(){
    return var1;
}

double InferenciaFuzzy::GetVar2(){
    return var2;
}

double InferenciaFuzzy::GetVar3(){
    return var3;
}
