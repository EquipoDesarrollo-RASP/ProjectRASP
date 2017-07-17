#include "inferenciafuzzy.h"
#include "fp.h"
#include "fo.h"
#include <QDebug>

InferenciaFuzzy::InferenciaFuzzy()
{
    var1 = 0;
    var2 = 0;
    var3 = 0;
    ResultadoFinal = 0;
}

InferenciaFuzzy::InferenciaFuzzy(double PrimerValor, double SegundoValor, double TercerValor, string cat){
    var1 = PrimerValor;
    var2 = SegundoValor;
    var3 = TercerValor;
    categoria = cat;
}

void InferenciaFuzzy::InferenciaMamdani(){
        //DeclaraciÃ³n de variables linguisticas
        ConjuntoDifuso Retraso(var1);
        ConjuntoDifuso Documentacion(var2);
        ConjuntoDifuso Importancia(var3);

        ConjuntoDifuso Desarrollo(var1);
        ConjuntoDifuso Planificacion(var2);
        ConjuntoDifuso Procesos(var3);

        ConjuntoDifuso AnalisisRiesgo(var1);
        ConjuntoDifuso RiesgoTecno(var2);
        ConjuntoDifuso RiesgoPerso(var2);
        ConjuntoDifuso RiesgoOrg(var2);
        ConjuntoDifuso RiesgoHerr(var2);
        ConjuntoDifuso RiesgoRequ(var2);
        ConjuntoDifuso RiesgoEst(var2);

        // Declaracion de valores linguisticos de sus respectivas variables linguisticas
        // Para la Variable RETRASO
        double Poco_retraso = Retraso.FuncionL(10,50);
        double Algo_retraso = Retraso.Triangular(10,50,90);
        double Mucho_retraso = Retraso.Gamma(50,90);

        // Para la variable DOCUMENTACION
        double Nada_documentacion = Documentacion.FuncionL(0,10);
        double Pobre_documentacion = Documentacion.Trapezoidal(5,15,45,55);
        double AlgoBuena_documentacion = Documentacion.Trapezoidal(45,55,85,95);
        double Buena_documentacion = Documentacion.Gamma(90,100);

        // Para la variable IMPORTANCIA
        double Poco_importante = Importancia.FuncionL(10,50);
        double Algo_importante = Importancia.Triangular(10,50,90);
        double Muy_importante = Importancia.Gamma(50,90);

        // Para la variable DESARROLLO
        double No_desarrollo = Desarrollo.FuncionL(10,25);
        double Poco_desarrollo = Desarrollo.Triangular(10,25,50);
        double Algo_desarrollo = Desarrollo.Triangular(25,50,75);
        double Si_desarrollo = Desarrollo.Gamma(75,90);

        // Para la variable PLANIFICACION
        double No_planificacion = Planificacion.FuncionL(10,50);
        double MasMenos_planificacion = Planificacion.Triangular(10,50,90);
        double Si_planificacion = Planificacion.Gamma(50,90);

        // Para la variable PROCESOS
        double Poco_proceso = Procesos.FuncionL(10,50);
        double Algo_proceso = Procesos.Triangular(10,50,90);
        double Mucho_proceso = Procesos.Gamma(50,90);

        // Para la variable ANALISIS RIESGO
        double Poco_analisis = AnalisisRiesgo.FuncionL(10,50);
        double Algo_analisis = AnalisisRiesgo.Triangular(10,50,90);
        double Mucho_analisis = AnalisisRiesgo.Gamma(50,90);

        // Para la variable RIESGO TECN.
        double Poco_tec = RiesgoTecno.FuncionL(10,50);
        double Algo_tec = RiesgoTecno.Triangular(10,50,90);
        double Mucho_tec = RiesgoTecno.Gamma(50,90);

        // Para la variable RIESGO PERS.
        double No_calificado = RiesgoPerso.FuncionL(10,50);
        double Talvez_calificado = RiesgoPerso.Triangular(10,50,90);
        double Si_calificado = RiesgoPerso.Gamma(50,90);

        // Para la variable RIESGO ORG.
        double Poco_cumplido = RiesgoOrg.FuncionL(10,50);
        double Algo_cumplido = RiesgoOrg.Triangular(10,50,90);
        double Mucho_cumplido = RiesgoOrg.Gamma(50,90);

        // Para la variable RIESGO HERR.
        double Poco_util = RiesgoHerr.FuncionL(10,50);
        double Algo_util = RiesgoHerr.Triangular(10,50,90);
        double Mucho_util = RiesgoHerr.Gamma(50,90);

        // Para la variable RIESGO REQUE.
        double Poco_impacto = RiesgoRequ.FuncionL(10,50);
        double Algo_impacto = RiesgoRequ.Triangular(10,50,90);
        double Mucho_impacto = RiesgoRequ.Gamma(50,90);

        // Para la variable RIESGO ESTI.
        double Poco_subestimado = RiesgoEst.FuncionL(10,50);
        double Algo_subestimado = RiesgoEst.Triangular(10,50,90);
        double Mucho_subestimado = RiesgoEst.Gamma(50,90);

        //REGLAS DIFUSAS
        FuzzyOperator operador;
        ConjuntoDifuso Riesgos[23];
        double umbral = 0.2;

        //Regla 1
        if(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Mucho_retraso,Muy_importante)) >= umbral){
            qDebug() << Nada_documentacion << Mucho_retraso << Muy_importante;
            Riesgos[0].SetValor(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Mucho_retraso,Muy_importante)));
            Riesgos[0].PreCalculoDivisor(90,100);
            Riesgos[0].PreCalculoDividendo(90,100);
        }

        //Regla 2
        if(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Algo_retraso,Muy_importante)) >= umbral){
            Riesgos[1].SetValor(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Algo_retraso,Muy_importante)));
            Riesgos[1].PreCalculoDivisor(90,100);
            Riesgos[1].PreCalculoDividendo(90,100);
        }

        //Regla 3
        if(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Algo_retraso,Algo_importante)) >= umbral){
            Riesgos[2].SetValor(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Algo_retraso,Algo_importante)));
            Riesgos[2].PreCalculoDivisor(70,80);
            Riesgos[2].PreCalculoDividendo(70,80);
        }

        //Regla 4
        if(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Poco_retraso,Muy_importante)) >= umbral){
            Riesgos[3].SetValor(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Poco_retraso,Muy_importante)));
            Riesgos[3].PreCalculoDivisor(70,80);
            Riesgos[3].PreCalculoDividendo(70,80);
        }

        //Regla 5
        if(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Poco_retraso,Algo_importante)) >= umbral){
            Riesgos[4].SetValor(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Poco_retraso,Algo_importante)));
            Riesgos[4].PreCalculoDivisor(70,80);
            Riesgos[4].PreCalculoDividendo(70,80);
        }

        //Regla 6
        if(operador.FuzzyAND(Pobre_documentacion,operador.FuzzyAND(Mucho_retraso,Muy_importante)) >= umbral){
            Riesgos[5].SetValor(operador.FuzzyAND(Pobre_documentacion,operador.FuzzyAND(Mucho_retraso,Muy_importante)));
            Riesgos[5].PreCalculoDivisor(90,100);
            Riesgos[5].PreCalculoDividendo(90,100);
        }

        //Regla 7
        if(operador.FuzzyAND(Pobre_documentacion,operador.FuzzyAND(Algo_retraso,Muy_importante)) >= umbral){
            Riesgos[6].SetValor(operador.FuzzyAND(Pobre_documentacion,operador.FuzzyAND(Algo_retraso,Muy_importante)));
            Riesgos[6].PreCalculoDivisor(90,100);
            Riesgos[6].PreCalculoDividendo(90,100);
        }

        //Regla 8
        if(operador.FuzzyAND(Pobre_documentacion,operador.FuzzyAND(Algo_retraso,Algo_importante)) >= umbral){
            Riesgos[7].SetValor(operador.FuzzyAND(Pobre_documentacion,operador.FuzzyAND(Algo_retraso,Algo_importante)));
            Riesgos[7].PreCalculoDivisor(70,80);
            Riesgos[7].PreCalculoDividendo(70,80);
        }

        //Regla 9
        if(operador.FuzzyAND(Pobre_documentacion,operador.FuzzyAND(Poco_retraso,Algo_importante)) >= umbral){
            Riesgos[8].SetValor(operador.FuzzyAND(Pobre_documentacion,operador.FuzzyAND(Poco_retraso,Algo_importante)));
            Riesgos[8].PreCalculoDivisor(40,60);
            Riesgos[8].PreCalculoDividendo(40,60);
        }

        //Regla 10
        if(operador.FuzzyAND(Pobre_documentacion,operador.FuzzyAND(Poco_retraso,Muy_importante)) >= umbral){
            Riesgos[9].SetValor(operador.FuzzyAND(Pobre_documentacion,operador.FuzzyAND(Poco_retraso,Muy_importante)));
            Riesgos[9].PreCalculoDivisor(70,80);
            Riesgos[9].PreCalculoDividendo(70,80);
        }

        //Regla 11
        if(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Mucho_retraso,Muy_importante)) >= umbral){
            Riesgos[10].SetValor(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Mucho_retraso,Muy_importante)));
            Riesgos[10].PreCalculoDivisor(90,100);
            Riesgos[10].PreCalculoDividendo(90,100);
        }

        //Regla 12
        if(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Mucho_retraso,Algo_importante)) >= umbral){
            Riesgos[11].SetValor(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Mucho_retraso,Algo_importante)));
            Riesgos[11].PreCalculoDivisor(70,80);
            Riesgos[11].PreCalculoDividendo(70,80);
        }

        //Regla 13
        if(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Mucho_retraso,Poco_importante)) >= umbral){
            Riesgos[12].SetValor(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Mucho_retraso,Poco_importante)));
            Riesgos[12].PreCalculoDivisor(40,60);
            Riesgos[12].PreCalculoDividendo(40,60);
        }

        //Regla 14
        if(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Algo_retraso,Muy_importante)) >= umbral){
            Riesgos[13].SetValor(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Algo_retraso,Muy_importante)));
            Riesgos[13].PreCalculoDivisor(70,80);
            Riesgos[13].PreCalculoDividendo(70,80);
        }

        //Regla 15
        if(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Algo_retraso,Algo_importante)) >= umbral){
            Riesgos[14].SetValor(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Algo_retraso,Algo_importante)));
            Riesgos[14].PreCalculoDivisor(40,60);
            Riesgos[14].PreCalculoDividendo(40,60);
        }

        //Regla 16
        if(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Algo_retraso,Poco_importante)) >= umbral){
            Riesgos[15].SetValor(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Algo_retraso,Poco_importante)));
            Riesgos[15].PreCalculoDivisor(20,30);
            Riesgos[15].PreCalculoDividendo(20,30);
        }

        //Regla 17
        if(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Poco_retraso,Muy_importante)) >= umbral){
            Riesgos[16].SetValor(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Poco_retraso,Muy_importante)));
            Riesgos[16].PreCalculoDivisor(20,30);
            Riesgos[16].PreCalculoDividendo(20,30);
        }

        //Regla 18
        if(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Poco_retraso,Algo_importante)) >= umbral){
            Riesgos[17].SetValor(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Poco_retraso,Algo_importante)));
            Riesgos[17].PreCalculoDivisor(20,30);
            Riesgos[17].PreCalculoDividendo(20,30);
        }

        //Regla 19
        if(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Poco_retraso,Poco_importante)) >= umbral){
            Riesgos[18].SetValor(operador.FuzzyAND(AlgoBuena_documentacion,operador.FuzzyAND(Poco_retraso,Poco_importante)));
            Riesgos[18].PreCalculoDivisor(0,10);
            Riesgos[18].PreCalculoDividendo(0,10);
        }

        //Regla 20
        if(operador.FuzzyAND(Buena_documentacion,operador.FuzzyAND(Mucho_retraso,Muy_importante)) >= umbral){
            Riesgos[19].SetValor(operador.FuzzyAND(Buena_documentacion,operador.FuzzyAND(Mucho_retraso,Muy_importante)));
            Riesgos[19].PreCalculoDivisor(70,80);
            Riesgos[19].PreCalculoDividendo(70,80);
        }

        //Regla 21
        if(operador.FuzzyAND(Buena_documentacion,operador.FuzzyAND(Algo_retraso,Muy_importante)) >= umbral){
            Riesgos[20].SetValor(operador.FuzzyAND(Buena_documentacion,operador.FuzzyAND(Algo_retraso,Muy_importante)));
            Riesgos[20].PreCalculoDivisor(40,60);
            Riesgos[20].PreCalculoDividendo(40,60);
        }

        //Regla 22
        if(operador.FuzzyAND(Buena_documentacion,operador.FuzzyAND(Poco_retraso,Muy_importante)) >= umbral){
            Riesgos[21].SetValor(operador.FuzzyAND(Buena_documentacion,operador.FuzzyAND(Poco_retraso,Muy_importante)));
            Riesgos[21].PreCalculoDivisor(0,10);
            Riesgos[21].PreCalculoDividendo(0,10);
        }

        //Regla 23
        if(operador.FuzzyAND(Buena_documentacion,operador.FuzzyAND(Poco_retraso,Algo_importante)) >= umbral){
            Riesgos[22].SetValor(operador.FuzzyAND(Buena_documentacion,operador.FuzzyAND(Poco_retraso,Algo_importante)));
            Riesgos[22].PreCalculoDivisor(0,10);
            Riesgos[22].PreCalculoDividendo(0,10);
        }
