#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inferenciafuzzy.h"
#include "matriz.h"
#include "gestor_matrices.h"
#include <QMessageBox>
#include <string>
#include <sstream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setTabEnabled(0,false);
    ui->tabWidget->setTabEnabled(1,false);
    ui->tabWidget->setTabEnabled(2,false);
    ui->pushButton_CalcularRiesgo->setEnabled(false);

    ui->pushButton_CicloVida->setEnabled(false);
    ui->pushButton_Desarrollo->setEnabled(false);
    ui->pushButton_Disenio->setEnabled(false);
    ui->pushButton_Requerimientos->setEnabled(false);
    ui->pushButton_PlanGeneral->setEnabled(false);
    ui->pushButton_Pruebas->setEnabled(false);
    ui->pushButton_REstimacion->setEnabled(false);
    ui->pushButton_RHerramientas->setEnabled(false);
    ui->pushButton_Riesgos->setEnabled(false);
    ui->pushButton_ROrganizacional->setEnabled(false);
    ui->pushButton_RPersonal->setEnabled(false);
    ui->pushButton_RRequerimiento->setEnabled(false);
    ui->pushButton_RTecnologia->setEnabled(false);
    ui->pushButton_Temporizacion->setEnabled(false);
    ui->pushButton_ArbolDeRiesgos->setEnabled(false);

    int i;
    for(i=0;i<15;i++){
        ResultadosFactores[i] = 0;
    }

    MatrizIncidencia.InicializarMatriz();


    QFont f("MS Shell Dig 2", 14, QFont::Bold);
    ui->label->setFont(f);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ModeloSolucion_clicked()
{
    ui->tabWidget->setTabEnabled(0,true);
    ui->pushButton_ModeloSolucion->setStyleSheet("background-color:yellow;border-style: outset;border-width: 6px;border-color: gray;");
    ui->pushButton_CicloVida->setEnabled(false);
    ui->pushButton_Desarrollo->setEnabled(false);
    ui->pushButton_Disenio->setEnabled(false);
    ui->pushButton_Requerimientos->setEnabled(false);
    ui->pushButton_PlanGeneral->setEnabled(false);
    ui->pushButton_Pruebas->setEnabled(false);
    ui->pushButton_REstimacion->setEnabled(false);
    ui->pushButton_RHerramientas->setEnabled(false);
    ui->pushButton_Riesgos->setEnabled(false);
    ui->pushButton_ROrganizacional->setEnabled(false);
    ui->pushButton_RPersonal->setEnabled(false);
    ui->pushButton_RRequerimiento->setEnabled(false);
    ui->pushButton_RTecnologia->setEnabled(false);
    ui->pushButton_Temporizacion->setEnabled(false);
    ui->pushButton_ArbolDeRiesgos->setEnabled(false);
    ui->horizontalSlider_Incidencia_ModeloSolucion->setSliderPosition(10);
    ui->horizontalSlider_Incidencia_ModeloSolucion->setEnabled(false);

}

void MainWindow::on_pushButton_Requerimientos_clicked()
{
    ui->tabWidget->setTabEnabled(0,true);
    ui->pushButton_Requerimientos->setStyleSheet("background-color:yellow;border-style: outset;border-width: 6px;border-color: gray;");
    ui->pushButton_CicloVida->setEnabled(false);
    ui->pushButton_Desarrollo->setEnabled(false);
    ui->pushButton_Disenio->setEnabled(false);
    ui->pushButton_ModeloSolucion->setEnabled(false);
    ui->pushButton_PlanGeneral->setEnabled(false);
    ui->pushButton_Pruebas->setEnabled(false);
    ui->pushButton_REstimacion->setEnabled(false);
    ui->pushButton_RHerramientas->setEnabled(false);
    ui->pushButton_Riesgos->setEnabled(false);
    ui->pushButton_ROrganizacional->setEnabled(false);
    ui->pushButton_RPersonal->setEnabled(false);
    ui->pushButton_RRequerimiento->setEnabled(false);
    ui->pushButton_RTecnologia->setEnabled(false);
    ui->pushButton_Temporizacion->setEnabled(false);
    ui->pushButton_ArbolDeRiesgos->setEnabled(false);
    ui->horizontalSlider_Incidencia_Requerimientos->setSliderPosition(10);
    ui->horizontalSlider_Incidencia_Requerimientos->setEnabled(false);
}

void MainWindow::on_pushButton_Disenio_clicked()
{
    ui->tabWidget->setTabEnabled(0,true);
    ui->pushButton_Disenio->setStyleSheet("background-color:yellow;border-style: outset;border-width: 6px;border-color: gray;");
    ui->pushButton_CicloVida->setEnabled(false);
    ui->pushButton_Desarrollo->setEnabled(false);
    ui->pushButton_Requerimientos->setEnabled(false);
    ui->pushButton_ModeloSolucion->setEnabled(false);
    ui->pushButton_PlanGeneral->setEnabled(false);
    ui->pushButton_Pruebas->setEnabled(false);
    ui->pushButton_REstimacion->setEnabled(false);
    ui->pushButton_RHerramientas->setEnabled(false);
    ui->pushButton_Riesgos->setEnabled(false);
    ui->pushButton_ROrganizacional->setEnabled(false);
    ui->pushButton_RPersonal->setEnabled(false);
    ui->pushButton_RRequerimiento->setEnabled(false);
    ui->pushButton_RTecnologia->setEnabled(false);
    ui->pushButton_Temporizacion->setEnabled(false);
    ui->pushButton_ArbolDeRiesgos->setEnabled(false);
    ui->horizontalSlider_Incidencia_Disenio->setSliderPosition(10);
    ui->horizontalSlider_Incidencia_Disenio->setEnabled(false);
}


void MainWindow::on_pushButton_Pruebas_clicked()
{
    ui->tabWidget->setTabEnabled(0,true);
    ui->pushButton_Pruebas->setStyleSheet("background-color:yellow;border-style: outset;border-width: 6px;border-color: gray;");
    ui->pushButton_CicloVida->setEnabled(false);
    ui->pushButton_Desarrollo->setEnabled(false);
    ui->pushButton_Requerimientos->setEnabled(false);
    ui->pushButton_ModeloSolucion->setEnabled(false);
    ui->pushButton_PlanGeneral->setEnabled(false);
    ui->pushButton_Disenio->setEnabled(false);
    ui->pushButton_REstimacion->setEnabled(false);
    ui->pushButton_RHerramientas->setEnabled(false);
    ui->pushButton_Riesgos->setEnabled(false);
    ui->pushButton_ROrganizacional->setEnabled(false);
    ui->pushButton_RPersonal->setEnabled(false);
    ui->pushButton_RRequerimiento->setEnabled(false);
    ui->pushButton_RTecnologia->setEnabled(false);
    ui->pushButton_Temporizacion->setEnabled(false);
    ui->pushButton_ArbolDeRiesgos->setEnabled(false);
    ui->horizontalSlider_Incidencia_Pruebas->setSliderPosition(10);
    ui->horizontalSlider_Incidencia_Pruebas->setEnabled(false);
}


