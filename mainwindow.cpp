#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inferenciafuzzy.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont f("MS Shell Dig 2", 14, QFont::Bold);
    ui->label->setFont(f);
    var1 = 0;
    var2 = 0;
    var3 = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ModeloSolucion_clicked()
{
    QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                     QMessageBox::Yes | QMessageBox::No);

    if(confirmacion == QMessageBox::Yes){

        valorModeloSolucion1 = ui->horizontalSlider_Respuesta_1->value();
        valorModeloSolucion2 = ui->horizontalSlider_Respuesta_2->value();
        valorModeloSolucion3 = ui->horizontalSlider_Respuesta_3->value();

        InferenciaFuzzy CalculoModeloSolucion(valorModeloSolucion1,valorModeloSolucion2,valorModeloSolucion3);
        CalculoModeloSolucion.InferenciaMamdani();

        double resultado;
        resultado = CalculoModeloSolucion.GetResultadoFinal();

        QString ResultadoModeloSolucion;
        ResultadoModeloSolucion.setNum(resultado);
        ui->Nivel_Riesgo->setText(ResultadoModeloSolucion+"%");
        ui->pushButton_ModeloSolucion->setStyleSheet("background-color:yellow;border-style: outset;border-width: 6px;border-color: gray;");
        ui->pushButton_ModeloSolucion->setEnabled(false);
    }

//    var1 = valorModeloSolucion1;
//    var2 = valorModeloSolucion2;
//    var3 = valorModeloSolucion3;
}

void MainWindow::on_pushButton_Requerimientos_clicked()
{
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
    QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                     QMessageBox::Yes | QMessageBox::No);

    if(confirmacion == QMessageBox::Yes){

        valorDisenio1 = ui->horizontalSlider_Respuesta_1->value();
        valorDisenio2 = ui->horizontalSlider_Respuesta_2->value();
        valorDisenio3 = ui->horizontalSlider_Respuesta_3->value();

        InferenciaFuzzy CalculoModeloSolucion(valorDisenio1,valorDisenio2,valorDisenio3);
        CalculoModeloSolucion.InferenciaMamdani();

        double resultado;
        resultado = CalculoModeloSolucion.GetResultadoFinal();

        QString ResultadoModeloSolucion;
        ResultadoModeloSolucion.setNum(resultado);
        ui->Nivel_Riesgo->setText(ResultadoModeloSolucion+"%");
        ui->pushButton_Disenio->setEnabled(false);
    }
}


void MainWindow::on_pushButton_Pruebas_clicked()
{
    QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                     QMessageBox::Yes | QMessageBox::No);

    if(confirmacion == QMessageBox::Yes){

        valorPruebas1 = ui->horizontalSlider_Respuesta_1->value();
        valorPruebas2 = ui->horizontalSlider_Respuesta_2->value();
        valorPruebas3 = ui->horizontalSlider_Respuesta_3->value();

        InferenciaFuzzy CalculoModeloSolucion(valorPruebas1,valorPruebas2,valorPruebas3);
        CalculoModeloSolucion.InferenciaMamdani();

        double resultado;
        resultado = CalculoModeloSolucion.GetResultadoFinal();

        QString ResultadoModeloSolucion;
        ResultadoModeloSolucion.setNum(resultado);
        ui->Nivel_Riesgo->setText(ResultadoModeloSolucion+"%");
        ui->pushButton_Pruebas->setEnabled(false);
    }
}


void MainWindow::on_pushButton_PlanGeneral_clicked()
{
    QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                     QMessageBox::Yes | QMessageBox::No);

    if(confirmacion == QMessageBox::Yes){

        valorPlanGeneral1 = ui->horizontalSlider_Respuesta_1->value();
        valorPlanGeneral2 = ui->horizontalSlider_Respuesta_2->value();
        valorPlanGeneral3 = ui->horizontalSlider_Respuesta_3->value();

        InferenciaFuzzy CalculoModeloSolucion(valorPlanGeneral1,valorPlanGeneral2,valorPlanGeneral3);
        CalculoModeloSolucion.InferenciaMamdani();

        double resultado;
        resultado = CalculoModeloSolucion.GetResultadoFinal();

        QString ResultadoModeloSolucion;
        ResultadoModeloSolucion.setNum(resultado);
        ui->Nivel_Riesgo->setText(ResultadoModeloSolucion+"%");
        ui->pushButton_PlanGeneral->setEnabled(false);
    }
}


