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
        ConjuntoDifuso Riesgos[23];

        //Regla 1
        if(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Mucho_retraso,Muy_importante)) >= 0.1){
            Riesgos[0].SetValor(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Mucho_retraso,Muy_importante)));
            Riesgos[0].PreCalculoDivisor(90,100);
            Riesgos[0].PreCalculoDividendo(90,100);
        }

        //Regla 2
        if(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Algo_retraso,Muy_importante)) >= 0.1){
            Riesgos[1].SetValor(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Algo_retraso,Muy_importante)));
            Riesgos[1].PreCalculoDivisor(90,100);
            Riesgos[1].PreCalculoDividendo(90,100);
        }

        //Regla 3
        if(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Algo_retraso,Algo_importante)) >= 0.1){
            Riesgos[2].SetValor(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Algo_retraso,Algo_importante)));
            Riesgos[2].PreCalculoDivisor(65,80);
            Riesgos[2].PreCalculoDividendo(65,80);
        }

        //Regla 4
        if(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Poco_retraso,Muy_importante)) >= 0.1){
            Riesgos[3].SetValor(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Poco_retraso,Muy_importante)));
            Riesgos[3].PreCalculoDivisor(65,80);
            Riesgos[3].PreCalculoDividendo(65,80);
        }

        //Regla 5
        if(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Poco_retraso,Algo_importante)) >= 0.1){
            Riesgos[4].SetValor(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Poco_retraso,Algo_importante)));
            Riesgos[4].PreCalculoDivisor(65,80);
            Riesgos[4].PreCalculoDividendo(65,80);
        }

        //Regla 6
        if(operador.FuzzyAND(Pobre_documentacion,operador.FuzzyAND(Mucho_retraso,Muy_importante)) >= 0.1){
            Riesgos[5].SetValor(operador.FuzzyAND(Pobre_documentacion,operador.FuzzyAND(Mucho_retraso,Muy_importante)));
            Riesgos[5].PreCalculoDivisor(90,100);
            Riesgos[5].PreCalculoDividendo(90,100);
        }

        //Regla 7
        if(operador.FuzzyAND(Pobre_documentacion,operador.FuzzyAND(Algo_retraso,Muy_importante)) >= 0.1){
            Riesgos[6].SetValor(operador.FuzzyAND(Pobre_documentacion,operador.FuzzyAND(Algo_retraso,Muy_importante)));
            Riesgos[6].PreCalculoDivisor(90,100);
            Riesgos[6].PreCalculoDividendo(90,100);
        }

        //Regla 8
        if(operador.FuzzyAND(Pobre_documentacion,operador.FuzzyAND(Algo_retraso,Algo_importante)) >= 0.1){
            Riesgos[7].SetValor(operador.FuzzyAND(Pobre_documentacion,operador.FuzzyAND(Algo_retraso,Algo_importante)));
            Riesgos[7].PreCalculoDivisor(65,80);
            Riesgos[7].PreCalculoDividendo(65,80);
        }

        //Regla 9
        if(operador.FuzzyAND(Pobre_documentacion,operador.FuzzyAND(Poco_retraso,Algo_importante)) >= 0.1){
            Riesgos[8].SetValor(operador.FuzzyAND(Pobre_documentacion,operador.FuzzyAND(Poco_retraso,Algo_importante)));
            Riesgos[8].PreCalculoDivisor(40,60);
            Riesgos[8].PreCalculoDividendo(40,60);
        }

        //Regla 10
        if(operador.FuzzyAND(Pobre_documentacion,operador.FuzzyAND(Poco_retraso,Muy_importante)) >= 0.1){
            Riesgos[9].SetValor(operador.FuzzyAND(Pobre_documentacion,operador.FuzzyAND(Poco_retraso,Muy_importante)));
            Riesgos[9].PreCalculoDivisor(65,80);
            Riesgos[9].PreCalculoDividendo(65,80);
        }

        //Regla 11
        if(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Mucho_retraso,Muy_importante)) >= 0.1){
            Riesgos[10].SetValor(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Mucho_retraso,Muy_importante)));
            Riesgos[10].PreCalculoDivisor(90,100);
            Riesgos[10].PreCalculoDividendo(90,100);
        }

        //Regla 12
        if(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Mucho_retraso,Algo_importante)) >= 0.1){
            Riesgos[11].SetValor(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Mucho_retraso,Algo_importante)));
            Riesgos[11].PreCalculoDivisor(65,80);
            Riesgos[11].PreCalculoDividendo(65,80);
        }

        //Regla 13
        if(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Mucho_retraso,Poco_importante)) >= 0.1){
            Riesgos[12].SetValor(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Mucho_retraso,Poco_importante)));
            Riesgos[12].PreCalculoDivisor(40,60);
            Riesgos[12].PreCalculoDividendo(40,60);
        }

        //Regla 14
        if(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Algo_retraso,Muy_importante)) >= 0.1){
            Riesgos[13].SetValor(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Algo_retraso,Muy_importante)));
            Riesgos[13].PreCalculoDivisor(65,80);
            Riesgos[13].PreCalculoDividendo(65,80);
        }

        //Regla 15
        if(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Algo_retraso,Algo_importante)) >= 0.1){
            Riesgos[14].SetValor(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Algo_retraso,Algo_importante)));
            Riesgos[14].PreCalculoDivisor(40,60);
            Riesgos[14].PreCalculoDividendo(40,60);
        }

        //Regla 16
        if(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Algo_retraso,Poco_importante)) >= 0.1){
            Riesgos[15].SetValor(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Algo_retraso,Poco_importante)));
            Riesgos[15].PreCalculoDivisor(20,35);
            Riesgos[15].PreCalculoDividendo(20,35);
        }

        //Regla 17
        if(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Poco_retraso,Muy_importante)) >= 0.1){
            Riesgos[16].SetValor(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Poco_retraso,Muy_importante)));
            Riesgos[16].PreCalculoDivisor(20,35);
            Riesgos[16].PreCalculoDividendo(20,35);
        }

        //Regla 18
        if(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Poco_retraso,Algo_importante)) >= 0.1){
            Riesgos[17].SetValor(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Poco_retraso,Algo_importante)));
            Riesgos[17].PreCalculoDivisor(20,35);
            Riesgos[17].PreCalculoDividendo(20,35);
        }

        //Regla 19
        if(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Poco_retraso,Poco_importante)) >= 0.1){
            Riesgos[18].SetValor(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Poco_retraso,Poco_importante)));
            Riesgos[18].PreCalculoDivisor(0,10);
            Riesgos[18].PreCalculoDividendo(0,10);
        }

        //Regla 20
        if(operador.FuzzyAND(Buena_documentacion,operador.FuzzyAND(Mucho_retraso,Muy_importante)) >= 0.1){
            Riesgos[19].SetValor(operador.FuzzyAND(Buena_documentacion,operador.FuzzyAND(Mucho_retraso,Muy_importante)));
            Riesgos[19].PreCalculoDivisor(65,80);
            Riesgos[19].PreCalculoDividendo(65,80);
        }

        //Regla 21
        if(operador.FuzzyAND(Buena_documentacion,operador.FuzzyAND(Algo_retraso,Muy_importante)) >= 0.1){
            Riesgos[20].SetValor(operador.FuzzyAND(Buena_documentacion,operador.FuzzyAND(Algo_retraso,Muy_importante)));
            Riesgos[20].PreCalculoDivisor(40,60);
            Riesgos[20].PreCalculoDividendo(40,60);
        }

        //Regla 22
        if(operador.FuzzyAND(Buena_documentacion,operador.FuzzyAND(Poco_retraso,Muy_importante)) >= 0.1){
            Riesgos[21].SetValor(operador.FuzzyAND(Buena_documentacion,operador.FuzzyAND(Poco_retraso,Muy_importante)));
            Riesgos[21].PreCalculoDivisor(0,10);
            Riesgos[21].PreCalculoDividendo(0,10);
        }

        //Regla 23
        if(operador.FuzzyAND(Buena_documentacion,operador.FuzzyAND(Poco_retraso,Algo_importante)) >= 0.1){
            Riesgos[22].SetValor(operador.FuzzyAND(Buena_documentacion,operador.FuzzyAND(Poco_retraso,Algo_importante)));
            Riesgos[22].PreCalculoDivisor(0,10);
            Riesgos[22].PreCalculoDividendo(0,10);
        }

        //DESFUSIFICACION
        int i;
        double divisor,dividendo;
        for(i = 0; i < 23 ; i++){
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