void MainWindow::on_pushButton_PlanGeneral_clicked()
{
    ui->tabWidget->setTabEnabled(0,true);
    ui->pushButton_PlanGeneral->setStyleSheet("background-color:yellow;border-style: outset;border-width: 6px;border-color: gray;");
    ui->pushButton_CicloVida->setEnabled(false);
    ui->pushButton_Desarrollo->setEnabled(false);
    ui->pushButton_Requerimientos->setEnabled(false);
    ui->pushButton_ModeloSolucion->setEnabled(false);
    ui->pushButton_Pruebas->setEnabled(false);
    ui->pushButton_Disenio->setEnabled(false);
    ui->pushButton_REstimacion->setEnabled(false);
    ui->pushButton_RHerramientas->setEnabled(false);
    ui->pushButton_Riesgos->setEnabled(false);
    ui->pushButton_ROrganizacional->setEnabled(false);
    ui->pushButton_RPersonal->setEnabled(false);
    ui->pushButton_RRequerimiento->setEnabled(false);
    ui->pushButton_RTecnologia->setEnabled(false);
    ui->pushButton_Temporizacion->setEnabled(false);
    ui->pushButton_ArbolDeRiesgos->setEnabled(false);
    ui->horizontalSlider_Incidencia_PlanGeneral->setSliderPosition(10);
    ui->horizontalSlider_Incidencia_PlanGeneral->setEnabled(false);
}


void MainWindow::on_pushButton_Temporizacion_clicked()
{
    ui->tabWidget->setTabEnabled(0,true);
    ui->pushButton_Temporizacion->setStyleSheet("background-color:yellow;border-style: outset;border-width: 6px;border-color: gray;");
    ui->pushButton_CicloVida->setEnabled(false);
    ui->pushButton_Desarrollo->setEnabled(false);
    ui->pushButton_Requerimientos->setEnabled(false);
    ui->pushButton_ModeloSolucion->setEnabled(false);
    ui->pushButton_Pruebas->setEnabled(false);
    ui->pushButton_Disenio->setEnabled(false);
    ui->pushButton_REstimacion->setEnabled(false);
    ui->pushButton_RHerramientas->setEnabled(false);
    ui->pushButton_Riesgos->setEnabled(false);
    ui->pushButton_ROrganizacional->setEnabled(false);
    ui->pushButton_RPersonal->setEnabled(false);
    ui->pushButton_RRequerimiento->setEnabled(false);
    ui->pushButton_RTecnologia->setEnabled(false);
    ui->pushButton_PlanGeneral->setEnabled(false);
    ui->pushButton_ArbolDeRiesgos->setEnabled(false);
    ui->horizontalSlider_Incidencia_Temporizacion->setSliderPosition(10);
    ui->horizontalSlider_Incidencia_Temporizacion->setEnabled(false);
}


void MainWindow::on_pushButton_CicloVida_clicked()
{
    ui->tabWidget->setTabEnabled(0,true);
    ui->pushButton_CicloVida->setStyleSheet("background-color:yellow;border-style: outset;border-width: 6px;border-color: gray;");
    ui->pushButton_Temporizacion->setEnabled(false);
    ui->pushButton_Desarrollo->setEnabled(false);
    ui->pushButton_Requerimientos->setEnabled(false);
    ui->pushButton_ModeloSolucion->setEnabled(false);
    ui->pushButton_Pruebas->setEnabled(false);
    ui->pushButton_Disenio->setEnabled(false);
    ui->pushButton_REstimacion->setEnabled(false);
    ui->pushButton_RHerramientas->setEnabled(false);
    ui->pushButton_Riesgos->setEnabled(false);
    ui->pushButton_ROrganizacional->setEnabled(false);
    ui->pushButton_RPersonal->setEnabled(false);
    ui->pushButton_RRequerimiento->setEnabled(false);
    ui->pushButton_RTecnologia->setEnabled(false);
    ui->pushButton_PlanGeneral->setEnabled(false);
    ui->pushButton_ArbolDeRiesgos->setEnabled(false);
    ui->horizontalSlider_Incidencia_CicloVida->setSliderPosition(10);
    ui->horizontalSlider_Incidencia_CicloVida->setEnabled(false);
}


void MainWindow::on_pushButton_Riesgos_clicked()
{
    ui->tabWidget->setTabEnabled(0,true);
    ui->pushButton_Riesgos->setStyleSheet("background-color:yellow;border-style: outset;border-width: 6px;border-color: gray;");
    ui->pushButton_Temporizacion->setEnabled(false);
    ui->pushButton_Desarrollo->setEnabled(false);
    ui->pushButton_Requerimientos->setEnabled(false);
    ui->pushButton_ModeloSolucion->setEnabled(false);
    ui->pushButton_Pruebas->setEnabled(false);
    ui->pushButton_Disenio->setEnabled(false);
    ui->pushButton_REstimacion->setEnabled(false);
    ui->pushButton_RHerramientas->setEnabled(false);
    ui->pushButton_CicloVida->setEnabled(false);
    ui->pushButton_ROrganizacional->setEnabled(false);
    ui->pushButton_RPersonal->setEnabled(false);
    ui->pushButton_RRequerimiento->setEnabled(false);
    ui->pushButton_RTecnologia->setEnabled(false);
    ui->pushButton_PlanGeneral->setEnabled(false);
    ui->pushButton_ArbolDeRiesgos->setEnabled(false);
    ui->horizontalSlider_Incidencia_Riesgos->setSliderPosition(10);
    ui->horizontalSlider_Incidencia_Riesgos->setEnabled(false);
}

void MainWindow::on_pushButton_Desarrollo_clicked()
{
    ui->tabWidget->setTabEnabled(0,true);
    ui->pushButton_Desarrollo->setStyleSheet("background-color:yellow;border-style: outset;border-width: 6px;border-color: gray;");
    ui->pushButton_Temporizacion->setEnabled(false);
    ui->pushButton_Riesgos->setEnabled(false);
    ui->pushButton_Requerimientos->setEnabled(false);
    ui->pushButton_ModeloSolucion->setEnabled(false);
    ui->pushButton_Pruebas->setEnabled(false);
    ui->pushButton_Disenio->setEnabled(false);
    ui->pushButton_REstimacion->setEnabled(false);
    ui->pushButton_RHerramientas->setEnabled(false);
    ui->pushButton_CicloVida->setEnabled(false);
    ui->pushButton_ROrganizacional->setEnabled(false);
    ui->pushButton_RPersonal->setEnabled(false);
    ui->pushButton_RRequerimiento->setEnabled(false);
    ui->pushButton_RTecnologia->setEnabled(false);
    ui->pushButton_PlanGeneral->setEnabled(false);
    ui->pushButton_ArbolDeRiesgos->setEnabled(false);
    ui->horizontalSlider_Incidencia_Desarrollo->setSliderPosition(10);
    ui->horizontalSlider_Incidencia_Desarrollo->setEnabled(false);
}

void MainWindow::on_pushButton_REstimacion_clicked()
{
    ui->tabWidget->setTabEnabled(0,true);
    ui->pushButton_REstimacion->setStyleSheet("background-color:yellow;border-style: outset;border-width: 6px;border-color: gray;");
    ui->pushButton_Temporizacion->setEnabled(false);
    ui->pushButton_Riesgos->setEnabled(false);
    ui->pushButton_Requerimientos->setEnabled(false);
    ui->pushButton_ModeloSolucion->setEnabled(false);
    ui->pushButton_Pruebas->setEnabled(false);
    ui->pushButton_Disenio->setEnabled(false);
    ui->pushButton_Desarrollo->setEnabled(false);
    ui->pushButton_RHerramientas->setEnabled(false);
    ui->pushButton_CicloVida->setEnabled(false);
    ui->pushButton_ROrganizacional->setEnabled(false);
    ui->pushButton_RPersonal->setEnabled(false);
    ui->pushButton_RRequerimiento->setEnabled(false);
    ui->pushButton_RTecnologia->setEnabled(false);
    ui->pushButton_PlanGeneral->setEnabled(false);
    ui->pushButton_ArbolDeRiesgos->setEnabled(false);
    ui->horizontalSlider_Incidencia_REstimacion->setSliderPosition(10);
    ui->horizontalSlider_Incidencia_REstimacion->setEnabled(false);
}

