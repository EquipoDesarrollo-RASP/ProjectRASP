#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ModeloSolucion_clicked()
{
    ui->label->setText("Modelo Solucion");
}

void MainWindow::on_pushButton_Requerimientos_clicked()
{
    ui->label->setText("Requerimientos");
}

void MainWindow::on_pushButton_Disenio_clicked()
{
    ui->label->setText("Diseño");
}

void MainWindow::on_pushButton_Pruebas_clicked()
{
    ui->label->setText("Plan de Pruebas");
}

void MainWindow::on_pushButton_PlanGeneral_clicked()
{
    ui->label->setText("Plan General");
}

void MainWindow::on_pushButton_Temporizacion_clicked()
{
    ui->label->setText("Temporizacion");
}

void MainWindow::on_pushButton_CicloVida_clicked()
{
    ui->label->setText("Determinacion del Ciclo de Vida");
}

void MainWindow::on_pushButton_Riesgos_clicked()
{
    ui->label->setText("Gestion de Riesgos");
}