void MainWindow::on_pushButton_Temporizacion_clicked()
{
    QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                     QMessageBox::Yes | QMessageBox::No);

    if(confirmacion == QMessageBox::Yes){

        valorTemporizacion1 = ui->horizontalSlider_Respuesta_1->value();
        valorTemporizacion2 = ui->horizontalSlider_Respuesta_2->value();
        valorTemporizacion3 = ui->horizontalSlider_Respuesta_3->value();

        InferenciaFuzzy CalculoModeloSolucion(valorTemporizacion1,valorTemporizacion2,valorTemporizacion3);
        CalculoModeloSolucion.InferenciaMamdani();

        double resultado;
        resultado = CalculoModeloSolucion.GetResultadoFinal();

        QString ResultadoModeloSolucion;
        ResultadoModeloSolucion.setNum(resultado);
        ui->Nivel_Riesgo->setText(ResultadoModeloSolucion+"%");
        ui->pushButton_Temporizacion->setEnabled(false);
    }
}


void MainWindow::on_pushButton_CicloVida_clicked()
{
    QMessageBox::StandardButton confirmacion = QMessageBox::question(this, "Confirmacion de Datos", "¿Confirmar Estimacion?",
                                                                     QMessageBox::Yes | QMessageBox::No);

    if(confirmacion == QMessageBox::Yes){

        valorCicloVida1 = ui->horizontalSlider_Respuesta_1->value();
        valorCicloVida2 = ui->horizontalSlider_Respuesta_2->value();
        valorCicloVida3 = ui->horizontalSlider_Respuesta_3->value();

        InferenciaFuzzy CalculoModeloSolucion(valorCicloVida1,valorCicloVida2,valorCicloVida3);
        CalculoModeloSolucion.InferenciaMamdani();

        double resultado;
        resultado = CalculoModeloSolucion.GetResultadoFinal();

        QString ResultadoModeloSolucion;
        ResultadoModeloSolucion.setNum(resultado);
        ui->Nivel_Riesgo->setText(ResultadoModeloSolucion+"%");
        ui->pushButton_CicloVida->setEnabled(false);
    }
}


void MainWindow::on_pushButton_Riesgos_clicked()
{
    ui->label->setText("NIVEL DE RIESGO:  G. de Riesgos");
}


void MainWindow::on_pushButton_Estimacion_clicked()
{
    ui->label->setText("NIVEL DE RIESGO:  Estimacion");
}

void MainWindow::on_pushButton_Confirmar_clicked()
{
    // Se cambia de color verde el boton que fue ejecutado
    if(ui->pushButton_CicloVida->isEnabled()){
        ui->pushButton_CicloVida->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
    }

    if(ui->pushButton_Desarrollo->isEnabled()){
        ui->pushButton_Desarrollo->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
    }

    if(ui->pushButton_Disenio->isEnabled()){
        ui->pushButton_Disenio->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
    }

    if(ui->pushButton_ModeloSolucion->isEnabled()){
        ui->pushButton_ModeloSolucion->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
    }

    if(ui->pushButton_PlanGeneral->isEnabled()){
        ui->pushButton_PlanGeneral->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
    }

    if(ui->pushButton_Pruebas->isEnabled()){
        ui->pushButton_Pruebas->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
    }

    if(ui->pushButton_Requerimientos->isEnabled()){
        ui->pushButton_Requerimientos->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
    }

    if(ui->pushButton_REstimacion->isEnabled()){
        ui->pushButton_REstimacion->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
    }

    if(ui->pushButton_RHerramientas->isEnabled()){
        ui->pushButton_RHerramientas->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
    }

    if(ui->pushButton_Riesgos->isEnabled()){
        ui->pushButton_Riesgos->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
    }

    if(ui->pushButton_ROrganizacional->isEnabled()){
        ui->pushButton_ROrganizacional->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
    }

    if(ui->pushButton_RPersonal->isEnabled()){
        ui->pushButton_RPersonal->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
    }

    if(ui->pushButton_RRequerimiento->isEnabled()){
        ui->pushButton_RRequerimiento->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
    }

    if(ui->pushButton_RTecnologia->isEnabled()){
        ui->pushButton_RTecnologia->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
    }

    if(ui->pushButton_Temporizacion->isEnabled()){
        ui->pushButton_Temporizacion->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
    }

    if(ui->pushButton_Desarrollo->isEnabled()){
        ui->pushButton_Desarrollo->setStyleSheet("background-color:lightgreen;border-style: outset;border-width: 6px;border-color: gray;");
    }


    // Se desbloquea todos los botones
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
}