void MainWindow::on_pushButton_RHerramientas_clicked()
{
    ui->tabWidget->setTabEnabled(0,true);
    ui->pushButton_RHerramientas->setStyleSheet("background-color:yellow;border-style: outset;border-width: 6px;border-color: gray;");
    ui->pushButton_Temporizacion->setEnabled(false);
    ui->pushButton_Riesgos->setEnabled(false);
    ui->pushButton_Requerimientos->setEnabled(false);
    ui->pushButton_ModeloSolucion->setEnabled(false);
    ui->pushButton_Pruebas->setEnabled(false);
    ui->pushButton_Disenio->setEnabled(false);
    ui->pushButton_Desarrollo->setEnabled(false);
    ui->pushButton_REstimacion->setEnabled(false);
    ui->pushButton_CicloVida->setEnabled(false);
    ui->pushButton_ROrganizacional->setEnabled(false);
    ui->pushButton_RPersonal->setEnabled(false);
    ui->pushButton_RRequerimiento->setEnabled(false);
    ui->pushButton_RTecnologia->setEnabled(false);
    ui->pushButton_PlanGeneral->setEnabled(false);
    ui->pushButton_ArbolDeRiesgos->setEnabled(false);
    ui->horizontalSlider_Incidencia_RHerramientas->setSliderPosition(10);
    ui->horizontalSlider_Incidencia_RHerramientas->setEnabled(false);
}

void MainWindow::on_pushButton_ROrganizacional_clicked()
{
    ui->tabWidget->setTabEnabled(0,true);
    ui->pushButton_ROrganizacional->setStyleSheet("background-color:yellow;border-style: outset;border-width: 6px;border-color: gray;");
    ui->pushButton_Temporizacion->setEnabled(false);
    ui->pushButton_Riesgos->setEnabled(false);
    ui->pushButton_Requerimientos->setEnabled(false);
    ui->pushButton_ModeloSolucion->setEnabled(false);
    ui->pushButton_Pruebas->setEnabled(false);
    ui->pushButton_Disenio->setEnabled(false);
    ui->pushButton_Desarrollo->setEnabled(false);
    ui->pushButton_REstimacion->setEnabled(false);
    ui->pushButton_CicloVida->setEnabled(false);
    ui->pushButton_RHerramientas->setEnabled(false);
    ui->pushButton_RPersonal->setEnabled(false);
    ui->pushButton_RRequerimiento->setEnabled(false);
    ui->pushButton_RTecnologia->setEnabled(false);
    ui->pushButton_PlanGeneral->setEnabled(false);
    ui->pushButton_ArbolDeRiesgos->setEnabled(false);
    ui->horizontalSlider_Incidencia_ROrganizacional->setSliderPosition(10);
    ui->horizontalSlider_Incidencia_ROrganizacional->setEnabled(false);
}

void MainWindow::on_pushButton_RPersonal_clicked()
{
    ui->tabWidget->setTabEnabled(0,true);
    ui->pushButton_RPersonal->setStyleSheet("background-color:yellow;border-style: outset;border-width: 6px;border-color: gray;");
    ui->pushButton_Temporizacion->setEnabled(false);
    ui->pushButton_Riesgos->setEnabled(false);
    ui->pushButton_Requerimientos->setEnabled(false);
    ui->pushButton_ModeloSolucion->setEnabled(false);
    ui->pushButton_Pruebas->setEnabled(false);
    ui->pushButton_Disenio->setEnabled(false);
    ui->pushButton_Desarrollo->setEnabled(false);
    ui->pushButton_REstimacion->setEnabled(false);
    ui->pushButton_CicloVida->setEnabled(false);
    ui->pushButton_RHerramientas->setEnabled(false);
    ui->pushButton_ROrganizacional->setEnabled(false);
    ui->pushButton_RRequerimiento->setEnabled(false);
    ui->pushButton_RTecnologia->setEnabled(false);
    ui->pushButton_PlanGeneral->setEnabled(false);
    ui->pushButton_ArbolDeRiesgos->setEnabled(false);
    ui->horizontalSlider_Incidencia_RPersonal->setSliderPosition(10);
    ui->horizontalSlider_Incidencia_RPersonal->setEnabled(false);
}

void MainWindow::on_pushButton_RRequerimiento_clicked()
{
    ui->tabWidget->setTabEnabled(0,true);
    ui->pushButton_RRequerimiento->setStyleSheet("background-color:yellow;border-style: outset;border-width: 6px;border-color: gray;");
    ui->pushButton_Temporizacion->setEnabled(false);
    ui->pushButton_Riesgos->setEnabled(false);
    ui->pushButton_Requerimientos->setEnabled(false);
    ui->pushButton_ModeloSolucion->setEnabled(false);
    ui->pushButton_Pruebas->setEnabled(false);
    ui->pushButton_Disenio->setEnabled(false);
    ui->pushButton_Desarrollo->setEnabled(false);
    ui->pushButton_REstimacion->setEnabled(false);
    ui->pushButton_CicloVida->setEnabled(false);
    ui->pushButton_RHerramientas->setEnabled(false);
    ui->pushButton_ROrganizacional->setEnabled(false);
    ui->pushButton_RPersonal->setEnabled(false);
    ui->pushButton_RTecnologia->setEnabled(false);
    ui->pushButton_PlanGeneral->setEnabled(false);
    ui->pushButton_ArbolDeRiesgos->setEnabled(false);
    ui->horizontalSlider_Incidencia_RRequerimientos->setSliderPosition(10);
    ui->horizontalSlider_Incidencia_RRequerimientos->setEnabled(false);
}

void MainWindow::on_pushButton_RTecnologia_clicked()
{
    ui->tabWidget->setTabEnabled(0,true);
    ui->pushButton_RTecnologia->setStyleSheet("background-color:yellow;border-style: outset;border-width: 6px;border-color: gray;");
    ui->pushButton_Temporizacion->setEnabled(false);
    ui->pushButton_Riesgos->setEnabled(false);
    ui->pushButton_Requerimientos->setEnabled(false);
    ui->pushButton_ModeloSolucion->setEnabled(false);
    ui->pushButton_Pruebas->setEnabled(false);
    ui->pushButton_Disenio->setEnabled(false);
    ui->pushButton_Desarrollo->setEnabled(false);
    ui->pushButton_REstimacion->setEnabled(false);
    ui->pushButton_CicloVida->setEnabled(false);
    ui->pushButton_RHerramientas->setEnabled(false);
    ui->pushButton_ROrganizacional->setEnabled(false);
    ui->pushButton_RRequerimiento->setEnabled(false);
    ui->pushButton_RPersonal->setEnabled(false);
    ui->pushButton_PlanGeneral->setEnabled(false);
    ui->pushButton_ArbolDeRiesgos->setEnabled(false);
    ui->horizontalSlider_Incidencia_RTecnologia->setSliderPosition(10);
    ui->horizontalSlider_Incidencia_RTecnologia->setEnabled(false);
}

