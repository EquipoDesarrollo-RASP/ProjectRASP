#include "inferenciafuzzy.h"

InferenciaFuzzy::InferenciaFuzzy()
{
    InferenciaFuzzy::InferenciaFuzzy(void){
        var1 = 0;
        var2 = 0;
        var3 = 0;
    }

    InferenciaFuzzy::InferenciaFuzzy(double PrimerValor, double SegundoValor, double TercerValor){
        var1 = PrimerValor;
        var2 = SegundoValor;
        var3 = TercerValor;
    }

    InferenciaFuzzy::InferenciaMamdani(){
            //Declaración de variables linguisticas
            Retraso.SetValor(var1);
            Documentacion.SetValor(var2);
            Importancia.SetValor(var3);

            // Declaracion de valores linguisticos de sus respectivas variables linguisticas
            // Para la Variable RETRASO
            double Poco_retraso = Retraso.FuncionL(10,30);
            double Algo_retraso = Retraso.Triangular(20,40,60);
            double Mucho_retraso = Retraso.Gamma(50,70);

            // Para la variable DOCUMENTACION
            double Nada_documentacion = Documentacion.FuncionL(0,10);
            double Poco_documentacion = Documentacion.Trapezoidal(0,10,20,30);
            double Algo_documentacion = Documentacion.Trapezoidal(20,40,70,90);
            double Completo_documentacion = Documentacion.Gamma(80,100);

            // Para la variable IMPORTANCIA
            double Poco_importancia = Importancia.FuncionL(10,30);
            double Mediana_importancia = Importancia.Triangular(20,40,60);
            double Mucha_importancia = Importancia.Gamma(50,70);

            //REGLAS DIFUSAS

    }
}
