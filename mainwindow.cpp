#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inferenciafuzzy.h"
#include <QMessageBox>

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

    QFont f("MS Shell Dig 2", 14, QFont::Bold);
    ui->label->setFont(f);

    int i;
    for(i=0;i<15;i++){
        ResultadosFactores[i] = 0;
    }

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
            if(ResultadosFactores[i] > 100){
                ResultadosFactores[i] = 100;
            }
            ResultadoFinal = ResultadosFactores[i] + ResultadoFinal;
            cant++;
        }
    }

    ResultadoFinal = ResultadoFinal/cant;
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
    float valor[15];

    valor[0] = ui->horizontalSlider_Incidencia_ModeloSolucion->value();
    valor[1] = ui->horizontalSlider_Incidencia_Requerimientos->value();
    valor[2] = ui->horizontalSlider_Incidencia_Disenio->value();
    valor[3] = ui->horizontalSlider_Incidencia_Pruebas->value();
    valor[4] = ui->horizontalSlider_Incidencia_PlanGeneral->value();
    valor[5] = ui->horizontalSlider_Incidencia_Temporizacion->value();

    ui->tabWidget->setTabEnabled(0,false);
    ui->tabWidget->setTabEnabled(1,true);
    ui->tabWidget->setTabEnabled(2,true);
    ui->pushButton_ConfirmarEstimacion->setEnabled(true);
}

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

            InferenciaFuzzy Calculo(var1,var2,var3);
            Calculo.InferenciaMamdani();

            ResultadosFactores[0] = Calculo.GetResultadoFinal();

            ui->pushButton_CicloVida->setEnabled(false);
            ui->pushButton_CicloVida->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
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

            InferenciaFuzzy Calculo(var1,var2,var3);
            Calculo.InferenciaMamdani();

            ResultadosFactores[1] = Calculo.GetResultadoFinal();

            ui->pushButton_Desarrollo->setEnabled(false);
            ui->pushButton_Desarrollo->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
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

            InferenciaFuzzy Calculo(var1,var2,var3);
            Calculo.InferenciaMamdani();

            ResultadosFactores[2] = Calculo.GetResultadoFinal();

            ui->pushButton_Disenio->setEnabled(false);
            ui->pushButton_Disenio->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
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

            InferenciaFuzzy Calculo(var1,var2,var3);
            Calculo.InferenciaMamdani();

            ResultadosFactores[3] = Calculo.GetResultadoFinal();

            ui->pushButton_ModeloSolucion->setEnabled(false);
            ui->pushButton_ModeloSolucion->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
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

            InferenciaFuzzy Calculo(var1,var2,var3);
            Calculo.InferenciaMamdani();

            ResultadosFactores[4] = Calculo.GetResultadoFinal();

            ui->pushButton_PlanGeneral->setEnabled(false);
            ui->pushButton_PlanGeneral->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
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

            InferenciaFuzzy Calculo(var1,var2,var3);
            Calculo.InferenciaMamdani();

            ResultadosFactores[5] = Calculo.GetResultadoFinal();

            ui->pushButton_Pruebas->setEnabled(false);
            ui->pushButton_Pruebas->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
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

            InferenciaFuzzy Calculo(var1,var2,var3);
            Calculo.InferenciaMamdani();

            ResultadosFactores[6] = Calculo.GetResultadoFinal();

            ui->pushButton_Requerimientos->setEnabled(false);
            ui->pushButton_Requerimientos->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
            ui->pushButton_ConfirmarEstimacion->setEnabled(false);
        }
    }

    if(ui->pushButton_REstimacion->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy Calculo(var1,var2,var3);
            Calculo.InferenciaMamdani();

            ResultadosFactores[7] = Calculo.GetResultadoFinal();

            ui->pushButton_REstimacion->setEnabled(false);
            ui->pushButton_REstimacion->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
            ui->pushButton_ConfirmarEstimacion->setEnabled(false);
        }
    }

    if(ui->pushButton_RHerramientas->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy Calculo(var1,var2,var3);
            Calculo.InferenciaMamdani();

            ResultadosFactores[8] = Calculo.GetResultadoFinal();

            ui->pushButton_RHerramientas->setEnabled(false);
            ui->pushButton_RHerramientas->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
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

            InferenciaFuzzy Calculo(var1,var2,var3);
            Calculo.InferenciaMamdani();

            ResultadosFactores[9] = Calculo.GetResultadoFinal();

            ui->pushButton_Riesgos->setEnabled(false);
            ui->pushButton_Riesgos->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
            ui->pushButton_ConfirmarEstimacion->setEnabled(false);
        }
    }

    if(ui->pushButton_ROrganizacional->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy Calculo(var1,var2,var3);
            Calculo.InferenciaMamdani();

            ResultadosFactores[10] = Calculo.GetResultadoFinal();

            ui->pushButton_ROrganizacional->setEnabled(false);
            ui->pushButton_ROrganizacional->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
            ui->pushButton_ConfirmarEstimacion->setEnabled(false);
        }
    }

    if(ui->pushButton_RPersonal->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy Calculo(var1,var2,var3);
            Calculo.InferenciaMamdani();

            ResultadosFactores[11] = Calculo.GetResultadoFinal();

            ui->pushButton_RPersonal->setEnabled(false);
            ui->pushButton_RPersonal->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
            ui->pushButton_ConfirmarEstimacion->setEnabled(false);
        }
    }

    if(ui->pushButton_RRequerimiento->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy Calculo(var1,var2,var3);
            Calculo.InferenciaMamdani();

            ResultadosFactores[12] = Calculo.GetResultadoFinal();

            ui->pushButton_RRequerimiento->setEnabled(false);
            ui->pushButton_RRequerimiento->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
            ui->pushButton_ConfirmarEstimacion->setEnabled(false);
        }
    }

    if(ui->pushButton_RTecnologia->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy Calculo(var1,var2,var3);
            Calculo.InferenciaMamdani();

            ResultadosFactores[13] = Calculo.GetResultadoFinal();

            ui->pushButton_RTecnologia->setEnabled(false);
            ui->pushButton_RTecnologia->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
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

            InferenciaFuzzy Calculo(var1,var2,var3);
            Calculo.InferenciaMamdani();

            ResultadosFactores[14] = Calculo.GetResultadoFinal();

            ui->pushButton_Temporizacion->setEnabled(false);
            ui->pushButton_Temporizacion->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
            ui->pushButton_ConfirmarEstimacion->setEnabled(false);
        }
    }
}