/*
        //Regla 24  ****** DESARROLLO ********
        if(operador.FuzzyAND(No_desarrollo,operador.FuzzyAND(No_planificacion,Poco_proceso)) >= umbral){
            Riesgos[23].SetValor(operador.FuzzyAND(No_desarrollo,operador.FuzzyAND(No_planificacion,Poco_proceso)));
            Riesgos[23].PreCalculoDivisor(90,100);
            Riesgos[23].PreCalculoDividendo(90,100);
        }

        //Regla 25
        if(operador.FuzzyAND(No_desarrollo,operador.FuzzyAND(No_planificacion,Algo_proceso)) >= umbral){
            Riesgos[24].SetValor(operador.FuzzyAND(No_desarrollo,operador.FuzzyAND(No_planificacion,Algo_proceso)));
            Riesgos[24].PreCalculoDivisor(90,100);
            Riesgos[24].PreCalculoDividendo(90,100);
        }

        //Regla 26
        if(operador.FuzzyAND(No_desarrollo,operador.FuzzyAND(No_planificacion,Mucho_proceso)) >= umbral){
            Riesgos[25].SetValor(operador.FuzzyAND(No_desarrollo,operador.FuzzyAND(No_planificacion,Mucho_proceso)));
            Riesgos[25].PreCalculoDivisor(90,100);
            Riesgos[25].PreCalculoDividendo(90,100);
        }

        //Regla 27
        if(operador.FuzzyAND(No_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Poco_proceso)) >= umbral){
            Riesgos[26].SetValor(operador.FuzzyAND(No_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Poco_proceso)));
            Riesgos[26].PreCalculoDivisor(90,100);
            Riesgos[26].PreCalculoDividendo(90,100);
        }

        //Regla 28
        if(operador.FuzzyAND(No_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Algo_proceso)) >= umbral){
            Riesgos[27].SetValor(operador.FuzzyAND(No_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Algo_proceso)));
            Riesgos[27].PreCalculoDivisor(70,80);
            Riesgos[27].PreCalculoDividendo(70,80);
        }

        //Regla 29
        if(operador.FuzzyAND(No_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Mucho_proceso)) >= umbral){
            Riesgos[28].SetValor(operador.FuzzyAND(No_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Mucho_proceso)));
            Riesgos[28].PreCalculoDivisor(70,80);
            Riesgos[28].PreCalculoDividendo(70,80);
        }

        //Regla 30
        if(operador.FuzzyAND(No_desarrollo,operador.FuzzyAND(Si_planificacion,Poco_proceso)) >= umbral){
            Riesgos[29].SetValor(operador.FuzzyAND(No_desarrollo,operador.FuzzyAND(Si_planificacion,Poco_proceso)));
            Riesgos[29].PreCalculoDivisor(70,80);
            Riesgos[29].PreCalculoDividendo(70,80);
        }

        //Regla 31
        if(operador.FuzzyAND(No_desarrollo,operador.FuzzyAND(Si_planificacion,Algo_proceso)) >= umbral){
            Riesgos[30].SetValor(operador.FuzzyAND(No_desarrollo,operador.FuzzyAND(Si_planificacion,Algo_proceso)));
            Riesgos[30].PreCalculoDivisor(70,80);
            Riesgos[30].PreCalculoDividendo(70,80);
        }

        //Regla 32
        if(operador.FuzzyAND(No_desarrollo,operador.FuzzyAND(Si_planificacion,Mucho_proceso)) >= umbral){
            Riesgos[31].SetValor(operador.FuzzyAND(No_desarrollo,operador.FuzzyAND(Si_planificacion,Mucho_proceso)));
            Riesgos[31].PreCalculoDivisor(40,60);
            Riesgos[31].PreCalculoDividendo(40,60);
        }

        //Regla 33
        if(operador.FuzzyAND(Poco_desarrollo,operador.FuzzyAND(No_planificacion,Poco_proceso)) >= umbral){
            Riesgos[32].SetValor(operador.FuzzyAND(Poco_desarrollo,operador.FuzzyAND(No_planificacion,Poco_proceso)));
            Riesgos[32].PreCalculoDivisor(90,100);
            Riesgos[32].PreCalculoDividendo(90,100);
        }

        //Regla 34
        if(operador.FuzzyAND(Poco_desarrollo,operador.FuzzyAND(No_planificacion,Algo_proceso)) >= umbral){
            Riesgos[33].SetValor(operador.FuzzyAND(Poco_desarrollo,operador.FuzzyAND(No_planificacion,Algo_proceso)));
            Riesgos[33].PreCalculoDivisor(90,100);
            Riesgos[33].PreCalculoDividendo(90,100);
        }

        //Regla 35
        if(operador.FuzzyAND(Poco_desarrollo,operador.FuzzyAND(No_planificacion,Mucho_proceso)) >= umbral){
            Riesgos[34].SetValor(operador.FuzzyAND(Poco_desarrollo,operador.FuzzyAND(No_planificacion,Mucho_proceso)));
            Riesgos[34].PreCalculoDivisor(90,100);
            Riesgos[34].PreCalculoDividendo(90,100);
        }

        //Regla 36
        if(operador.FuzzyAND(Poco_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Poco_proceso)) >= umbral){
            Riesgos[35].SetValor(operador.FuzzyAND(Poco_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Poco_proceso)));
            Riesgos[35].PreCalculoDivisor(70,80);
            Riesgos[35].PreCalculoDividendo(70,80);
        }

        //Regla 37
        if(operador.FuzzyAND(Poco_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Algo_proceso)) >= umbral){
            Riesgos[36].SetValor(operador.FuzzyAND(Poco_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Algo_proceso)));
            Riesgos[36].PreCalculoDivisor(70,80);
            Riesgos[36].PreCalculoDividendo(70,80);
        }

        //Regla 38
        if(operador.FuzzyAND(Poco_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Mucho_proceso)) >= umbral){
            Riesgos[37].SetValor(operador.FuzzyAND(Poco_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Mucho_proceso)));
            Riesgos[37].PreCalculoDivisor(70,80);
            Riesgos[37].PreCalculoDividendo(70,80);
        }

        //Regla 39
        if(operador.FuzzyAND(Poco_desarrollo,operador.FuzzyAND(Si_planificacion,Poco_proceso)) >= umbral){
            Riesgos[38].SetValor(operador.FuzzyAND(Poco_desarrollo,operador.FuzzyAND(Si_planificacion,Poco_proceso)));
            Riesgos[38].PreCalculoDivisor(70,80);
            Riesgos[38].PreCalculoDividendo(70,80);
        }

        //Regla 40
        if(operador.FuzzyAND(Poco_desarrollo,operador.FuzzyAND(Si_planificacion,Algo_proceso)) >= umbral){
            Riesgos[39].SetValor(operador.FuzzyAND(Poco_desarrollo,operador.FuzzyAND(Si_planificacion,Algo_proceso)));
            Riesgos[39].PreCalculoDivisor(40,60);
            Riesgos[39].PreCalculoDividendo(40,60);
        }

        //Regla 41
        if(operador.FuzzyAND(Poco_desarrollo,operador.FuzzyAND(Si_planificacion,Mucho_proceso)) >= umbral){
            Riesgos[40].SetValor(operador.FuzzyAND(Poco_desarrollo,operador.FuzzyAND(Si_planificacion,Mucho_proceso)));
            Riesgos[40].PreCalculoDivisor(40,60);
            Riesgos[40].PreCalculoDividendo(40,60);
        }

        //Regla 42
        if(operador.FuzzyAND(Algo_desarrollo,operador.FuzzyAND(No_planificacion,Poco_proceso)) >= umbral){
            Riesgos[41].SetValor(operador.FuzzyAND(Algo_desarrollo,operador.FuzzyAND(No_planificacion,Poco_proceso)));
            Riesgos[41].PreCalculoDivisor(40,60);
            Riesgos[41].PreCalculoDividendo(40,60);
        }

        //Regla 43
        if(operador.FuzzyAND(Algo_desarrollo,operador.FuzzyAND(No_planificacion,Algo_proceso)) >= umbral){
            Riesgos[42].SetValor(operador.FuzzyAND(Algo_desarrollo,operador.FuzzyAND(No_planificacion,Algo_proceso)));
            Riesgos[42].PreCalculoDivisor(40,60);
            Riesgos[42].PreCalculoDividendo(40,60);
        }

        //Regla 44
        if(operador.FuzzyAND(Algo_desarrollo,operador.FuzzyAND(No_planificacion,Mucho_proceso)) >= umbral){
            Riesgos[43].SetValor(operador.FuzzyAND(Algo_desarrollo,operador.FuzzyAND(No_planificacion,Mucho_proceso)));
            Riesgos[43].PreCalculoDivisor(40,60);
            Riesgos[43].PreCalculoDividendo(40,60);
        }

        //Regla 45
        if(operador.FuzzyAND(Algo_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Poco_proceso)) >= umbral){
            Riesgos[44].SetValor(operador.FuzzyAND(Algo_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Poco_proceso)));
            Riesgos[44].PreCalculoDivisor(40,60);
            Riesgos[44].PreCalculoDividendo(40,60);
        }

        //Regla 46
        if(operador.FuzzyAND(Algo_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Algo_proceso)) >= umbral){
            Riesgos[45].SetValor(operador.FuzzyAND(Algo_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Algo_proceso)));
            Riesgos[45].PreCalculoDivisor(40,60);
            Riesgos[45].PreCalculoDividendo(40,60);
        }

        //Regla 47
        if(operador.FuzzyAND(Algo_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Mucho_proceso)) >= umbral){
            Riesgos[46].SetValor(operador.FuzzyAND(Algo_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Mucho_proceso)));
            Riesgos[46].PreCalculoDivisor(20,30);
            Riesgos[46].PreCalculoDividendo(20,30);
        }

        //Regla 48
        if(operador.FuzzyAND(Algo_desarrollo,operador.FuzzyAND(Si_planificacion,Poco_proceso)) >= umbral){
            Riesgos[47].SetValor(operador.FuzzyAND(Algo_desarrollo,operador.FuzzyAND(Si_planificacion,Poco_proceso)));
            Riesgos[47].PreCalculoDivisor(20,30);
            Riesgos[47].PreCalculoDividendo(20,30);
        }

        //Regla 49
        if(operador.FuzzyAND(Algo_desarrollo,operador.FuzzyAND(Si_planificacion,Algo_proceso)) >= umbral){
            Riesgos[48].SetValor(operador.FuzzyAND(Algo_desarrollo,operador.FuzzyAND(Si_planificacion,Algo_proceso)));
            Riesgos[48].PreCalculoDivisor(20,30);
            Riesgos[48].PreCalculoDividendo(20,30);
        }

        //Regla 50
        if(operador.FuzzyAND(Algo_desarrollo,operador.FuzzyAND(Si_planificacion,Mucho_proceso)) >= umbral){
            Riesgos[49].SetValor(operador.FuzzyAND(Algo_desarrollo,operador.FuzzyAND(Si_planificacion,Mucho_proceso)));
            Riesgos[49].PreCalculoDivisor(20,30);
            Riesgos[49].PreCalculoDividendo(20,30);
        }

        //Regla 51
        if(operador.FuzzyAND(Si_desarrollo,operador.FuzzyAND(No_planificacion,Poco_proceso)) >= umbral){
            Riesgos[50].SetValor(operador.FuzzyAND(Si_desarrollo,operador.FuzzyAND(No_planificacion,Poco_proceso)));
            Riesgos[50].PreCalculoDivisor(20,30);
            Riesgos[50].PreCalculoDividendo(20,30);
        }

        //Regla 52
        if(operador.FuzzyAND(Si_desarrollo,operador.FuzzyAND(No_planificacion,Algo_proceso)) >= umbral){
            Riesgos[51].SetValor(operador.FuzzyAND(Si_desarrollo,operador.FuzzyAND(No_planificacion,Algo_proceso)));
            Riesgos[51].PreCalculoDivisor(20,30);
            Riesgos[51].PreCalculoDividendo(20,30);
        }

        //Regla 53
        if(operador.FuzzyAND(Si_desarrollo,operador.FuzzyAND(No_planificacion,Mucho_proceso)) >= umbral){
            Riesgos[52].SetValor(operador.FuzzyAND(Si_desarrollo,operador.FuzzyAND(No_planificacion,Mucho_proceso)));
            Riesgos[52].PreCalculoDivisor(20,30);
            Riesgos[52].PreCalculoDividendo(20,30);
        }

        //Regla 54
        if(operador.FuzzyAND(Si_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Poco_proceso)) >= umbral){
            Riesgos[53].SetValor(operador.FuzzyAND(Si_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Poco_proceso)));
            Riesgos[53].PreCalculoDivisor(0,10);
            Riesgos[53].PreCalculoDividendo(0,10);
        }

        //Regla 55
        if(operador.FuzzyAND(Si_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Algo_proceso)) >= umbral){
            Riesgos[54].SetValor(operador.FuzzyAND(Si_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Algo_proceso)));
            Riesgos[54].PreCalculoDivisor(0,10);
            Riesgos[54].PreCalculoDividendo(0,10);
        }

        //Regla 56
        if(operador.FuzzyAND(Si_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Mucho_proceso)) >= umbral){
            Riesgos[55].SetValor(operador.FuzzyAND(Si_desarrollo,operador.FuzzyAND(MasMenos_planificacion,Mucho_proceso)));
            Riesgos[55].PreCalculoDivisor(0,10);
            Riesgos[55].PreCalculoDividendo(0,10);
        }

        //Regla 57
        if(operador.FuzzyAND(Si_desarrollo,operador.FuzzyAND(Si_planificacion,Poco_proceso)) >= umbral){
            Riesgos[56].SetValor(operador.FuzzyAND(Si_desarrollo,operador.FuzzyAND(Si_planificacion,Poco_proceso)));
            Riesgos[56].PreCalculoDivisor(0,10);
            Riesgos[56].PreCalculoDividendo(0,10);
        }

        //Regla 58
        if(operador.FuzzyAND(Si_desarrollo,operador.FuzzyAND(Si_planificacion,Algo_proceso)) >= umbral){
            Riesgos[57].SetValor(operador.FuzzyAND(Si_desarrollo,operador.FuzzyAND(Si_planificacion,Algo_proceso)));
            Riesgos[57].PreCalculoDivisor(0,10);
            Riesgos[57].PreCalculoDividendo(0,10);
        }

        //Regla 59
        if(operador.FuzzyAND(Si_desarrollo,operador.FuzzyAND(Si_planificacion,Mucho_proceso)) >= umbral){
            Riesgos[58].SetValor(operador.FuzzyAND(Si_desarrollo,operador.FuzzyAND(Si_planificacion,Mucho_proceso)));
            Riesgos[58].PreCalculoDivisor(0,10);
            Riesgos[58].PreCalculoDividendo(0,10);
        }

        //Regla 60 ******** RIESGOS *************
        if(operador.FuzzyAND(Poco_analisis,Poco_tec) >= umbral){
            Riesgos[59].SetValor(operador.FuzzyAND(Poco_analisis,Poco_tec));
            Riesgos[59].PreCalculoDivisor(90,100);
            Riesgos[59].PreCalculoDividendo(90,100);
        }

        //Regla 61
        if(operador.FuzzyAND(Poco_analisis,Algo_tec) >= umbral){
            Riesgos[60].SetValor(operador.FuzzyAND(Poco_analisis,Algo_tec));
            Riesgos[60].PreCalculoDivisor(90,100);
            Riesgos[60].PreCalculoDividendo(90,100);
        }

        //Regla 62
        if(operador.FuzzyAND(Poco_analisis,Mucho_tec) >= umbral){
            Riesgos[61].SetValor(operador.FuzzyAND(Poco_analisis,Mucho_tec));
            Riesgos[61].PreCalculoDivisor(70,80);
            Riesgos[61].PreCalculoDividendo(70,80);
        }

        //Regla 63
        if(operador.FuzzyAND(Algo_analisis,Poco_tec) >= umbral){
            Riesgos[62].SetValor(operador.FuzzyAND(Algo_analisis,Poco_tec));
            Riesgos[62].PreCalculoDivisor(90,100);
            Riesgos[62].PreCalculoDividendo(90,100);
        }

        //Regla 64
        if(operador.FuzzyAND(Algo_analisis,Algo_tec) >= umbral){
            Riesgos[63].SetValor(operador.FuzzyAND(Algo_analisis,Algo_tec));
            Riesgos[63].PreCalculoDivisor(40,60);
            Riesgos[63].PreCalculoDividendo(40,60);
        }

        //Regla 65
        if(operador.FuzzyAND(Algo_analisis,Mucho_tec) >= umbral){
            Riesgos[64].SetValor(operador.FuzzyAND(Algo_analisis,Mucho_tec));
            Riesgos[64].PreCalculoDivisor(40,60);
            Riesgos[64].PreCalculoDividendo(40,60);
        }

        //Regla 66
        if(operador.FuzzyAND(Mucho_analisis,Poco_tec) >= umbral){
            Riesgos[65].SetValor(operador.FuzzyAND(Mucho_analisis,Poco_tec));
            Riesgos[65].PreCalculoDivisor(70,80);
            Riesgos[65].PreCalculoDividendo(70,80);
        }

        //Regla 67
        if(operador.FuzzyAND(Mucho_analisis,Algo_tec) >= umbral){
            Riesgos[66].SetValor(operador.FuzzyAND(Mucho_analisis,Algo_tec));
            Riesgos[66].PreCalculoDivisor(20,30);
            Riesgos[66].PreCalculoDividendo(20,30);
        }

        //Regla 68
        if(operador.FuzzyAND(Mucho_analisis,Mucho_tec) >= umbral){
            Riesgos[67].SetValor(operador.FuzzyAND(Mucho_analisis,Mucho_tec));
            Riesgos[67].PreCalculoDivisor(0,10);
            Riesgos[67].PreCalculoDividendo(0,10);
        }

        //Regla 69
        if(operador.FuzzyAND(Poco_analisis,No_calificado) >= umbral){
            Riesgos[68].SetValor(operador.FuzzyAND(Poco_analisis,No_calificado));
            Riesgos[68].PreCalculoDivisor(90,100);
            Riesgos[68].PreCalculoDividendo(90,100);
        }

        //Regla 70
        if(operador.FuzzyAND(Poco_analisis,Talvez_calificado) >= umbral){
            Riesgos[69].SetValor(operador.FuzzyAND(Poco_analisis,Talvez_calificado));
            Riesgos[69].PreCalculoDivisor(70,80);
            Riesgos[69].PreCalculoDividendo(70,80);
        }

        //Regla 71
        if(operador.FuzzyAND(Poco_analisis,Si_calificado) >= umbral){
            Riesgos[70].SetValor(operador.FuzzyAND(Poco_analisis,Si_calificado));
            Riesgos[70].PreCalculoDivisor(70,80);
            Riesgos[70].PreCalculoDividendo(70,80);
        }

        //Regla 72
        if(operador.FuzzyAND(Algo_analisis,No_calificado) >= umbral){
            Riesgos[71].SetValor(operador.FuzzyAND(Algo_analisis,No_calificado));
            Riesgos[71].PreCalculoDivisor(70,80);
            Riesgos[71].PreCalculoDividendo(70,80);
        }

        //Regla 73
        if(operador.FuzzyAND(Algo_analisis,Talvez_calificado) >= umbral){
            Riesgos[72].SetValor(operador.FuzzyAND(Algo_analisis,Talvez_calificado));
            Riesgos[72].PreCalculoDivisor(40,60);
            Riesgos[72].PreCalculoDividendo(40,60);
        }

        //Regla 74
        if(operador.FuzzyAND(Algo_analisis,Si_calificado) >= umbral){
            Riesgos[73].SetValor(operador.FuzzyAND(Algo_analisis,Si_calificado));
            Riesgos[73].PreCalculoDivisor(20,30);
            Riesgos[73].PreCalculoDividendo(20,30);
        }

        //Regla 75
        if(operador.FuzzyAND(Mucho_analisis,No_calificado) >= umbral){
            Riesgos[74].SetValor(operador.FuzzyAND(Mucho_analisis,No_calificado));
            Riesgos[74].PreCalculoDivisor(70,80);
            Riesgos[74].PreCalculoDividendo(70,80);
        }

        //Regla 76
        if(operador.FuzzyAND(Mucho_analisis,Talvez_calificado) >= umbral){
            Riesgos[75].SetValor(operador.FuzzyAND(Mucho_analisis,Talvez_calificado));
            Riesgos[75].PreCalculoDivisor(20,30);
            Riesgos[75].PreCalculoDividendo(20,30);
        }

        //Regla 77
        if(operador.FuzzyAND(Mucho_analisis,Si_calificado) >= umbral){
            Riesgos[76].SetValor(operador.FuzzyAND(Mucho_analisis,Si_calificado));
            Riesgos[76].PreCalculoDivisor(0,10);
            Riesgos[76].PreCalculoDividendo(0,10);
        }

        //Regla 78
        if(operador.FuzzyAND(Poco_analisis,Poco_cumplido) >= umbral){
            Riesgos[77].SetValor(operador.FuzzyAND(Poco_analisis,Poco_cumplido));
            Riesgos[77].PreCalculoDivisor(90,100);
            Riesgos[77].PreCalculoDividendo(90,100);
        }

        //Regla 79
        if(operador.FuzzyAND(Poco_analisis,Algo_cumplido) >= umbral){
            Riesgos[78].SetValor(operador.FuzzyAND(Poco_analisis,Algo_cumplido));
            Riesgos[78].PreCalculoDivisor(90,100);
            Riesgos[78].PreCalculoDividendo(90,100);
        }

        //Regla 80
        if(operador.FuzzyAND(Poco_analisis,Mucho_cumplido) >= umbral){
            Riesgos[79].SetValor(operador.FuzzyAND(Poco_analisis,Mucho_cumplido));
            Riesgos[79].PreCalculoDivisor(70,80);
            Riesgos[79].PreCalculoDividendo(70,80);
        }

        //Regla 81
        if(operador.FuzzyAND(Algo_analisis,Poco_cumplido) >= umbral){
            Riesgos[80].SetValor(operador.FuzzyAND(Algo_analisis,Poco_cumplido));
            Riesgos[80].PreCalculoDivisor(70,80);
            Riesgos[80].PreCalculoDividendo(70,80);
        }

        //Regla 82
        if(operador.FuzzyAND(Algo_analisis,Algo_cumplido) >= umbral){
            Riesgos[81].SetValor(operador.FuzzyAND(Algo_analisis,Algo_cumplido));
            Riesgos[81].PreCalculoDivisor(40,60);
            Riesgos[81].PreCalculoDividendo(40,60);
        }

        //Regla 83
        if(operador.FuzzyAND(Algo_analisis,Mucho_cumplido) >= umbral){
            Riesgos[82].SetValor(operador.FuzzyAND(Algo_analisis,Mucho_cumplido));
            Riesgos[82].PreCalculoDivisor(40,60);
            Riesgos[82].PreCalculoDividendo(40,60);
        }

        //Regla 84
        if(operador.FuzzyAND(Mucho_analisis,Poco_cumplido) >= umbral){
            Riesgos[83].SetValor(operador.FuzzyAND(Mucho_analisis,Poco_cumplido));
            Riesgos[83].PreCalculoDivisor(70,80);
            Riesgos[83].PreCalculoDividendo(70,80);
        }

        //Regla 85
        if(operador.FuzzyAND(Mucho_analisis,Algo_cumplido) >= umbral){
            Riesgos[84].SetValor(operador.FuzzyAND(Mucho_analisis,Algo_cumplido));
            Riesgos[84].PreCalculoDivisor(20,30);
            Riesgos[84].PreCalculoDividendo(20,30);
        }

        //Regla 86
        if(operador.FuzzyAND(Mucho_analisis,Mucho_cumplido) >= umbral){
            Riesgos[85].SetValor(operador.FuzzyAND(Mucho_analisis,Mucho_cumplido));
            Riesgos[85].PreCalculoDivisor(0,10);
            Riesgos[85].PreCalculoDividendo(0,10);
        }

        //Regla 87
        if(operador.FuzzyAND(Poco_analisis,Poco_util) >= umbral){
            Riesgos[86].SetValor(operador.FuzzyAND(Poco_analisis,Poco_util));
            Riesgos[86].PreCalculoDivisor(90,100);
            Riesgos[86].PreCalculoDividendo(90,100);
        }

        //Regla 88
        if(operador.FuzzyAND(Poco_analisis,Algo_util) >= umbral){
            Riesgos[87].SetValor(operador.FuzzyAND(Poco_analisis,Algo_util));
            Riesgos[87].PreCalculoDivisor(90,100);
            Riesgos[87].PreCalculoDividendo(90,100);
        }

        //Regla 89
        if(operador.FuzzyAND(Poco_analisis,Mucho_util) >= umbral){
            Riesgos[88].SetValor(operador.FuzzyAND(Poco_analisis,Mucho_util));
            Riesgos[88].PreCalculoDivisor(70,80);
            Riesgos[88].PreCalculoDividendo(70,80);
        }

        //Regla 90
        if(operador.FuzzyAND(Algo_analisis,Poco_util) >= umbral){
            Riesgos[89].SetValor(operador.FuzzyAND(Algo_analisis,Poco_util));
            Riesgos[89].PreCalculoDivisor(70,80);
            Riesgos[89].PreCalculoDividendo(70,80);
        }

        //Regla 91
        if(operador.FuzzyAND(Algo_analisis,Algo_util) >= umbral){
            Riesgos[90].SetValor(operador.FuzzyAND(Algo_analisis,Algo_util));
            Riesgos[90].PreCalculoDivisor(40,60);
            Riesgos[90].PreCalculoDividendo(40,60);
        }

        //Regla 92
        if(operador.FuzzyAND(Algo_analisis,Mucho_util) >= umbral){
            Riesgos[91].SetValor(operador.FuzzyAND(Algo_analisis,Mucho_util));
            Riesgos[91].PreCalculoDivisor(40,60);
            Riesgos[91].PreCalculoDividendo(40,60);
        }

        //Regla 93
        if(operador.FuzzyAND(Mucho_analisis,Poco_util) >= umbral){
            Riesgos[92].SetValor(operador.FuzzyAND(Mucho_analisis,Poco_util));
            Riesgos[92].PreCalculoDivisor(70,80);
            Riesgos[92].PreCalculoDividendo(70,80);
        }

        //Regla 94
        if(operador.FuzzyAND(Mucho_analisis,Algo_util) >= umbral){
            Riesgos[93].SetValor(operador.FuzzyAND(Mucho_analisis,Algo_util));
            Riesgos[93].PreCalculoDivisor(20,30);
            Riesgos[93].PreCalculoDividendo(20,30);
        }

        //Regla 95
        if(operador.FuzzyAND(Mucho_analisis,Mucho_util) >= umbral){
            Riesgos[94].SetValor(operador.FuzzyAND(Mucho_analisis,Mucho_util));
            Riesgos[94].PreCalculoDivisor(0,10);
            Riesgos[94].PreCalculoDividendo(0,10);
        }

        //Regla 96
        if(operador.FuzzyAND(Poco_analisis,Poco_impacto) >= umbral){
            Riesgos[95].SetValor(operador.FuzzyAND(Poco_analisis,Poco_impacto));
            Riesgos[95].PreCalculoDivisor(90,100);
            Riesgos[95].PreCalculoDividendo(90,100);
        }

        //Regla 97
        if(operador.FuzzyAND(Poco_analisis,Algo_impacto) >= umbral){
            Riesgos[96].SetValor(operador.FuzzyAND(Poco_analisis,Algo_impacto));
            Riesgos[96].PreCalculoDivisor(90,100);
            Riesgos[96].PreCalculoDividendo(90,100);
        }

        //Regla 98
        if(operador.FuzzyAND(Poco_analisis,Mucho_impacto) >= umbral){
            Riesgos[97].SetValor(operador.FuzzyAND(Poco_analisis,Mucho_impacto));
            Riesgos[97].PreCalculoDivisor(90,100);
            Riesgos[97].PreCalculoDividendo(90,100);
        }

        //Regla 99
        if(operador.FuzzyAND(Algo_analisis,Poco_impacto) >= umbral){
            Riesgos[98].SetValor(operador.FuzzyAND(Algo_analisis,Poco_impacto));
            Riesgos[98].PreCalculoDivisor(70,80);
            Riesgos[98].PreCalculoDividendo(70,80);
        }

        //Regla 100
        if(operador.FuzzyAND(Algo_analisis,Algo_impacto) >= umbral){
            Riesgos[99].SetValor(operador.FuzzyAND(Algo_analisis,Algo_impacto));
            Riesgos[99].PreCalculoDivisor(40,60);
            Riesgos[99].PreCalculoDividendo(40,60);
        }

        //Regla 101
        if(operador.FuzzyAND(Algo_analisis,Mucho_impacto) >= umbral){
            Riesgos[100].SetValor(operador.FuzzyAND(Algo_analisis,Mucho_impacto));
            Riesgos[100].PreCalculoDivisor(40,60);
            Riesgos[100].PreCalculoDividendo(40,60);
        }

        //Regla 102
        if(operador.FuzzyAND(Mucho_analisis,Poco_impacto) >= umbral){
            Riesgos[101].SetValor(operador.FuzzyAND(Mucho_analisis,Poco_impacto));
            Riesgos[101].PreCalculoDivisor(0,10);
            Riesgos[101].PreCalculoDividendo(0,10);
        }

        //Regla 103
        if(operador.FuzzyAND(Mucho_analisis,Algo_impacto) >= umbral){
            Riesgos[102].SetValor(operador.FuzzyAND(Mucho_analisis,Algo_impacto));
            Riesgos[102].PreCalculoDivisor(20,30);
            Riesgos[102].PreCalculoDividendo(20,30);
        }

        //Regla 104
        if(operador.FuzzyAND(Mucho_analisis,Mucho_impacto) >= umbral){
            Riesgos[103].SetValor(operador.FuzzyAND(Mucho_analisis,Mucho_impacto));
            Riesgos[103].PreCalculoDivisor(20,30);
            Riesgos[103].PreCalculoDividendo(20,30);
        }

        //Regla 105
        if(operador.FuzzyAND(Poco_analisis,Poco_subestimado) >= umbral){
            Riesgos[104].SetValor(operador.FuzzyAND(Poco_analisis,Poco_subestimado));
            Riesgos[104].PreCalculoDivisor(90,100);
            Riesgos[104].PreCalculoDividendo(90,100);
        }

        //Regla 106
        if(operador.FuzzyAND(Poco_analisis,Algo_subestimado) >= umbral){
            Riesgos[105].SetValor(operador.FuzzyAND(Poco_analisis,Algo_subestimado));
            Riesgos[105].PreCalculoDivisor(90,100);
            Riesgos[105].PreCalculoDividendo(90,100);
        }

        //Regla 107
        if(operador.FuzzyAND(Poco_analisis,Mucho_subestimado) >= umbral){
            Riesgos[106].SetValor(operador.FuzzyAND(Poco_analisis,Mucho_subestimado));
            Riesgos[106].PreCalculoDivisor(90,100);
            Riesgos[106].PreCalculoDividendo(90,100);
        }

        //Regla 108
        if(operador.FuzzyAND(Algo_analisis,Poco_subestimado) >= umbral){
            Riesgos[107].SetValor(operador.FuzzyAND(Algo_analisis,Poco_subestimado));
            Riesgos[107].PreCalculoDivisor(70,80);
            Riesgos[107].PreCalculoDividendo(70,80);
        }

        //Regla 109
        if(operador.FuzzyAND(Algo_analisis,Algo_subestimado) >= umbral){
            Riesgos[108].SetValor(operador.FuzzyAND(Algo_analisis,Algo_subestimado));
            Riesgos[108].PreCalculoDivisor(40,60);
            Riesgos[108].PreCalculoDividendo(40,60);
        }

        //Regla 110
        if(operador.FuzzyAND(Algo_analisis,Mucho_subestimado) >= umbral){
            Riesgos[109].SetValor(operador.FuzzyAND(Algo_analisis,Mucho_subestimado));
            Riesgos[109].PreCalculoDivisor(40,60);
            Riesgos[109].PreCalculoDividendo(40,60);
        }

        //Regla 111
        if(operador.FuzzyAND(Mucho_analisis,Poco_subestimado) >= umbral){
            Riesgos[110].SetValor(operador.FuzzyAND(Mucho_analisis,Poco_subestimado));
            Riesgos[110].PreCalculoDivisor(0,10);
            Riesgos[110].PreCalculoDividendo(0,10);
        }

        //Regla 112
        if(operador.FuzzyAND(Mucho_analisis,Algo_subestimado) >= umbral){
            Riesgos[111].SetValor(operador.FuzzyAND(Mucho_analisis,Algo_subestimado));
            Riesgos[111].PreCalculoDivisor(20,30);
            Riesgos[111].PreCalculoDividendo(20,30);
        }

        //Regla 113
        if(operador.FuzzyAND(Mucho_analisis,Mucho_subestimado) >= umbral){
            Riesgos[112].SetValor(operador.FuzzyAND(Mucho_analisis,Mucho_subestimado));
            Riesgos[112].PreCalculoDivisor(40,60);
            Riesgos[112].PreCalculoDividendo(40,60);
        }*/


        //DESFUSIFICACION
        int i;
        double divisor,dividendo;

        if(categoria == "Documentacion"){
            qDebug() << "Documentacion";
            for(i = 0; i < 23 ; i++){
                divisor += Riesgos[i].GetResultado();
                dividendo += Riesgos[i].GetValor();
                qDebug() << i <<" "<< divisor << " " << dividendo;
            }
        }else if(categoria == "Desarrollo"){
            qDebug() << "Desarrollo";
            for(i = 23; i < 59 ; i++){
                divisor += Riesgos[i].GetResultado();
                dividendo += Riesgos[i].GetValor();
                qDebug() << i <<" "<< divisor << " " << dividendo;
            }
        }else if(categoria == "Riesgos"){
            qDebug() << "Riesgos";
            for(i = 59; i < 113 ; i++){
                divisor += Riesgos[i].GetResultado();
                dividendo += Riesgos[i].GetValor();
                qDebug() << i <<" "<< divisor << " " << dividendo;
            }
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