/*--------------------------------PROCESO DE CALCULO DE RIESGO--------------------------------------*/
void MainWindow::on_pushButton_CalcularRiesgo_clicked()
{

    int i;
    int cant = 0;
    double ResultadoFinal = 0;
    for(i = 0; i<15 ; i++){
        if(ResultadosFactores[i] > 0){
            qDebug() << ResultadosFactores[i];
            if(ResultadosFactores[i] > 100){
                ResultadosFactores[i] = 100;
            }
            ResultadoFinal = ResultadosFactores[i] + ResultadoFinal;
            cant++;
        }
    }

    ResultadoFinal = ResultadoFinal/cant;
    qDebug() << "Resultado Final es: " << ResultadoFinal;
    QString ResultadoRiesgo;

    if(ResultadoFinal >= 100){
        ResultadoFinal = 100;
        ResultadoRiesgo.setNum(ResultadoFinal);
        ResultadoRiesgo.resize(3);
    }else{
        ResultadoRiesgo.setNum(ResultadoFinal);
        ResultadoRiesgo.resize(5);
    }

    ui->Nivel_Riesgo->setText(ResultadoRiesgo+"%");

    // Se desbloquea los botones factores y se bloquean los demás botones y tabs
    ui->pushButton_CicloVida->setEnabled(true);
    ui->pushButton_Desarrollo->setEnabled(true);
    ui->pushButton_Disenio->setEnabled(true);
    ui->pushButton_ModeloSolucion->setEnabled(true);
    ui->pushButton_PlanGeneral->setEnabled(true);
    ui->pushButton_Pruebas->setEnabled(true);
    ui->pushButton_REstimacion->setEnabled(true);
    ui->pushButton_RHerramientas->setEnabled(true);
    ui->pushButton_Riesgos->setEnabled(true);
    ui->pushButton_ROrganizacional->setEnabled(true);
    ui->pushButton_RPersonal->setEnabled(true);
    ui->pushButton_RRequerimiento->setEnabled(true);
    ui->pushButton_RTecnologia->setEnabled(true);
    ui->pushButton_Temporizacion->setEnabled(true);
    ui->pushButton_ArbolDeRiesgos->setEnabled(true);
    ui->pushButton_Requerimientos->setEnabled(true);
    ui->tabWidget->setTabEnabled(0,false);
    ui->tabWidget->setTabEnabled(1,false);
    ui->tabWidget->setTabEnabled(2,false);
    ui->pushButton_CalcularRiesgo->setEnabled(false);

}

/*--------------------------------PROCESO DE CALCULO DE INCIDENCIAS--------------------------------------*/
void MainWindow::on_pushButton_ConfirmarIncidencias_clicked()
{
    //Se determina cual es la fila de la matriz del factor seleccionado
    int filaFactor;

    if(ui->pushButton_ModeloSolucion->isEnabled()){
        filaFactor = 0;
    }else if(ui->pushButton_Requerimientos->isEnabled()){
        filaFactor = 1;
    }else if(ui->pushButton_Disenio->isEnabled()){
        filaFactor = 2;
    }else if(ui->pushButton_Pruebas->isEnabled()){
        filaFactor = 3;
    }else if(ui->pushButton_PlanGeneral->isEnabled()){
        filaFactor = 4;
    }else if(ui->pushButton_Temporizacion->isEnabled()){
        filaFactor = 5;
    }else if(ui->pushButton_CicloVida->isEnabled()){
        filaFactor = 6;
    }else if(ui->pushButton_Riesgos->isEnabled()){
        filaFactor = 7;
    }else if(ui->pushButton_Desarrollo->isEnabled()){
        filaFactor = 8;
    }else if(ui->pushButton_RTecnologia->isEnabled()){
        filaFactor = 9;
    }else if(ui->pushButton_RPersonal->isEnabled()){
        filaFactor = 10;
    }else if(ui->pushButton_ROrganizacional->isEnabled()){
        filaFactor = 11;
    }else if(ui->pushButton_RHerramientas->isEnabled()){
        filaFactor = 12;
    }else if(ui->pushButton_RRequerimiento->isEnabled()){
        filaFactor = 13;
    }else if(ui->pushButton_REstimacion->isEnabled()){
        filaFactor = 14;
    }

    //Se extraen los valores de los sliders para las columnas de la matriz
    float valor[15];

    valor[0] = ui->horizontalSlider_Incidencia_ModeloSolucion->value();
    valor[1] = ui->horizontalSlider_Incidencia_Requerimientos->value();
    valor[2] = ui->horizontalSlider_Incidencia_Disenio->value();
    valor[3] = ui->horizontalSlider_Incidencia_Pruebas->value();
    valor[4] = ui->horizontalSlider_Incidencia_PlanGeneral->value();
    valor[5] = ui->horizontalSlider_Incidencia_Temporizacion->value();
    valor[6] = ui->horizontalSlider_Incidencia_CicloVida->value();
    valor[7] = ui->horizontalSlider_Incidencia_Riesgos->value();
    valor[8] = ui->horizontalSlider_Incidencia_Desarrollo->value();
    valor[9] = ui->horizontalSlider_Incidencia_RTecnologia->value();
    valor[10] = ui->horizontalSlider_Incidencia_RPersonal->value();
    valor[11] = ui->horizontalSlider_Incidencia_ROrganizacional->value();
    valor[12] = ui->horizontalSlider_Incidencia_RHerramientas->value();
    valor[13] = ui->horizontalSlider_Incidencia_RRequerimientos->value();
    valor[14] = ui->horizontalSlider_Incidencia_REstimacion->value();

    //Con este ciclo FOR los deja con los valores entre 0 y 1
    int i;
    for(i=0 ; i < 15; i++){
        valor[i] = valor[i] / 10;
    }

    //Se actualizan los valores de la matriz con los nuevos datos.
    for(int columna = 0; columna < 15 ; columna++){
        MatrizIncidencia.setValor(filaFactor,columna, valor[columna]);
    }

    //Se muestra en un cuadro de dialogo el resultado de la matriz --- CON PROPOSITOS DE PRUEBA
    MatrizR2 = Gestor.siguiente_grado(MatrizIncidencia);
    EfectoOlvidado = Gestor.efectos_olvidados(MatrizIncidencia,MatrizR2);
    string resultadoMatriz = EfectoOlvidado.mostrar();
    QString mensaje = QString::fromStdString(resultadoMatriz);
    QMessageBox::information(this, "Hola", mensaje);

    ui->tabWidget->setTabEnabled(0,false);
    ui->tabWidget->setTabEnabled(1,true);
    ui->tabWidget->setTabEnabled(2,true);
    ui->pushButton_ConfirmarEstimacion->setEnabled(true);
}


