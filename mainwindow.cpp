#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont f("MS Shell Dig 2", 14, QFont::Bold);
    ui->label->setFont(f);
    QFont s("MS Shell Dig 2", 10, QFont::Bold);
    ui->label_Factor_Seleccionado->setFont(s);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ModeloSolucion_clicked()
{
    ui->label->setText("El porcentaje de riesgo estimado es: Modelo Solucion");
    ui->label_Factor_Seleccionado->setText("Factor Seleccionado: Modelo Solución");
}

void MainWindow::on_pushButton_Requerimientos_clicked()
{
    ui->label->setText("El porcentaje de riesgo estimado es: Requerimientos");
    ui->label_Factor_Seleccionado->setText("Factor Seleccionado: Requerimientos");
}

void MainWindow::on_pushButton_Disenio_clicked()
{
    ui->label->setText("El porcentaje de riesgo estimado es: Diseño");
    ui->label_Factor_Seleccionado->setText("Factor Seleccionado: Diseño");
}


void MainWindow::on_pushButton_Pruebas_clicked()
{
    ui->label->setText("El porcentaje de riesgo estimado es: Plan de Pruebas");
    ui->label_Factor_Seleccionado->setText("Factor Seleccionado: Plan de Pruebas");
}


void MainWindow::on_pushButton_PlanGeneral_clicked()
{
    ui->label->setText("El porcentaje de riesgo estimado es: Plan General");
    ui->label_Factor_Seleccionado->setText("Factor Seleccionado: Plan General");
}


void MainWindow::on_pushButton_Temporizacion_clicked()
{
    ui->label->setText("El porcentaje de riesgo estimado es: Temporizacion");
    ui->label_Factor_Seleccionado->setText("Factor Seleccionado: Temporización");
}


void MainWindow::on_pushButton_CicloVida_clicked()
{
    ui->label->setText("El porcentaje de riesgo estimado es: Det. del Ciclo de Vida");
    ui->label_Factor_Seleccionado->setText("Factor Seleccionado: Det. del Ciclo de Vida");
}


void MainWindow::on_pushButton_Riesgos_clicked()
{
    ui->label->setText("El porcentaje de riesgo estimado es: G. de Riesgos");
    ui->label_Factor_Seleccionado->setText("Factor Seleccionado: G. de Riesgos");
}


void MainWindow::on_pushButton_Estimacion_clicked()
{
    ui->label->setText("El porcentaje de riesgo estimado es: Estimacion");
}
