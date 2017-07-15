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
}

/*--------------------------------PROCESO DE CALCULO DE BOTON CONFIRMACION--------------------------------------*/
void MainWindow::on_pushButton_CalcularRiesgo_clicked()
{

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

void MainWindow::on_pushButton_ConfirmarIncidencias_clicked()
{
    ui->tabWidget->setTabEnabled(0,false);
    ui->tabWidget->setTabEnabled(1,true);
    ui->tabWidget->setTabEnabled(2,true);
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

            InferenciaFuzzy CalculoModeloSolucion(var1,var2,var3);
            CalculoModeloSolucion.InferenciaMamdani();

            double resultado;
            resultado = CalculoModeloSolucion.GetResultadoFinal();

            QString ResultadoModeloSolucion;
            ResultadoModeloSolucion.setNum(resultado);
            ui->Nivel_Riesgo->setText(ResultadoModeloSolucion+"%");
            ui->pushButton_CicloVida->setEnabled(false);
            ui->pushButton_CicloVida->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
        }
    }

    if(ui->pushButton_Desarrollo->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy CalculoModeloSolucion(var1,var2,var3);
            CalculoModeloSolucion.InferenciaMamdani();

            double resultado;
            resultado = CalculoModeloSolucion.GetResultadoFinal();

            QString ResultadoModeloSolucion;
            ResultadoModeloSolucion.setNum(resultado);
            ui->Nivel_Riesgo->setText(ResultadoModeloSolucion+"%");
            ui->pushButton_Desarrollo->setEnabled(false);
            ui->pushButton_Desarrollo->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
        }
    }

    if(ui->pushButton_Disenio->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy CalculoModeloSolucion(var1,var2,var3);
            CalculoModeloSolucion.InferenciaMamdani();

            double resultado;
            resultado = CalculoModeloSolucion.GetResultadoFinal();

            QString ResultadoModeloSolucion;
            ResultadoModeloSolucion.setNum(resultado);
            ui->Nivel_Riesgo->setText(ResultadoModeloSolucion+"%");
            ui->pushButton_Disenio->setEnabled(false);
            ui->pushButton_Disenio->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
        }
    }

    if(ui->pushButton_ModeloSolucion->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy CalculoModeloSolucion(var1,var2,var3);
            CalculoModeloSolucion.InferenciaMamdani();

            double resultado;
            resultado = CalculoModeloSolucion.GetResultadoFinal();

            QString ResultadoModeloSolucion;
            ResultadoModeloSolucion.setNum(resultado);
            ui->Nivel_Riesgo->setText(ResultadoModeloSolucion+"%");
            ui->pushButton_ModeloSolucion->setEnabled(false);
            ui->pushButton_ModeloSolucion->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
        }
    }

    if(ui->pushButton_PlanGeneral->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy CalculoModeloSolucion(var1,var2,var3);
            CalculoModeloSolucion.InferenciaMamdani();

            double resultado;
            resultado = CalculoModeloSolucion.GetResultadoFinal();

            QString ResultadoModeloSolucion;
            ResultadoModeloSolucion.setNum(resultado);
            ui->Nivel_Riesgo->setText(ResultadoModeloSolucion+"%");
            ui->pushButton_PlanGeneral->setEnabled(false);
            ui->pushButton_PlanGeneral->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
        }
    }

    if(ui->pushButton_Pruebas->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy CalculoModeloSolucion(var1,var2,var3);
            CalculoModeloSolucion.InferenciaMamdani();

            double resultado;
            resultado = CalculoModeloSolucion.GetResultadoFinal();

            QString ResultadoModeloSolucion;
            ResultadoModeloSolucion.setNum(resultado);
            ui->Nivel_Riesgo->setText(ResultadoModeloSolucion+"%");
            ui->pushButton_Pruebas->setEnabled(false);
            ui->pushButton_Pruebas->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
        }
    }

    if(ui->pushButton_Requerimientos->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy CalculoRequerimientos(var1,var2,var3);
            CalculoRequerimientos.InferenciaMamdani();

            double resultado;
            resultado = CalculoRequerimientos.GetResultadoFinal();

            QString ResultadoModeloSolucion;
            ResultadoModeloSolucion.setNum(resultado);
            ui->Nivel_Riesgo->setText(ResultadoModeloSolucion+"%");
            ui->pushButton_Requerimientos->setEnabled(false);
            ui->pushButton_Requerimientos->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
        }
    }

    if(ui->pushButton_REstimacion->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy CalculoRequerimientos(var1,var2,var3);
            CalculoRequerimientos.InferenciaMamdani();

            double resultado;
            resultado = CalculoRequerimientos.GetResultadoFinal();

            QString ResultadoModeloSolucion;
            ResultadoModeloSolucion.setNum(resultado);
            ui->Nivel_Riesgo->setText(ResultadoModeloSolucion+"%");
            ui->pushButton_REstimacion->setEnabled(false);
            ui->pushButton_REstimacion->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
        }
    }

    if(ui->pushButton_RHerramientas->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy CalculoRequerimientos(var1,var2,var3);
            CalculoRequerimientos.InferenciaMamdani();

            double resultado;
            resultado = CalculoRequerimientos.GetResultadoFinal();

            QString ResultadoModeloSolucion;
            ResultadoModeloSolucion.setNum(resultado);
            ui->Nivel_Riesgo->setText(ResultadoModeloSolucion+"%");
            ui->pushButton_RHerramientas->setEnabled(false);
            ui->pushButton_RHerramientas->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
        }
    }

    if(ui->pushButton_Riesgos->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy CalculoRequerimientos(var1,var2,var3);
            CalculoRequerimientos.InferenciaMamdani();

            double resultado;
            resultado = CalculoRequerimientos.GetResultadoFinal();

            QString ResultadoModeloSolucion;
            ResultadoModeloSolucion.setNum(resultado);
            ui->Nivel_Riesgo->setText(ResultadoModeloSolucion+"%");
            ui->pushButton_Riesgos->setEnabled(false);
            ui->pushButton_Riesgos->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
        }
    }

    if(ui->pushButton_ROrganizacional->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy CalculoRequerimientos(var1,var2,var3);
            CalculoRequerimientos.InferenciaMamdani();

            double resultado;
            resultado = CalculoRequerimientos.GetResultadoFinal();

            QString ResultadoModeloSolucion;
            ResultadoModeloSolucion.setNum(resultado);
            ui->Nivel_Riesgo->setText(ResultadoModeloSolucion+"%");
            ui->pushButton_ROrganizacional->setEnabled(false);
            ui->pushButton_ROrganizacional->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
        }
    }

    if(ui->pushButton_RPersonal->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy CalculoRequerimientos(var1,var2,var3);
            CalculoRequerimientos.InferenciaMamdani();

            double resultado;
            resultado = CalculoRequerimientos.GetResultadoFinal();

            QString ResultadoModeloSolucion;
            ResultadoModeloSolucion.setNum(resultado);
            ui->Nivel_Riesgo->setText(ResultadoModeloSolucion+"%");
            ui->pushButton_RPersonal->setEnabled(false);
            ui->pushButton_RPersonal->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
        }
    }

    if(ui->pushButton_RRequerimiento->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy CalculoRequerimientos(var1,var2,var3);
            CalculoRequerimientos.InferenciaMamdani();

            double resultado;
            resultado = CalculoRequerimientos.GetResultadoFinal();

            QString ResultadoModeloSolucion;
            ResultadoModeloSolucion.setNum(resultado);
            ui->Nivel_Riesgo->setText(ResultadoModeloSolucion+"%");
            ui->pushButton_RRequerimiento->setEnabled(false);
            ui->pushButton_RRequerimiento->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
        }
    }

    if(ui->pushButton_RTecnologia->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy CalculoRequerimientos(var1,var2,var3);
            CalculoRequerimientos.InferenciaMamdani();

            double resultado;
            resultado = CalculoRequerimientos.GetResultadoFinal();

            QString ResultadoModeloSolucion;
            ResultadoModeloSolucion.setNum(resultado);
            ui->Nivel_Riesgo->setText(ResultadoModeloSolucion+"%");
            ui->pushButton_RTecnologia->setEnabled(false);
            ui->pushButton_RTecnologia->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
        }
    }

    if(ui->pushButton_Temporizacion->isEnabled()){
        QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                         QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMessageBox::Yes){

            var1 = ui->horizontalSlider_Respuesta_1->value();
            var2 = ui->horizontalSlider_Respuesta_2->value();
            var3 = ui->horizontalSlider_Respuesta_3->value();

            InferenciaFuzzy CalculoModeloSolucion(var1,var2,var3);
            CalculoModeloSolucion.InferenciaMamdani();

            double resultado;
            resultado = CalculoModeloSolucion.GetResultadoFinal();

            QString ResultadoModeloSolucion;
            ResultadoModeloSolucion.setNum(resultado);
            ui->Nivel_Riesgo->setText(ResultadoModeloSolucion+"%");
            ui->pushButton_Temporizacion->setEnabled(false);
            ui->pushButton_Temporizacion->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
            ui->pushButton_CalcularRiesgo->setEnabled(true);
        }
    }
}