/*-----------------------------------CALCULO DE LA ESTIMACION DEL FACTOR-----------------------------------------*/
void MainWindow::on_pushButton_ConfirmarEstimacion_clicked()
{
    // Se cambia de color verde el boton que fue ejecutado
    if(ui->pushButton_CicloVida->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy Calculo(var1,var2,var3,"Documentacion");
            Calculo.InferenciaMamdani();

            ResultadosFactores[0] = Calculo.GetResultadoFinal();

            ui->pushButton_CicloVida->setEnabled(false);
            ui->pushButton_CicloVida->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
            ui->horizontalSlider_Incidencia_CicloVida->setEnabled(true);
            ui->pushButton_ConfirmarEstimacion->setEnabled(false);
        }
    }

    if(ui->pushButton_Desarrollo->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy Calculo(var1,var2,var3,"Desarrollo");
            Calculo.InferenciaMamdani();

            ResultadosFactores[1] = Calculo.GetResultadoFinal();

            ui->pushButton_Desarrollo->setEnabled(false);
            ui->pushButton_Desarrollo->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
            ui->horizontalSlider_Incidencia_Desarrollo->setEnabled(true);
            ui->pushButton_ConfirmarEstimacion->setEnabled(false);
        }
    }

    if(ui->pushButton_Disenio->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy Calculo(var1,var2,var3,"Documentacion");
            Calculo.InferenciaMamdani();

            ResultadosFactores[2] = Calculo.GetResultadoFinal();

            ui->pushButton_Disenio->setEnabled(false);
            ui->pushButton_Disenio->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
            ui->horizontalSlider_Incidencia_Disenio->setEnabled(true);
            ui->pushButton_ConfirmarEstimacion->setEnabled(false);
        }
    }

    if(ui->pushButton_ModeloSolucion->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy Calculo(var1,var2,var3,"Documentacion");
            Calculo.InferenciaMamdani();

            ResultadosFactores[3] = Calculo.GetResultadoFinal();

            ui->pushButton_ModeloSolucion->setEnabled(false);
            ui->pushButton_ModeloSolucion->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
            ui->horizontalSlider_Incidencia_ModeloSolucion->setEnabled(true);
            ui->pushButton_ConfirmarEstimacion->setEnabled(false);
        }
    }

    if(ui->pushButton_PlanGeneral->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy Calculo(var1,var2,var3,"Documentacion");
            Calculo.InferenciaMamdani();

            ResultadosFactores[4] = Calculo.GetResultadoFinal();

            ui->pushButton_PlanGeneral->setEnabled(false);
            ui->pushButton_PlanGeneral->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
            ui->horizontalSlider_Incidencia_PlanGeneral->setEnabled(true);
            ui->pushButton_ConfirmarEstimacion->setEnabled(false);
        }
    }

    if(ui->pushButton_Pruebas->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy Calculo(var1,var2,var3,"Documentacion");
            Calculo.InferenciaMamdani();

            ResultadosFactores[5] = Calculo.GetResultadoFinal();

            ui->pushButton_Pruebas->setEnabled(false);
            ui->pushButton_Pruebas->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
            ui->horizontalSlider_Incidencia_Pruebas->setEnabled(true);
            ui->pushButton_ConfirmarEstimacion->setEnabled(false);
        }
    }

    if(ui->pushButton_Requerimientos->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy Calculo(var1,var2,var3,"Documentacion");
            Calculo.InferenciaMamdani();

            ResultadosFactores[6] = Calculo.GetResultadoFinal();

            ui->pushButton_Requerimientos->setEnabled(false);
            ui->pushButton_Requerimientos->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
            ui->horizontalSlider_Incidencia_Requerimientos->setEnabled(true);
            ui->pushButton_ConfirmarEstimacion->setEnabled(false);
        }
    }

    if(ui->pushButton_REstimacion->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();

            InferenciaFuzzy Calculo(var1,var2,0,"Riesgos");
            Calculo.InferenciaMamdani();

            ResultadosFactores[7] = Calculo.GetResultadoFinal();

            ui->pushButton_REstimacion->setEnabled(false);
            ui->pushButton_REstimacion->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
            ui->horizontalSlider_Incidencia_REstimacion->setEnabled(true);
            ui->pushButton_ConfirmarEstimacion->setEnabled(false);
        }
    }

    if(ui->pushButton_RHerramientas->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();

            InferenciaFuzzy Calculo(var1,var2,0,"Riesgos");
            Calculo.InferenciaMamdani();

            ResultadosFactores[8] = Calculo.GetResultadoFinal();

            ui->pushButton_RHerramientas->setEnabled(false);
            ui->pushButton_RHerramientas->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
            ui->horizontalSlider_Incidencia_RHerramientas->setEnabled(true);
            ui->pushButton_ConfirmarEstimacion->setEnabled(false);
        }
    }

    if(ui->pushButton_Riesgos->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy Calculo(var1,var2,var3,"Documentacion");
            Calculo.InferenciaMamdani();

            ResultadosFactores[9] = Calculo.GetResultadoFinal();

            ui->pushButton_Riesgos->setEnabled(false);
            ui->pushButton_Riesgos->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
            ui->horizontalSlider_Incidencia_Riesgos->setEnabled(true);
            ui->pushButton_ConfirmarEstimacion->setEnabled(false);
        }
    }

    if(ui->pushButton_ROrganizacional->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();

            InferenciaFuzzy Calculo(var1,var2,0,"Riesgos");
            Calculo.InferenciaMamdani();

            ResultadosFactores[10] = Calculo.GetResultadoFinal();

            ui->pushButton_ROrganizacional->setEnabled(false);
            ui->pushButton_ROrganizacional->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
            ui->horizontalSlider_Incidencia_ROrganizacional->setEnabled(true);
            ui->pushButton_ConfirmarEstimacion->setEnabled(false);
        }
    }

    if(ui->pushButton_RPersonal->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();

            InferenciaFuzzy Calculo(var1,var2,0,"Riesgos");
            Calculo.InferenciaMamdani();

            ResultadosFactores[11] = Calculo.GetResultadoFinal();

            ui->pushButton_RPersonal->setEnabled(false);
            ui->pushButton_RPersonal->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
            ui->horizontalSlider_Incidencia_RPersonal->setEnabled(true);
            ui->pushButton_ConfirmarEstimacion->setEnabled(false);
        }
    }

    if(ui->pushButton_RRequerimiento->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();

            InferenciaFuzzy Calculo(var1,var2,0,"Riesgos");
            Calculo.InferenciaMamdani();

            ResultadosFactores[12] = Calculo.GetResultadoFinal();

            ui->pushButton_RRequerimiento->setEnabled(false);
            ui->pushButton_RRequerimiento->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
            ui->horizontalSlider_Incidencia_RRequerimientos->setEnabled(true);
            ui->pushButton_ConfirmarEstimacion->setEnabled(false);
        }
    }

    if(ui->pushButton_RTecnologia->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();

            InferenciaFuzzy Calculo(var1,var2,0,"Riesgos");
            Calculo.InferenciaMamdani();

            ResultadosFactores[13] = Calculo.GetResultadoFinal();

            ui->pushButton_RTecnologia->setEnabled(false);
            ui->pushButton_RTecnologia->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
            ui->horizontalSlider_Incidencia_RTecnologia->setEnabled(true);
            ui->pushButton_ConfirmarEstimacion->setEnabled(false);
        }
    }

    if(ui->pushButton_Temporizacion->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy Calculo(var1,var2,var3,"Documentacion");
            Calculo.InferenciaMamdani();

            ResultadosFactores[14] = Calculo.GetResultadoFinal();

            ui->pushButton_Temporizacion->setEnabled(false);
            ui->pushButton_Temporizacion->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
            ui->horizontalSlider_Incidencia_Temporizacion->setEnabled(true);
            ui->pushButton_ConfirmarEstimacion->setEnabled(false);
        }
    }
}


void MainWindow::on_horizontalSlider_Incidencia_ModeloSolucion_valueChanged(int value)
{
    switch(value){
        case 0:
            ui->label_Incidencia_ModeloSolucion->setText("          Ninguna Incidencia");
            break;
        case 1:
            ui->label_Incidencia_ModeloSolucion->setText("Practicamente sin Incidencia");
            break;
        case 2:
            ui->label_Incidencia_ModeloSolucion->setText("         Casi sin Incidencia");
            break;
        case 3:
            ui->label_Incidencia_ModeloSolucion->setText("        Muy débil Incidencia");
            break;
        case 4:
            ui->label_Incidencia_ModeloSolucion->setText("            Débil Incidencia");
            break;
        case 5:
            ui->label_Incidencia_ModeloSolucion->setText("          Mediana Incidencia");
            break;
        case 6:
            ui->label_Incidencia_ModeloSolucion->setText("         Incidencia Sensible");
            break;
        case 7:
            ui->label_Incidencia_ModeloSolucion->setText("         Bastante Incidencia");
            break;
        case 8:
            ui->label_Incidencia_ModeloSolucion->setText("           Fuerte Incidencia");
            break;
        case 9:
            ui->label_Incidencia_ModeloSolucion->setText("       Muy fuerte Incidencia");
            break;
        case 10:
            ui->label_Incidencia_ModeloSolucion->setText("         La mayor Incidencia");
            break;
    }
}

