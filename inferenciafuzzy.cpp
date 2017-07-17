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

        //REGLAS DIFUSAS
        FuzzyOperator operador;
        ConjuntoDifuso Riesgos[59];
        double umbral = 0.2;

        //Regla 1
        if(operador.FuzzyAND(Nada_documentacion,operador.FuzzyAND(Mucho_retraso,Muy_importante)) >= umbral){
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

        //DESFUSIFICACION
        int i;
        double divisor,dividendo;

        if(categoria == "Documentacion"){
            for(i = 0; i < 23 ; i++){
                divisor += Riesgos[i].GetResultado();
                dividendo += Riesgos[i].GetValor();
            }
        }else if(categoria == "Desarrollo"){
            for(i = 24; i < 59 ; i++){
                divisor += Riesgos[i].GetResultado();
                dividendo += Riesgos[i].GetValor();
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