void MainWindow::on_horizontalSlider_Incidencia_Requerimientos_valueChanged(int value)
{
    switch(value){
        case 0:
            ui->label_Incidencia_Requerimientos->setText("          Ninguna Incidencia");
            break;
        case 1:
            ui->label_Incidencia_Requerimientos->setText("Practicamente sin Incidencia");
            break;
        case 2:
            ui->label_Incidencia_Requerimientos->setText("         Casi sin Incidencia");
            break;
        case 3:
            ui->label_Incidencia_Requerimientos->setText("        Muy débil Incidencia");
            break;
        case 4:
            ui->label_Incidencia_Requerimientos->setText("            Débil Incidencia");
            break;
        case 5:
            ui->label_Incidencia_Requerimientos->setText("          Mediana Incidencia");
            break;
        case 6:
            ui->label_Incidencia_Requerimientos->setText("         Incidencia Sensible");
            break;
        case 7:
            ui->label_Incidencia_Requerimientos->setText("         Bastante Incidencia");
            break;
        case 8:
            ui->label_Incidencia_Requerimientos->setText("           Fuerte Incidencia");
            break;
        case 9:
            ui->label_Incidencia_Requerimientos->setText("       Muy fuerte Incidencia");
            break;
        case 10:
            ui->label_Incidencia_Requerimientos->setText("         La mayor Incidencia");
            break;
    }
}

void MainWindow::on_horizontalSlider_Incidencia_Disenio_valueChanged(int value)
{
    switch(value){
        case 0:
            ui->label_Incidencia_Disenio->setText("          Ninguna Incidencia");
            break;
        case 1:
            ui->label_Incidencia_Disenio->setText("Practicamente sin Incidencia");
            break;
        case 2:
            ui->label_Incidencia_Disenio->setText("         Casi sin Incidencia");
            break;
        case 3:
            ui->label_Incidencia_Disenio->setText("        Muy débil Incidencia");
            break;
        case 4:
            ui->label_Incidencia_Disenio->setText("            Débil Incidencia");
            break;
        case 5:
            ui->label_Incidencia_Disenio->setText("          Mediana Incidencia");
            break;
        case 6:
            ui->label_Incidencia_Disenio->setText("         Incidencia Sensible");
            break;
        case 7:
            ui->label_Incidencia_Disenio->setText("         Bastante Incidencia");
            break;
        case 8:
            ui->label_Incidencia_Disenio->setText("           Fuerte Incidencia");
            break;
        case 9:
            ui->label_Incidencia_Disenio->setText("       Muy fuerte Incidencia");
            break;
        case 10:
            ui->label_Incidencia_Disenio->setText("         La mayor Incidencia");
            break;
    }
}

void MainWindow::on_horizontalSlider_Incidencia_Pruebas_valueChanged(int value)
{
    switch(value){
        case 0:
            ui->label_Incidencia_Pruebas->setText("          Ninguna Incidencia");
            break;
        case 1:
            ui->label_Incidencia_Pruebas->setText("Practicamente sin Incidencia");
            break;
        case 2:
            ui->label_Incidencia_Pruebas->setText("         Casi sin Incidencia");
            break;
        case 3:
            ui->label_Incidencia_Pruebas->setText("        Muy débil Incidencia");
            break;
        case 4:
            ui->label_Incidencia_Pruebas->setText("            Débil Incidencia");
            break;
        case 5:
            ui->label_Incidencia_Pruebas->setText("          Mediana Incidencia");
            break;
        case 6:
            ui->label_Incidencia_Pruebas->setText("         Incidencia Sensible");
            break;
        case 7:
            ui->label_Incidencia_Pruebas->setText("         Bastante Incidencia");
            break;
        case 8:
            ui->label_Incidencia_Pruebas->setText("           Fuerte Incidencia");
            break;
        case 9:
            ui->label_Incidencia_Pruebas->setText("       Muy fuerte Incidencia");
            break;
        case 10:
            ui->label_Incidencia_Pruebas->setText("         La mayor Incidencia");
            break;
    }
}

void MainWindow::on_horizontalSlider_Incidencia_PlanGeneral_valueChanged(int value)
{
    switch(value){
        case 0:
            ui->label_Incidencia_PlanGeneral->setText("          Ninguna Incidencia");
            break;
        case 1:
            ui->label_Incidencia_PlanGeneral->setText("Practicamente sin Incidencia");
            break;
        case 2:
            ui->label_Incidencia_PlanGeneral->setText("         Casi sin Incidencia");
            break;
        case 3:
            ui->label_Incidencia_PlanGeneral->setText("        Muy débil Incidencia");
            break;
        case 4:
            ui->label_Incidencia_PlanGeneral->setText("            Débil Incidencia");
            break;
        case 5:
            ui->label_Incidencia_PlanGeneral->setText("          Mediana Incidencia");
            break;
        case 6:
            ui->label_Incidencia_PlanGeneral->setText("         Incidencia Sensible");
            break;
        case 7:
            ui->label_Incidencia_PlanGeneral->setText("         Bastante Incidencia");
            break;
        case 8:
            ui->label_Incidencia_PlanGeneral->setText("           Fuerte Incidencia");
            break;
        case 9:
            ui->label_Incidencia_PlanGeneral->setText("       Muy fuerte Incidencia");
            break;
        case 10:
            ui->label_Incidencia_PlanGeneral->setText("         La mayor Incidencia");
            break;
    }
}

void MainWindow::on_horizontalSlider_Incidencia_Temporizacion_valueChanged(int value)
{
    switch(value){
        case 0:
            ui->label_Incidencia_Temporizacion->setText("          Ninguna Incidencia");
            break;
        case 1:
            ui->label_Incidencia_Temporizacion->setText("Practicamente sin Incidencia");
            break;
        case 2:
            ui->label_Incidencia_Temporizacion->setText("         Casi sin Incidencia");
            break;
        case 3:
            ui->label_Incidencia_Temporizacion->setText("        Muy débil Incidencia");
            break;
        case 4:
            ui->label_Incidencia_Temporizacion->setText("            Débil Incidencia");
            break;
        case 5:
            ui->label_Incidencia_Temporizacion->setText("          Mediana Incidencia");
            break;
        case 6:
            ui->label_Incidencia_Temporizacion->setText("         Incidencia Sensible");
            break;
        case 7:
            ui->label_Incidencia_Temporizacion->setText("         Bastante Incidencia");
            break;
        case 8:
            ui->label_Incidencia_Temporizacion->setText("           Fuerte Incidencia");
            break;
        case 9:
            ui->label_Incidencia_Temporizacion->setText("       Muy fuerte Incidencia");
            break;
        case 10:
            ui->label_Incidencia_Temporizacion->setText("         La mayor Incidencia");
            break;
    }
}

void MainWindow::on_horizontalSlider_Incidencia_CicloVida_valueChanged(int value)
{
    switch(value){
        case 0:
            ui->label_Incidencia_CicloVida->setText("          Ninguna Incidencia");
            break;
        case 1:
            ui->label_Incidencia_CicloVida->setText("Practicamente sin Incidencia");
            break;
        case 2:
            ui->label_Incidencia_CicloVida->setText("         Casi sin Incidencia");
            break;
        case 3:
            ui->label_Incidencia_CicloVida->setText("        Muy débil Incidencia");
            break;
        case 4:
            ui->label_Incidencia_CicloVida->setText("            Débil Incidencia");
            break;
        case 5:
            ui->label_Incidencia_CicloVida->setText("          Mediana Incidencia");
            break;
        case 6:
            ui->label_Incidencia_CicloVida->setText("         Incidencia Sensible");
            break;
        case 7:
            ui->label_Incidencia_CicloVida->setText("         Bastante Incidencia");
            break;
        case 8:
            ui->label_Incidencia_CicloVida->setText("           Fuerte Incidencia");
            break;
        case 9:
            ui->label_Incidencia_CicloVida->setText("       Muy fuerte Incidencia");
            break;
        case 10:
            ui->label_Incidencia_CicloVida->setText("         La mayor Incidencia");
            break;
    }
}

void MainWindow::on_horizontalSlider_Incidencia_Riesgos_valueChanged(int value)
{
    switch(value){
        case 0:
            ui->label_Incidencia_Riesgos->setText("          Ninguna Incidencia");
            break;
        case 1:
            ui->label_Incidencia_Riesgos->setText("Practicamente sin Incidencia");
            break;
        case 2:
            ui->label_Incidencia_Riesgos->setText("         Casi sin Incidencia");
            break;
        case 3:
            ui->label_Incidencia_Riesgos->setText("        Muy débil Incidencia");
            break;
        case 4:
            ui->label_Incidencia_Riesgos->setText("            Débil Incidencia");
            break;
        case 5:
            ui->label_Incidencia_Riesgos->setText("          Mediana Incidencia");
            break;
        case 6:
            ui->label_Incidencia_Riesgos->setText("         Incidencia Sensible");
            break;
        case 7:
            ui->label_Incidencia_Riesgos->setText("         Bastante Incidencia");
            break;
        case 8:
            ui->label_Incidencia_Riesgos->setText("           Fuerte Incidencia");
            break;
        case 9:
            ui->label_Incidencia_Riesgos->setText("       Muy fuerte Incidencia");
            break;
        case 10:
            ui->label_Incidencia_Riesgos->setText("         La mayor Incidencia");
            break;
    }
}

void MainWindow::on_horizontalSlider_Incidencia_Desarrollo_valueChanged(int value)
{
    switch(value){
        case 0:
            ui->label_Incidencia_Desarrollo->setText("          Ninguna Incidencia");
            break;
        case 1:
            ui->label_Incidencia_Desarrollo->setText("Practicamente sin Incidencia");
            break;
        case 2:
            ui->label_Incidencia_Desarrollo->setText("         Casi sin Incidencia");
            break;
        case 3:
            ui->label_Incidencia_Desarrollo->setText("        Muy débil Incidencia");
            break;
        case 4:
            ui->label_Incidencia_Desarrollo->setText("            Débil Incidencia");
            break;
        case 5:
            ui->label_Incidencia_Desarrollo->setText("          Mediana Incidencia");
            break;
        case 6:
            ui->label_Incidencia_Desarrollo->setText("         Incidencia Sensible");
            break;
        case 7:
            ui->label_Incidencia_Desarrollo->setText("         Bastante Incidencia");
            break;
        case 8:
            ui->label_Incidencia_Desarrollo->setText("           Fuerte Incidencia");
            break;
        case 9:
            ui->label_Incidencia_Desarrollo->setText("       Muy fuerte Incidencia");
            break;
        case 10:
            ui->label_Incidencia_Desarrollo->setText("         La mayor Incidencia");
            break;
    }
}

void MainWindow::on_horizontalSlider_Incidencia_RTecnologia_valueChanged(int value)
{
    switch(value){
        case 0:
            ui->label_Incidencia_RTecnologia->setText("          Ninguna Incidencia");
            break;
        case 1:
            ui->label_Incidencia_RTecnologia->setText("Practicamente sin Incidencia");
            break;
        case 2:
            ui->label_Incidencia_RTecnologia->setText("         Casi sin Incidencia");
            break;
        case 3:
            ui->label_Incidencia_RTecnologia->setText("        Muy débil Incidencia");
            break;
        case 4:
            ui->label_Incidencia_RTecnologia->setText("            Débil Incidencia");
            break;
        case 5:
            ui->label_Incidencia_RTecnologia->setText("          Mediana Incidencia");
            break;
        case 6:
            ui->label_Incidencia_RTecnologia->setText("         Incidencia Sensible");
            break;
        case 7:
            ui->label_Incidencia_RTecnologia->setText("         Bastante Incidencia");
            break;
        case 8:
            ui->label_Incidencia_RTecnologia->setText("           Fuerte Incidencia");
            break;
        case 9:
            ui->label_Incidencia_RTecnologia->setText("       Muy fuerte Incidencia");
            break;
        case 10:
            ui->label_Incidencia_RTecnologia->setText("         La mayor Incidencia");
            break;
    }
}

void MainWindow::on_horizontalSlider_Incidencia_RPersonal_valueChanged(int value)
{
    switch(value){
        case 0:
            ui->label_Incidencia_RPersonal->setText("          Ninguna Incidencia");
            break;
        case 1:
            ui->label_Incidencia_RPersonal->setText("Practicamente sin Incidencia");
            break;
        case 2:
            ui->label_Incidencia_RPersonal->setText("         Casi sin Incidencia");
            break;
        case 3:
            ui->label_Incidencia_RPersonal->setText("        Muy débil Incidencia");
            break;
        case 4:
            ui->label_Incidencia_RPersonal->setText("            Débil Incidencia");
            break;
        case 5:
            ui->label_Incidencia_RPersonal->setText("          Mediana Incidencia");
            break;
        case 6:
            ui->label_Incidencia_RPersonal->setText("         Incidencia Sensible");
            break;
        case 7:
            ui->label_Incidencia_RPersonal->setText("         Bastante Incidencia");
            break;
        case 8:
            ui->label_Incidencia_RPersonal->setText("           Fuerte Incidencia");
            break;
        case 9:
            ui->label_Incidencia_RPersonal->setText("       Muy fuerte Incidencia");
            break;
        case 10:
            ui->label_Incidencia_RPersonal->setText("         La mayor Incidencia");
            break;
    }
}

void MainWindow::on_horizontalSlider_Incidencia_ROrganizacional_valueChanged(int value)
{
    switch(value){
        case 0:
            ui->label_Incidencia_ROrganizacional->setText("          Ninguna Incidencia");
            break;
        case 1:
            ui->label_Incidencia_ROrganizacional->setText("Practicamente sin Incidencia");
            break;
        case 2:
            ui->label_Incidencia_ROrganizacional->setText("         Casi sin Incidencia");
            break;
        case 3:
            ui->label_Incidencia_ROrganizacional->setText("        Muy débil Incidencia");
            break;
        case 4:
            ui->label_Incidencia_ROrganizacional->setText("            Débil Incidencia");
            break;
        case 5:
            ui->label_Incidencia_ROrganizacional->setText("          Mediana Incidencia");
            break;
        case 6:
            ui->label_Incidencia_ROrganizacional->setText("         Incidencia Sensible");
            break;
        case 7:
            ui->label_Incidencia_ROrganizacional->setText("         Bastante Incidencia");
            break;
        case 8:
            ui->label_Incidencia_ROrganizacional->setText("           Fuerte Incidencia");
            break;
        case 9:
            ui->label_Incidencia_ROrganizacional->setText("       Muy fuerte Incidencia");
            break;
        case 10:
            ui->label_Incidencia_ROrganizacional->setText("         La mayor Incidencia");
            break;
    }
}

void MainWindow::on_horizontalSlider_Incidencia_RHerramientas_valueChanged(int value)
{
    switch(value){
        case 0:
            ui->label_Incidencia_RHerramientas->setText("          Ninguna Incidencia");
            break;
        case 1:
            ui->label_Incidencia_RHerramientas->setText("Practicamente sin Incidencia");
            break;
        case 2:
            ui->label_Incidencia_RHerramientas->setText("         Casi sin Incidencia");
            break;
        case 3:
            ui->label_Incidencia_RHerramientas->setText("        Muy débil Incidencia");
            break;
        case 4:
            ui->label_Incidencia_RHerramientas->setText("            Débil Incidencia");
            break;
        case 5:
            ui->label_Incidencia_RHerramientas->setText("          Mediana Incidencia");
            break;
        case 6:
            ui->label_Incidencia_RHerramientas->setText("         Incidencia Sensible");
            break;
        case 7:
            ui->label_Incidencia_RHerramientas->setText("         Bastante Incidencia");
            break;
        case 8:
            ui->label_Incidencia_RHerramientas->setText("           Fuerte Incidencia");
            break;
        case 9:
            ui->label_Incidencia_RHerramientas->setText("       Muy fuerte Incidencia");
            break;
        case 10:
            ui->label_Incidencia_RHerramientas->setText("         La mayor Incidencia");
            break;
    }
}

void MainWindow::on_horizontalSlider_Incidencia_RRequerimientos_valueChanged(int value)
{
    switch(value){
        case 0:
            ui->label_Incidencia_RRequerimientos->setText("          Ninguna Incidencia");
            break;
        case 1:
            ui->label_Incidencia_RRequerimientos->setText("Practicamente sin Incidencia");
            break;
        case 2:
            ui->label_Incidencia_RRequerimientos->setText("         Casi sin Incidencia");
            break;
        case 3:
            ui->label_Incidencia_RRequerimientos->setText("        Muy débil Incidencia");
            break;
        case 4:
            ui->label_Incidencia_RRequerimientos->setText("            Débil Incidencia");
            break;
        case 5:
            ui->label_Incidencia_RRequerimientos->setText("          Mediana Incidencia");
            break;
        case 6:
            ui->label_Incidencia_RRequerimientos->setText("         Incidencia Sensible");
            break;
        case 7:
            ui->label_Incidencia_RRequerimientos->setText("         Bastante Incidencia");
            break;
        case 8:
            ui->label_Incidencia_RRequerimientos->setText("           Fuerte Incidencia");
            break;
        case 9:
            ui->label_Incidencia_RRequerimientos->setText("       Muy fuerte Incidencia");
            break;
        case 10:
            ui->label_Incidencia_RRequerimientos->setText("         La mayor Incidencia");
            break;
    }
}

void MainWindow::on_horizontalSlider_Incidencia_REstimacion_valueChanged(int value)
{
    switch(value){
        case 0:
            ui->label_Incidencia_REstimacion->setText("          Ninguna Incidencia");
            break;
        case 1:
            ui->label_Incidencia_REstimacion->setText("Practicamente sin Incidencia");
            break;
        case 2:
            ui->label_Incidencia_REstimacion->setText("         Casi sin Incidencia");
            break;
        case 3:
            ui->label_Incidencia_REstimacion->setText("        Muy débil Incidencia");
            break;
        case 4:
            ui->label_Incidencia_REstimacion->setText("            Débil Incidencia");
            break;
        case 5:
            ui->label_Incidencia_REstimacion->setText("          Mediana Incidencia");
            break;
        case 6:
            ui->label_Incidencia_REstimacion->setText("         Incidencia Sensible");
            break;
        case 7:
            ui->label_Incidencia_REstimacion->setText("         Bastante Incidencia");
            break;
        case 8:
            ui->label_Incidencia_REstimacion->setText("           Fuerte Incidencia");
            break;
        case 9:
            ui->label_Incidencia_REstimacion->setText("       Muy fuerte Incidencia");
            break;
        case 10:
            ui->label_Incidencia_REstimacion->setText("         La mayor Incidencia");
            break;
    }
}

void MainWindow::on_pushButton_ArbolDeRiesgos_clicked()
{
    float consulta;
    string NombreFactorFila;
    string NombreFactorColumna;
    string relacionFactor;

    for(int fila = 0; fila < 15 ; fila++){
        for(int columna = 0; columna < 15 ; columna++){
            consulta = EfectoOlvidado.getValor(fila,columna);
            if(consulta > 0.8){
                switch(fila){
                    case 0:
                        NombreFactorFila = "Modelo Solución";
                        break;
                    case 1:
                        NombreFactorFila = "Requerimientos";
                        break;
                    case 2:
                        NombreFactorFila = "Diseño";
                        break;
                    case 3:
                        NombreFactorFila = "Plan de Pruebas";
                        break;
                    case 4:
                        NombreFactorFila = "Plan General";
                        break;
                    case 5:
                        NombreFactorFila = "Temporización";
                        break;
                    case 6:
                        NombreFactorFila = "Ciclo de Vida";
                        break;
                    case 7:
                        NombreFactorFila = "Gestión de Riesgos";
                        break;
                    case 8:
                        NombreFactorFila = "Desarrollo";
                        break;
                    case 9:
                        NombreFactorFila = "Riesgos de Tecnología";
                        break;
                    case 10:
                        NombreFactorFila = "Riesgos de Personal";
                        break;
                    case 11:
                        NombreFactorFila = "Riesgo Organizacional";
                        break;
                    case 12:
                        NombreFactorFila = "Riesgos de Herramientas";
                        break;
                    case 13:
                        NombreFactorFila = "Riesgos de Requerimientos";
                        break;
                    case 14:
                        NombreFactorFila = "Riesgo de Estimación";
                        break;
                }


                switch(columna){
                    case 0:
                        NombreFactorColumna = "Modelo Solución";
                        break;
                    case 1:
                        NombreFactorColumna = "Requerimientos";
                        break;
                    case 2:
                        NombreFactorColumna = "Diseño";
                        break;
                    case 3:
                        NombreFactorColumna = "Plan de Pruebas";
                        break;
                    case 4:
                        NombreFactorColumna = "Plan General";
                        break;
                    case 5:
                        NombreFactorColumna = "Temporización";
                        break;
                    case 6:
                        NombreFactorColumna = "Ciclo de Vida";
                        break;
                    case 7:
                        NombreFactorColumna = "Gestión de Riesgos";
                        break;
                    case 8:
                        NombreFactorColumna = "Desarrollo";
                        break;
                    case 9:
                        NombreFactorColumna = "Riesgos de Tecnología";
                        break;
                    case 10:
                        NombreFactorColumna = "Riesgos de Personal";
                        break;
                    case 11:
                        NombreFactorColumna = "Riesgo Organizacional";
                        break;
                    case 12:
                        NombreFactorColumna = "Riesgos de Herramientas";
                        break;
                    case 13:
                        NombreFactorColumna = "Riesgos de Requerimientos";
                        break;
                    case 14:
                        NombreFactorColumna = "Riesgo de Estimación";
                        break;
                }
                std::ostringstream buff;
                buff<<consulta;
                relacionFactor += NombreFactorFila+" --("+buff.str()+")--> "+NombreFactorColumna;
                relacionFactor += " = "+Gestor.buscarIntermediario(MatrizIncidencia,fila,columna);
                relacionFactor += "\n\n";
            }
        }
    }

    QString mensaje = QString::fromStdString(relacionFactor);
    QMessageBox::information(this, "Causas del Riesgo", mensaje);

}
